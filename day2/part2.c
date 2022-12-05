#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_READ_SIZE 20

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

static char returnWinner(char opp) {
	if(opp == 'A') {
		return 'B';
	}
	else if(opp == 'B') {
		return 'C';
	}
	else if(opp == 'C') {
		return 'A';
	}
}

static char returnLoser(char opp) {
	if(opp == 'A') {
		return 'C';
	}
	else if(opp == 'B') {
		return 'A';
	}
	else if(opp == 'C') {
		return 'B';
	}
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
		uint32_t shapeResult = 0;

		if(me == 'X') {
			/* Lost */
			char loser = returnLoser(opp);
			shapeResult = checkShape(loser);
			totalScore += (shapeResult + 0);
		}
		else if(me == 'Y') {
			/* Draw */
			shapeResult = checkShape(opp);
			totalScore += (shapeResult + 3);
		}
		else if(me == 'Z') {
			/* Win */
			char winner = returnWinner(opp);
			shapeResult = checkShape(winner);
			totalScore += (shapeResult + 6);
		}
	}

	printf("%u", totalScore);
	return 0;
}