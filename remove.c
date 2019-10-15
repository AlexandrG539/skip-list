#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "search.h"
#include "create.h"
#include "remove.h"

int removeFromSkipList (int value, struct skipList *skplt) {
	struct node *toRemove = searchNode (value, skplt, 0);
	if (toRemove == NULL) {
		printf("value %d is not in skipList\n", value);
		return 1;
	}
	int steps = 1;
	struct node *toRemoveLow = toRemove;
	while (toRemoveLow->lower != NULL) {
		toRemoveLow = toRemoveLow->lower;
		steps++;
	}
	while (steps != 0) {
		int curLvl = skplt->level - (skplt->level - steps);
		toRemove = removeNode(toRemove, findPrev(curLvl, toRemove, skplt));
		steps--;
	}
	removeEmptyLists(skplt);
	return 0;
}

struct node *removeNode (struct node *toRemove, struct node *prev) {
	prev->next = toRemove->next;
	struct node *nextToRemove;
	if (toRemove->lower != NULL)
		nextToRemove = toRemove->lower;
	free(toRemove);
	return nextToRemove;
}

struct node *findPrev(int number, struct node *nd, struct skipList *skplt) {
	int steps = (skplt->level - number);
	struct node *current = skplt->head;
	while (steps != 0) {
		if (nd->key <= current->next->key) { 
			if (steps != 0) {
				current = current->lower;
				steps--;
			}
		}
		else
			current = current->next;
	}
	while (current->next != nd)
			current = current->next;
	return current;
}

int removeEmptyLists (struct skipList *skplt) {
	struct node *low;
	struct node *nodeToRemove = skplt->head;
	while (nodeToRemove->next->key == INT_MAX) {
		low = skplt->head->lower;
		free(nodeToRemove->next);
		free(nodeToRemove);
		skplt->head = low;
		skplt->level--;
		nodeToRemove = skplt->head;
	}
	return 0;
}