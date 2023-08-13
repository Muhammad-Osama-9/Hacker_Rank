#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   int arr [10] = {0} ;
   char * ptr ='\0';
  ptr = (char*)malloc(1000*sizeof(char)) ;

  scanf("%s",ptr);

  ptr = realloc(ptr,(strlen(ptr)+1));

  for(int j=0;j<10; j++)
   {
         for (int i = 0 ;i<strlen(ptr) ; i++)
      {
            if (ptr[i]==j+48)
                  arr[j]++;
      }

   }

    for(int k = 0 ; k <10 ; k++)
    {
       printf("%d ",arr[k]);
    }
    return 0;
}

