#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries) {
    int *result = malloc(queries_count * sizeof(int));
    for(int i =0; i<queries_count; i++){
       int count = 0;
       for (int j=0;j<strings_count; j++){
           if(strcmp(queries[i],strings[j])==0){
              count++;
           }
       }
       result[i]=count;
    }
    return result ;
}
int main(){
    int n;
    scanf("%d",&n);
    char **strings=malloc(n* sizeof(char *));
    for(int i=0; i<n; i++){
        strings[i]=malloc(21 *sizeof(char));
        scanf("%s",strings[i]);
    }
    int q;
    scanf("%d",&q);
    char **queries=malloc(q*sizeof(char *));
    for(int i=0; i<q; i++){
        queries[i]=malloc(21 *sizeof(char));
        scanf("%s",queries[i]);
    }
    int *res =matchingStrings(n ,strings,q,queries);
    for(int i=0;i<q;i++){
        printf("%d\n",res[i]);
    }
    for(int i=0; i<n; i++)free(strings[i]);
    for(int i=0; i<q; i++)free(queries[i]);
    free(strings);
    free(queries);
    free(res);
    return 0;
    
}