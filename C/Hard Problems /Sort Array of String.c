
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
return (strcmp(a,b) >= 0 );
}

int lexicographic_sort_reverse(const char* a, const char* b) {
return  (strcmp(a,b) <= 0 );
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int ret_flag = 0 ;
    int len_a = strlen(a) ;
    int len_b = strlen(b) ;
    int freq[26] ;
    memset(freq , 0, 26 * sizeof(int)  );

    int a_distinct = 0  , b_distinct = 0 ;

    for (int i = 0 ; i < len_a ; i ++ )
    {
        freq[(int)(a[i]-'a')] ++ ;
    }
    for (int i = 0 ; i < 128 ; i ++ )
    {
        if (freq[i]>0)
        {
            a_distinct++;
        }
    }

    memset(freq , 0, 26 * sizeof(int)  );
     for (int i = 0 ; i < len_b ; i ++ )
    {
        freq[(int)(b[i]-'a')] ++ ;
    }
     for (int i = 0 ; i < 128 ; i ++ )
    {
        if (freq[i]>0)
        {
            b_distinct++;
        }
    }



    if (a_distinct > b_distinct)
    {
        ret_flag = 1;
    }
    else if (a_distinct == b_distinct){
        ret_flag = lexicographic_sort(a , b) ;
    }

    return ret_flag ;
}

int sort_by_length(const char* a, const char* b) {
    int flag = 0 ;
    if (strlen(a) > strlen(b))
    {
        flag = 1 ;
    }
    else if(strlen(a) == strlen(b))
    {
        flag  = lexicographic_sort(a, b) ;
    }


return  flag  ;

}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    char *temp ;
    for (int  i = 0 ; i < len ; i++ )
    {
        for (int j = 1;  j < len-i ; j ++  )
            {

               if ( cmp_func(*(arr+j-1),*(arr+j)) )
               {
                   temp = *(arr+j-1) ;
                   *(arr+j-1) = *(arr+j) ;
                   *(arr+j) = temp ;

               }else {
                   /*Do Nothing*/
               }

            }


    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
