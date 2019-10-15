#include <stddef.h>
#include <stdio.h>
#include "structs.h"
#include "search.h"



struct node *searchNode (int value, struct skipList *skplt, int fl) {
	struct node *current = skplt->head;
	while (current->lower != NULL) {
		if (value == current->key) {
			if (fl == 1) 
				printf("value:%d was founded\n", current->key);
			return current;
		}	
		if (value < current->next->key) 
			current = current->lower;
		else 
			current = current->next;
	}
	while (current->next != NULL) {
		if (current->key == value) {
			return current;
		}
		else current = current->next;
	}
	if (fl == 1)
		printf ("value:%d wasn't founded\n", value);
	return NULL;
}

