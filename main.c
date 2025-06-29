#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "libasm.h"

void test_strlen() {
	printf("=== Testing ft_strlen ===\n");
	
	const char *test1 = "Hello, World!";
	const char *test2 = "";
	const char *test3 = "Test string with spaces";
	
	printf("---Case 1: Normal string---\n");
	printf("ft_strlen(\"%s\") = %zu\n", test1, ft_strlen(test1));
	printf("strlen(\"%s\") = %zu\n", test1, strlen(test1));
	
	printf("---Case 2: Empty string---\n");
	printf("ft_strlen(\"%s\") = %zu\n", test2, ft_strlen(test2));
	printf("strlen(\"%s\") = %zu\n", test2, strlen(test2));
	
	printf("---Case 3: String with spaces---\n");
	printf("ft_strlen(\"%s\") = %zu\n", test3, ft_strlen(test3));
	printf("strlen(\"%s\") = %zu\n", test3, strlen(test3));

	printf("\n");
}

void test_strcpy() {
	printf("=== Testing ft_strcpy ===\n");
	
	printf("---Case 1: Normal string---\n");
	char dest[50];
	const char *src = "Hello, World!";

	char *result = ft_strcpy(dest, src);
	printf("Original string: %s\n", src);
	printf("Copied string: %s\n", dest);
	printf("Return value: %s\n", result);
	
	if (strcmp(dest, src) == 0) {
		printf("✓ Test passed\n");
	} else {
		printf("✗ Test failed\n");
	}

	printf("---Case 2: Empty string---\n");
	char dest2[50];
	const char *src2 = "";

	char *result2 = ft_strcpy(dest2, src2);
	printf("Original string: %s\n", src2);
	printf("Copied string: %s\n", dest2);
	printf("Return value: %s\n", result2);

	if (strcmp(dest2, src2) == 0) {
		printf("✓ Test passed\n");
	} else {
		printf("✗ Test failed\n");
	}

	printf("\n");
}

void test_strcmp() {
	printf("=== Testing ft_strcmp ===\n");
	
	const char *str1 = "Hello";
	const char *str2 = "Hello";
	const char *str3 = "Helloa";
	const char *str4 = "Hell";
	const char *str5 = NULL;

	printf("---Case 1: Normal string---\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str2, ft_strcmp(str1, str2));
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str2, strcmp(str1, str2));
	
	printf("---Case 2: 2 Empty strings---\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", "", "", ft_strcmp("", ""));
	printf("strcmp(\"%s\", \"%s\") = %d\n", "", "", strcmp("", ""));

	printf("---Case 3: First Param is Empty string---\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", "", str1, ft_strcmp("", str1));
	printf("strcmp(\"%s\", \"%s\") = %d\n", "", str1, strcmp("", str1));

	printf("---Case 4: Second Param is Empty string---\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, "", ft_strcmp(str1, ""));
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, "", strcmp(str1, ""));
	
	printf("---Case 5: String with spaces---\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str3, ft_strcmp(str1, str3));
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str3, strcmp(str1, str3));
	
	printf("---Case 6: String with spaces---\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str4, ft_strcmp(str1, str4));
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str4, strcmp(str1, str4));

	printf("---Case 7: NULL---\n");
	(void)ft_strcmp(str5, str5);
	(void)strcmp(str5, str5);
	
	printf("\n");
}

void test_write() {
	printf("=== Testing ft_write ===\n");
	
	printf("---Case 1: Normal string---\n");
	ssize_t result1 = ft_write(1, "Hello from ft_write!\n", 21);
	printf("ft_write result: %zd\n", result1);
	
	printf("---Case 2: Empty string---\n");
	ssize_t result2 = write(1, "Hello from write!\n", 18);
	printf("write result: %zd\n", result2);
	
	// Test error case
	printf("---Case 3: Invalid fd---\n");
	ssize_t result3 = ft_write(-1, "This should fail\n", 17);
	printf("ft_write with invalid fd result: %zd, errno: %d\n", result3, errno);
	ssize_t result4 = write(-1, "This should fail\n", 17);
	printf("write with invalid fd result: %zd, errno: %d\n", result4, errno);
	
	printf("---Case 4: NULL---\n");
	ssize_t result5 = ft_write(1, NULL, 0);
	printf("ft_write with NULL result: %zd, errno: %d\n", result5, errno);
	ssize_t result6 = write(1, NULL, 0);
	printf("write with NULL result: %zd, errno: %d\n", result6, errno);

	printf("\n");
}

void test_read() {
	printf("=== Testing ft_read ===\n");
	
	// Create a test file
	int fd = open("test_read.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1) {
		write(fd, "Test content for reading", 23);
		close(fd);
	}
	
	printf("---Case 1: Valid Fd and buffer---\n");
	// Read from the file
	fd = open("test_read.txt", O_RDONLY);
	if (fd != -1) {
		char buf[50] = {0};
		ssize_t result = ft_read(fd, buf, 49);
		printf("ft_read result: %zd\n", result);
		printf("Read content: \"%s\"\n", buf);
		close(fd);
	}
	
	printf("---Case 2: Invalid Fd and buffer---\n");
	// Test error case
	char error_buf[10];
	ssize_t result2 = ft_read(-1, error_buf, 10);
	printf("ft_read with invalid fd result: %zd, errno: %d\n", result2, errno);
	ssize_t result3 = read(-1, error_buf, 10);
	printf("read with invalid fd result: %zd, errno: %d\n", result3, errno);

	printf("---Case 3: NULL---\n");
	ssize_t result4 = ft_read(fd, NULL, 10);
	printf("ft_read with NULL result: %zd, errno: %d\n", result4, errno);
	ssize_t result5 = read(fd, NULL, 10);
	printf("read with NULL result: %zd, errno: %d\n", result5, errno);
	printf("\n");
}

void test_strdup() {
	printf("=== Testing ft_strdup ===\n");
	
	printf("---Case 1: Normal string---\n");
	const char *test_str = "Hello, World!";
	char *dup1 = ft_strdup(test_str);
	char *dup2 = strdup(test_str);
	
	printf("Original: \"%s\"\n", test_str);
	printf("ft_strdup: \"%s\"\n", dup1);
	printf("strdup: \"%s\"\n", dup2);
	
	if (strcmp(dup1, test_str) == 0) {
		printf("✓ ft_strdup test passed\n");
	} else {
		printf("✗ ft_strdup test failed\n");
	}
	
	printf("---Case 2: Empty string---\n");
	const char *test_str2 = "";
	char *dup3 = ft_strdup(test_str2);
	char *dup4 = strdup(test_str2);
	
	printf("Original: \"%s\"\n", test_str2);
	printf("ft_strdup: \"%s\"\n", dup3);
	printf("strdup: \"%s\"\n", dup4);
	
	if (strcmp(dup3, test_str2) == 0) {
		printf("✓ ft_strdup test passed\n");
	} else {
		printf("✗ ft_strdup test failed\n");
	}

	free(dup1);
	free(dup2);
	free(dup3);
	free(dup4);
	printf("\n");
}

int main() {
	printf("=== Libasm Mandatory Functions Test ===\n\n");
	
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	
	printf("=== All mandatory tests completed ===\n");
	return 0;
}
