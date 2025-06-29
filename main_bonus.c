#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm_bonus.h"

void test_list_size() {
	printf("=== Testing ft_list_size ===\n");
	
	// Create a test list
	t_list *first = malloc(sizeof(t_list));
	t_list *second = malloc(sizeof(t_list));
	t_list *third = malloc(sizeof(t_list));
	
	first->data = "First element";
	first->next = second;
	second->data = "Second element";
	second->next = third;
	third->data = "Third element";
	third->next = NULL;
	
	int result = ft_list_size(first);
	printf("List size: %d\n", result);
	
	// Test with NULL
	int result_null = ft_list_size(NULL);
	printf("NULL list size: %d\n", result_null);
	
	// Clean up
	free(first);
	free(second);
	free(third);
	printf("\n");
}

void test_list_push_front() {
	printf("=== Testing ft_list_push_front ===\n");
	
	// Create initial list
	t_list *list = malloc(sizeof(t_list));
	list->data = "Original element";
	list->next = NULL;
	
	printf("Before push_front:\n");
	printf("List size: %d\n", ft_list_size(list));
	printf("First element: %s\n", (char*)list->data);
	
	// Push new element to front
	ft_list_push_front(&list, "New first element");
	
	printf("After push_front:\n");
	printf("List size: %d\n", ft_list_size(list));
	printf("First element: %s\n", (char*)list->data);
	printf("Second element: %s\n", (char*)list->next->data);
	
	// Test with NULL list
	t_list *null_list = NULL;
	ft_list_push_front(&null_list, "First element in NULL list");
	printf("NULL list after push_front size: %d\n", ft_list_size(null_list));
	printf("NULL list after push_front first element: %s\n", (char*)null_list->data);
	
	// Clean up
	free(list->next);
	free(list);
	free(null_list);
	printf("\n");
}

int main() {
	printf("=== Libasm Bonus Functions Test ===\n\n");
	
	test_list_size();
	test_list_push_front();
	
	printf("=== All bonus tests completed ===\n");
	return 0;
} 