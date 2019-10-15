#include <stdlib.h>
#include <stddef.h>
#include "structs.h"
#include "create.h"


struct skipList *createSkipList() {
	struct skipList *skplt = (struct skipList*)malloc(sizeof(struct skipList));
	if (skplt == 0)
		return 0;
	skplt->level = 1;
	skplt->head = createNode(INT_MIN, NULL, createNode(INT_MAX, NULL, NULL));
	return skplt;
}

struct node *createNode(int k, struct node *lw, struct node *nt) {
	struct node *nd = (struct node*)malloc(sizeof(struct node));
	if (nd == 0)
		return 0;
	nd->key = k;
	nd->next = nt;
	nd->lower = lw;
	return nd;
}