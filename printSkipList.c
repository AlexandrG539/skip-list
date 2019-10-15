#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "printSkipList.h"


int printSkipList(struct skipList *skplt) {
	struct node *nd = skplt->head;
	if (skplt->head->next->key == INT_MAX)
		return 1;
	while (nd->lower != NULL) {
		printList(nd, skplt->head);
		nd = nd->lower;
	}
	printList(nd, skplt->head);
}

int printList(struct node *nd, struct node *head) {
	struct node *prevNode = nd;
	struct node *prevLower;
	struct node *current = nd->next;
	struct node *currentLower;
	while (1) {
		prevLower = prevNode;
		while (prevLower->lower != NULL)
			prevLower = prevLower->lower;
		currentLower = current;
		while (currentLower->lower != NULL)
			currentLower = currentLower->lower;
		printSpaces(prevLower, currentLower);
		printf("%d", current->key);
		if (current->next->key == INT_MAX)
			break;
		prevNode = prevNode->next;
		current = current->next;
	}
	printf("\n");
	return 0;
}

int printSpaces (struct node *prevNode, struct node *currentLower) {
	struct node *current = prevNode;
	while (current != currentLower) {
		current = current->next;
		printf(" ");
		if (current != currentLower) {
			if (current->key < 0)
				printf(" ");
			int dc = digitCount(abs(current->key));
			while (dc != 0) {
				printf(" ");
				dc--;
			}
		}
	}
	return 0;
}

int digitCount (int digit) {
	int i = 0;
	int d = digit;
	int fl = 0;
	do {
		d = (d / 10);
		if (d == 0)
			fl = 1;
		i++;
	} while (fl == 0);
	return i;
}