#include <stdio.h>
#include <stdlib.h>
/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(int arr_count, int* arr) {
    int positive =0, negative =0, zero =0;
    
    for (int i = 0; i < arr_count; i++) {
        if(arr[i]>0)
           positive++;
        else if (arr[i]<0)
           negative++;
        else 
           zero++;
    }


    double pos_ratio =(double)positive/ arr_count;
    double neg_ratio =(double)negative/ arr_count;
    double zero_ratio =(double)zero/ arr_count;

    printf("%.6f\n",pos_ratio);
    printf("%.6f\n",neg_ratio);
    printf("%.6f\n",zero_ratio);
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr = malloc(n* sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    plusMinus(n, arr);
    return 0;
}