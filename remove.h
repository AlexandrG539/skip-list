int removeFromSkipList (int value, struct skipList *skplt);
struct node *removeNode (struct node *toRemove, struct node *prev);
struct node *findPrev(int number, struct node *nd, struct skipList *skplt);
int removeEmptyLists (struct skipList *skplt);