#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>	
#include "structs.h"
#include "create.h"
#include "search.h"
#include "insert.h"



int insertInSkipList (int value, struct skipList *skplt) {
	struct node *current = skplt->head;
	while (current->lower != NULL) {
		if (value <= current->next->key) 
			current = current->lower;
		else 
			current = current->next;
	}
	int lvl = insertInLowLevel(value, current);
	if (lvl == 0)
		return 0;
	int newLvls = (lvl - (skplt->level) + 1);
	if (newLvls > 0) { 
		while (newLvls != 0) {
			skplt->head = createNode (INT_MIN, skplt->head, createNode(INT_MAX, NULL, NULL));
			newLvls--;
			skplt->level++;
		}
	}
	fillKeys(value, skplt, lvl);
	return 0;
}

struct node *goToLevel(int number, int value, struct skipList *skplt) {
	int steps = (skplt->level - number);
	struct node *current = skplt->head;
	while (steps != 0) {
		if (value <= current->next->key) { 
			if (steps != 0) {
				current = current->lower;
				steps--;
			}
		}
		else
			current = current->next;
	}
	while (value >= current->next->key)
			current = current->next;
	return current;
}

int fillKeys(int value, struct skipList *skplt, int lvls) {
	int currentNumber = 2;
	struct node *first; 
	struct node *second;
	first = goToLevel(1, value, skplt);
	while (lvls != 0) {
		second = goToLevel(currentNumber, value, skplt);
		second->next = createNode(value, first, second->next);
		lvls--;
		first = second->next;
		currentNumber++;
	}
	return 0;
}

int insertInLowLevel (int value, struct node *nd) {
	struct node *current = nd;
	while (value >= current->next->key) 
		current = current->next;
	current->next = createNode(value, NULL, current->next);
	int lvl = coin();
	return lvl;
}

int coin(){
	int i = 0;
	for(;;) {
		if (rand() < (RAND_MAX / 2))
			i++;
		else break;
	}	
	return i;
}