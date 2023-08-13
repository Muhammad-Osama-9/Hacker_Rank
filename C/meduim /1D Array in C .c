
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int size , result=0 ;
     scanf("%d",&size);
    int arr [size] ;
    for (int i =0 ; i<size ;i++)
    {
        scanf("%d",&arr[i]);
        result = result +  arr[i] ; 
     }
     printf("%d",result);
    return 0;
}
