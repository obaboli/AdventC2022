#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_READ_SIZE 20

/** new and improvec max macro
** https://stackoverflow.com/questions/3437404/min-and-max-in-c
**/
#define MAX(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})

int main() {
   uint32_t sum = 0;
   uint32_t maxSum = 0;
   char buf[MAX_READ_SIZE] = "";
   FILE *fptr = NULL;

   if ((fptr = fopen("input.txt","r")) == NULL){
       printf("Error Opening File");
       exit(1);
   }

   while (fgets (buf, MAX_READ_SIZE, fptr)) { 
      if(buf[0] == '\n') {
         maxSum = MAX(maxSum, sum);
         sum = 0;
      }
      else {
         /* Should check for errors */
         sum += strtol(buf, NULL, 10);
      }
   }  

   printf("%u", maxSum);
   
   fclose(fptr); 

   return 0;
}