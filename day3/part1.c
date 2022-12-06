#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_READ_SIZE 500
#define MAX_CHARS 52

int main() {
	FILE *fptr = NULL;
	char buf[MAX_READ_SIZE] = "";
	uint32_t totalScore = 0;

	char split1[MAX_READ_SIZE] = "";
	char split2[MAX_READ_SIZE] = "";

	uint8_t freq1[MAX_CHARS] = {0};
	uint8_t freq2[MAX_CHARS] = {0};

	if ((fptr = fopen("input.txt","r")) == NULL){
		printf("Error Opening File");
		exit(1);
	}

	while(fgets (buf, MAX_READ_SIZE, fptr)) {
		uint32_t stringSize = strnlen(buf, MAX_READ_SIZE) / 2;

		strncpy(split1, buf, stringSize);
		strncpy(split2, buf + stringSize, stringSize);

		for(uint8_t i = 0; i < stringSize; i++) {
			if(split1[i] >= 'a' && split1[i] <= 'z') {
				uint8_t indexLowerCase = split1[i] - 'a';
				freq1[indexLowerCase]++;
			}
			else if(split1[i] >= 'A' && split1[i] <= 'Z') {
				uint8_t indexUpperCase = split1[i] - 'A';
				indexUpperCase += 26;
				freq1[indexUpperCase]++;
			}
		}

		for(uint8_t i = 0; i < stringSize; i++) {
			if(split2[i] >= 'a' && split2[i] <= 'z') {
				uint8_t indexLowerCase = split2[i] - 'a';
				freq2[indexLowerCase]++;
			}
			else if(split2[i] >= 'A' && split2[i] <= 'Z') {
				uint8_t indexUpperCase = split2[i] - 'A';
				indexUpperCase += 26;
				freq2[indexUpperCase]++;
			}
		}


		for(uint8_t i = 0; i < MAX_CHARS; i++) {
			if(freq1[i] > 0 && freq2[i] > 0){
				totalScore += (i + 1);
				break;
			}
		}

		memset(split1, 0, stringSize);
		memset(split2, 0, stringSize);
		memset(freq1, 0, MAX_CHARS);
		memset(freq2, 0, MAX_CHARS);
	}

	printf("%u", totalScore);
	return 0;
}