#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "structs.h"
#include "create.h"
#include "insert.h"
#include "printSkipList.h"
#include "search.h"
#include "remove.h"

int console(struct skipList *skplt);

int main () {
	struct skipList *skplt = createSkipList();
	for(;;) {
		console(skplt);
	}	
	return 0;
}

int console(struct skipList *skplt) {
	int value;
	char name[256];
	scanf("%s", name);
	if(!strcmp("insert", name)){
		if (scanf("%d", &value) == 1)
			insertInSkipList(value, skplt);
		else 
			printf ("wrong format of value");
	}
	else if(!strcmp("remove", name)){
		if (scanf("%d", &value) == 1)
			removeFromSkipList(value, skplt);
		else 
			printf ("wrong format of value");
	}
	else if(!strcmp("search", name)){
		if (scanf("%d", &value) == 1)
			searchNode(value, skplt, 1);
		else 
			printf ("wrong format of value");
	}
	else if(!strcmp("print", name))
		printSkipList(stdout, skplt);
	else if(!strcmp("exit", name)) 
		exit(0);
	else
		printf("Unknown [%s]\n", name);
	return 0;
}
