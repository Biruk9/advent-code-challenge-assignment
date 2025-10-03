#include <stdio.h>
#include <stdbool.h>
// function to check if a sequence is safe

bool is_safe(int arr[],int n){
if (n<1) return true; // 1 element is safe

//first check the tread (increasing or decreasing)

int diff= arr[1]-arr[0];
if(diff == 0) return false; // equal elements are not allowed
bool increasing = (diff>0);

//check the differences
for(int i=1; i<n; i++){
    int d= arr[i]-arr[i-1];

    if(d==0) return false; // equal elements are not allowed
    if(increasing && d<0) return false; // if increasing, a decrease is not allowed
    if(!increasing && d>0) return false; // if decreasing, an increase is not allowed
    if(d>3 || d<-3) return false; // difference greater than 3 is not allowed

}
return true; // if all checks passed, the sequence is safe
}

bool is_safe_with_dampener(int arr[], int n){
if (is_safe(arr, n)) return true; // if already safe, return true

// try removing one element at a time and check if it becomes safe

for(int i =0;i<n;i++){
int temp[100]; // copy array without arr[i]
int k=0;
for(int j=0;j<n;j++){
if(j!=i) temp[k++] = arr[j];
}
if(is_safe(temp, k)) return true; // if removing arr[i] makes it safe, return true
}
return false; // if no single removal makes it safe, return false
}

int main(){
FILE *f= fopen("input1.txt", "r"); //open input file
if(!f){
    printf("could not open file!\n");
    return 1;

}
int safe_count=0;// count of safe sequences
int arr[100]; //store numbers from one line
int n;

// read each line of numbers unlit end of file
 while(1){
    n=0;

    while (fscanf(f, "%d", &arr[n])==1){
        n++;
        if(fgetc(f)=='\n') break; // stop at end of line
    }
    if(n==0) break; // if no numbers read, end of file reached
 
// check if this report is safe with dampner
if(is_safe_with_dampener(arr,n)) safe_count++;
 }
 fclose(f);
// print result
printf("safe reports: %d\n", safe_count);
return 0;

}

