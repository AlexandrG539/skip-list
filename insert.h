int insertInLowLevel (int value, struct node *nd);
int insertInSkipList (int value, struct skipList *skplt);
int coin();
struct node *goToLevel(int number, int value, struct skipList *skplt);
int fillKeys(int value, struct skipList *skplt, int lvls);