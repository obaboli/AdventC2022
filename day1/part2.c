#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_READ_SIZE 20

int main() {
   uint32_t sum = 0;
   uint32_t maxSum1 = 0;
   uint32_t maxSum2 = 0;
   uint32_t maxSum3 = 0;
   char buf[MAX_READ_SIZE] = "";
   FILE *fptr = NULL;

   if ((fptr = fopen("input.txt","r")) == NULL){
       printf("Error Opening File");
       exit(1);
   }

   while (fgets (buf, MAX_READ_SIZE, fptr)) { 
      if(buf[0] == '\n') {
         if(sum > maxSum1) {
            maxSum2 = maxSum1;
            maxSum3 = maxSum2;
            maxSum1 = sum;
         }
         else if(sum > maxSum2) {
            maxSum3 = maxSum2;
            maxSum2 = sum;
         }
         else if(sum > maxSum3) {
            maxSum3 = sum;
         }
         sum = 0;
      }
      else {
         /* Should check for errors */
         sum += strtol(buf, NULL, 10);
      }
   }  
   
   printf("%u", maxSum1 + maxSum2 + maxSum3);
   fclose(fptr); 

   return 0;
}