#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRLEN 100
#define LEN 3

void display(char[][STRLEN],int );
void quickSort(char [][STRLEN], int, int);
void swap(char *, char *);

int main(){
    char str[LEN][STRLEN];
    int i = 0;
    for ( i = 0; i < LEN; i++)
    {
        fflush(stdin);
        printf("Enter %d string:- ",i+1);
        gets(str[i]);
    }
    quickSort(str, 0, LEN - 1);
    printf("\n---------------------After sorting------------------------");
    display(str,LEN);
    return 0;
}

void display(char str[][STRLEN],int l){
    int i = 0;
    printf("\nStrings are as:- ");
    while (i<l)
    {
       printf("%s", str[i]); 
       if (i != l-1)
            printf(", ");
        i++;
    }
}

void quickSort(char str[][STRLEN], int s, int e){
    int i,j,p;
    if (s == e)
    {
        return;
    }
    if (s < e)
    {
        p = s;
        i = s;
        j = e;
        while (i < j)
        {
            while ((strcmp(str[i],str[p]) > 0) &&  i < e)
            {
                i++;
            }
            while ((strcmp(str[j],str[p]) > 0) &&  j > s)
            {
                j--;
            }
            if (i < j)
            {
                swap(str[i],str[j]);
            } 
        }
        swap(str[p],str[j]);
        quickSort(str,s,j-1);
        quickSort(str,j+1,e);
    }
}

void swap(char *fc, char *sc){
    char temp[STRLEN];
    strcpy(temp,fc);
    strcpy(fc,sc);
    strcpy(sc,temp);
}