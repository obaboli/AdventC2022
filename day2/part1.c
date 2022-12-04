#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_READ_SIZE 20

static char alignShape(char me) {
	if(me == 'X') {
		return 'A';
	}
	if(me == 'Y') {
		return 'B';
	}
	if(me == 'Z') {
		return 'C';
	}
}

static uint32_t checkShape(char me) {
	if(me == 'A') {
		return 1;
	}
	if(me == 'B') {
		return 2;
	}
	if(me == 'C') {
		return 3;
	}
}

static uint32_t checkResult(char opp, char me) {
	if(opp == me) {
		return 3;
	}
	
	if(opp == 'A' && me == 'B') {
		return 6;
	}
	else if(opp == 'B' && me == 'C') {
		return 6;
	}
	else if(opp == 'C' && me == 'A') {
		return 6;
	}

	return 0;
}

int main() {
	FILE *fptr = NULL;
	char buf[MAX_READ_SIZE] = "";
	uint32_t totalScore = 0;

	if ((fptr = fopen("input.txt","r")) == NULL){
		printf("Error Opening File");
		exit(1);
	}

	while(fgets (buf, MAX_READ_SIZE, fptr)) {
		char opp = buf[0];
		char me = buf[2];
		me = alignShape(me);
		uint32_t resultScore = checkResult(opp, me);
		uint32_t shapeScore = checkShape(me);

		totalScore += (resultScore + shapeScore);
	}

	printf("%u", totalScore);
	return 0;
}