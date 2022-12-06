#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_READ_SIZE 500
#define MAX_CHARS 52
#define GROUP_SIZE 3

int main() {
	FILE *fptr = NULL;
	char buf[MAX_READ_SIZE] = "";
	uint32_t totalScore = 0;
	uint8_t lineNumber = 0;

	char line1[MAX_READ_SIZE] = "";
	char line2[MAX_READ_SIZE] = "";
	char line3[MAX_READ_SIZE] = "";

	uint8_t freq1[MAX_CHARS] = {0};
	uint8_t freq2[MAX_CHARS] = {0};
	uint8_t freq3[MAX_CHARS] = {0};

	if ((fptr = fopen("input.txt","r")) == NULL){
		printf("Error Opening File");
		exit(1);
	}

	while(fgets (buf, MAX_READ_SIZE, fptr)) {
		uint32_t stringSize = strnlen(buf, MAX_READ_SIZE);

		if(lineNumber == 0) {
			strncpy(line1, buf, stringSize);
			lineNumber++;

			for(uint8_t i = 0; i < stringSize; i++) {
				if(line1[i] >= 'a' && line1[i] <= 'z') {
					uint8_t indexLowerCase = line1[i] - 'a';
					freq1[indexLowerCase]++;
				}
				else if(line1[i] >= 'A' && line1[i] <= 'Z') {
					uint8_t indexUpperCase = line1[i] - 'A';
					indexUpperCase += 26;
					freq1[indexUpperCase]++;
				}
			}
		}
		else if(lineNumber == 1) {
			strncpy(line2, buf, stringSize);
			lineNumber++;

			for(uint8_t i = 0; i < stringSize; i++) {
				if(line2[i] >= 'a' && line2[i] <= 'z') {
					uint8_t indexLowerCase = line2[i] - 'a';
					freq2[indexLowerCase]++;
				}
				else if(line2[i] >= 'A' && line2[i] <= 'Z') {
					uint8_t indexUpperCase = line2[i] - 'A';
					indexUpperCase += 26;
					freq2[indexUpperCase]++;
				}
			}
		}
		else if(lineNumber == 2) {
			strncpy(line3, buf, stringSize);

			for(uint8_t i = 0; i < stringSize; i++) {
				if(line3[i] >= 'a' && line3[i] <= 'z') {
					uint8_t indexLowerCase = line3[i] - 'a';
					freq3[indexLowerCase]++;
				}
				else if(line3[i] >= 'A' && line3[i] <= 'Z') {
					uint8_t indexUpperCase = line3[i] - 'A';
					indexUpperCase += 26;
					freq3[indexUpperCase]++;
				}
			}

			for(uint8_t i = 0; i < MAX_CHARS; i++) {
				if(freq1[i] > 0 && freq2[i] > 0 && freq3[i] > 0){
					totalScore += (i + 1);
					break;
				}
			}

			lineNumber = 0;
			memset(line1, 0, stringSize);
			memset(line2, 0, stringSize);
			memset(line3, 0, stringSize);
			memset(freq1, 0, MAX_CHARS);
			memset(freq2, 0, MAX_CHARS);
			memset(freq3, 0, MAX_CHARS);
		}
	}

	printf("%u", totalScore);

	return 0;
}