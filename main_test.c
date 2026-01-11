/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:20:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/11 10:39:51 by tghnassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libunit.h"

int dummy_test_OK(void)
{
	return (0);
}

int dummy_test_KO(void)
{
	return (-1);
}

int dummy_test_SEGV(void)
{
	char *a;
	*a = 5;
	return 1;
}

#include <stdio.h>
#include <stdlib.h>
int dummy_test_BUSERR(void)
{
    // Create a buffer of bytes. A char is always 1 byte and is byte-aligned.
    char *buffer = malloc(16); // Allocate 16 bytes.
    if (!buffer) {
        // perror("malloc");
        return 1;
    }

    // Attempt to point an integer pointer to an address that is NOT
    // a multiple of sizeof(int) (usually 4 bytes).
    // Here, we point to the second byte of the buffer.
    int *misaligned_ptr = (int *)(buffer + 1);

    // printf("Attempting to write to a misaligned address 0x%p...\n", (void*)misaligned_ptr);
    
    // On systems with strict alignment requirements, this line
    // is likely to cause a SIGBUS. On x86/x86-64, it will likely succeed.
    *misaligned_ptr = 0xDEADBEEF; // Writing a test value.

    // printf("Write successful (no SIGBUS occurred on this system, value: 0x%x).\n", *misaligned_ptr);

    free(buffer); // Clean up allocated memory.
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // For memset
#include <sys/mman.h>   // For mmap, munmap
#include <sys/stat.h>   // For fstat, mode constants
#include <fcntl.h>      // For open, O_RDWR, etc.
#include <unistd.h>     // For ftruncate, close, getpagesize
int dummy_test_BUSERR2(void)
{
    const char *filename = "sigbus_test_file.txt";
    int page_size = getpagesize(); // Get system's memory page size.
    char buffer_data[page_size];   // Buffer to write to file.

    // Initialize buffer with some data
    memset(buffer_data, 'A', page_size);
    buffer_data[0] = 'X'; // Mark first byte
    buffer_data[page_size - 1] = 'Z'; // Mark last byte

    // 1. Create and populate a file with at least one page of data.
    int fd = open(filename, O_CREAT | O_RDWR, 0644);
    if (fd == -1) { perror("open file for writing"); return 1; }
    if (ftruncate(fd, page_size) == -1) { perror("ftruncate initial size"); close(fd); return 1; }
    if (write(fd, buffer_data, page_size) == -1) { perror("write to file"); close(fd); return 1; }
    close(fd); // Close and re-open to ensure proper state for mmap.

    // 2. Re-open the file and map it into memory.
    fd = open(filename, O_RDWR);
    if (fd == -1) { perror("open file for mmap"); return 1; }
    
    char *map_ptr = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map_ptr == MAP_FAILED) { perror("mmap"); close(fd); return 1; }

    // printf("File '%s' mapped into memory at address %p.\n", filename, (void*)map_ptr);
    // printf("Initial content: map_ptr[0] = '%c', map_ptr[%d] = '%c'\n", 
        //    map_ptr[0], page_size - 1, map_ptr[page_size - 1]);
    
    // Give a moment to confirm mapping.
    sleep(1);

    // 3. Truncate the file on disk, making the mapped region invalid past a certain point.
    // We'll truncate it to 0 bytes, making the entire mapped region invalid.
    // printf("\nTruncating file '%s' to 0 bytes...\n", filename);
    if (ftruncate(fd, 0) == -1) { perror("ftruncate to 0"); munmap(map_ptr, page_size); close(fd); return 1; }
    
    // 4. Attempt to access the memory that no longer has a file backing it.
    // printf("Attempting to access memory from the now-truncated file section (map_ptr[0])...\n");
    
    // This access will cause the OS to try to load the page from a non-existent
    // part of the file, resulting in SIGBUS.
    // The exact byte that causes the SIGBUS can vary depending on OS/architecture,
    // but map_ptr[0] is guaranteed to be in the invalid part.
    char invalid_access_char = map_ptr[0]; // Trying to read
    // Or try to write: map_ptr[0] = 'Y';
    
    // This line will typically not be reached, as the program will
    // terminate due to SIGBUS before it.
    // printf("This message will not be printed (SIGBUS should occur).\n"); 
    
    munmap(map_ptr, page_size);
    close(fd);
    unlink(filename); // Clean up the test file.
    return 0;
}

int main()
{
	t_list	*list;

	list = NULL;

	load_test(&list, "OK dummy function", &dummy_test_OK);
	load_test(&list, "KO dummy function", &dummy_test_KO);
	load_test(&list, "segfault that!", &dummy_test_SEGV);
	load_test(&list, "attempt to BUS ERROR!", &dummy_test_BUSERR);
	load_test(&list, "KO dummy function", &dummy_test_KO);
	load_test(&list, "attempt 2 to BUS ERROR!", &dummy_test_BUSERR2);
	load_test(&list, "OK dummy function", &dummy_test_OK);

	ft_printf("list len: %d\n", ft_lst_size(list));

	launch_tests("THEO TESTS", list);
}
