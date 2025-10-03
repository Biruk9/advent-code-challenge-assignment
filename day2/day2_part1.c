#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){
    FILE *f= fopen("input1.txt", "r"); //open input file
    if(!f){
        printf("could not open file!\n");

    }
char line[256];
int safe_count=0;
int line_num =1; // keep track of line numbers for debugging
while(fgets(line, sizeof(line), f)){//

    int arr[50],n=0;
    //split line into numbers

    char *token=strtok(line, " \n");
    while(token!=NULL){
        arr[n++]=atoi(token);
        token=strtok(NULL, " \n");
    }
//assume safe unitil proven otherwise
    bool safe=true;
   int diff =arr[1]-arr[0];

   if(diff == 0 || abs(diff) > 3) safe = false;
   bool increasing=(diff>0);

   for (int i=1; i< n&& safe;i++){
    int d= arr[i] - arr[i-1];
    if( d==0|| abs(d)>3) safe=false;
    if( increasing && d<0) {safe=false; break;}
    if(!increasing && d>0) safe=false;
   }
   if(safe){
printf("line %d: safe\n", line_num);
safe_count++;
   }
else   {
printf( "line %d: unsafe\n", line_num);
   }
   line_num++;

}

fclose(f);
printf("total safe units: %d\n", safe_count);
return 0;



}