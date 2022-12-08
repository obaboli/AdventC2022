
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_READ_SIZE 500

int main() {
	FILE *fptr = NULL;
	char buf[MAX_READ_SIZE] = "";
	char delimit[] = "-,";
	uint32_t totalScore = 0;

	if ((fptr = fopen("input.txt","r")) == NULL){
		printf("Error Opening File");
		exit(1);
	}

	while(fgets (buf, MAX_READ_SIZE, fptr)) {
		/**
		 * Really gross gnarly string function to break apart string
		 * TODO: Revisit to look for safer way to handle this
		 */
		int32_t elfOneLower = strtol(strtok(buf,delimit), NULL, 10);
		int32_t elfOneUpper = strtol(strtok(NULL,delimit), NULL, 10);
		int32_t elfTwoLower = strtol(strtok(NULL,delimit), NULL, 10);
		int32_t elfTwoUpper = strtol(strtok(NULL,delimit), NULL, 10);

		int32_t diff = 0;
		
		if(elfOneLower < elfTwoLower) {
			diff = elfOneUpper - elfTwoLower;
		}
		else {
			diff = elfTwoUpper - elfOneLower;
		}

		if(diff >= 0) {
			totalScore++;
		}
		
	}

	printf("%u", totalScore);
	return 0;
}