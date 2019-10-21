#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "search.h"
#include "create.h"
#include "insert.h"
#include "printSkipList.h"
#include "remove.h"


int main (int argc, char **argv) {
	char *nameInput;
	char *nameOutput;
	if (argc <= 1) {
         printf("syntax : \n\t-i name of imput file\n\t-o name of output file\n", argv[0]);
         return 1; 
     }
	if (argc != 5) {
		printf("Parameters entered incorrectly");
		return 1;
	}
	if ((!strcmp(argv[1], "-i") && !strcmp (argv[3], "-o")) 
		|| (!strcmp(argv[3], "-i") && !strcmp (argv[1], "-o"))) {
		if (!strcmp(argv[1], "-i")) {
			nameInput = argv[2];
			nameOutput = argv[4];
		}
		else if (!strcmp(argv[1], "-o")) {
			nameInput = argv[4];
			nameOutput = argv[2];
		}
	} 
	else {
		printf ("Wrong pare of flags:'%s', '%s', required '-i' and '-o'\n", argv[1], argv[3]);
		return 1;
	}
	FILE *input = fopen(nameInput, "rt");
	FILE *output = fopen (nameOutput, "wb");
	if (input == NULL || output == NULL) {
		fprintf(output, "TEST FAILED\n");
		return 1;
	}
		
	struct skipList *skplt = createSkipList();
	while (1) {
		int num = 0;
		int ret = fscanf(input, " %d", &num);
		if (ret != 1) {
			printf("out\n");
			break;
		}
		else {
			printf("+\n");
			insertInSkipList(num, skplt);
			if (searchNode (num, skplt, 0) == NULL) {
				fprintf(output, "TEST FAILED\n");
				return 1;
			}	
		}
	}
	printSkipList(output, skplt);
	fclose(output);
	fclose(input);
}