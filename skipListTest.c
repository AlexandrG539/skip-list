#include <stddef.h>
#include <stdio.h>
#include "search.h"
#include "structs.h"
#include "create.h"
#include "insert.h"
#include "printSkipList.h"
#include "remove.h"


int main() {
	struct skipList *skplt = createSkipList();
	struct node *current = skplt->head;
	insertInSkipList (-1, skplt);
	insertInSkipList (2, skplt);
	insertInSkipList (5, skplt);
	insertInSkipList (7, skplt);
	insertInSkipList (12, skplt);
	insertInSkipList (15, skplt);
	insertInSkipList (20, skplt);
	insertInSkipList (1, skplt);
	insertInSkipList (1, skplt);
	insertInSkipList (1, skplt);
	if (searchNode(15, skplt, 0) == NULL) {
		printf("Test failed\n");
		return 1;
	}
	if (searchNode(23, skplt, 0) != NULL) {
		printf("Test failed\n");
		return 1;
	}
	removeFromSkipList(15, skplt);
	if (searchNode(15, skplt, 0) != NULL) {
		printf("Test failed\n");
		return 1;
	}
	printf("Test passed\n");
	return 0;
}