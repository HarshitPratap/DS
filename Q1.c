#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int main(int argc, char const *argv[])
{
    int size,i,j,k;
    int arr[MAX];
    int pArr[MAX];
    int nArr[MAX];
    printf("Enter size of array:- ");
    scanf("%d",&size);
    printf("Enter elements of array:- ");
    for ( i = 0; i < size; i++)
    {
       scanf("%d",&arr[i]); 
    }
    j=k=0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            nArr[j++] = arr[i];
        }else if(arr[i] >= 0){
            pArr[k++] = arr[i];
        }
    }
    i = 0;
    for ( ; i < j; i++)
    {
        arr[i] = nArr[i];
    }
    for ( k = 0; i < size; i++,k++)
    {
        arr[i] = pArr[k];
    }
    for ( i = 0; i < size; i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}
