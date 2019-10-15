struct node {
	int key;
	struct node *next;
	struct node *lower;
};

struct skipList {
	struct node *head;
	int level;
};