#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p, *temp, i, n;

    printf("Enter total elements: ");
    scanf("%d", &n);

    p = (int*) malloc(sizeof(int)*n);
    if(p == NULL){
        printf("Memory Allocation Failed!");
        return 1; 
    }else{
        printf("%d Memory Allocated!\n", sizeof(int) * n);
    }

    temp = p;
    for(i=0;i<n;i++){
        printf("Enter element %d for position %d: ", i, temp);
        scanf("%d", temp);
        temp++;
    }

    temp = p;
    for(i=0;i<n;i++){
        printf("element at position %d is: %d\n ", temp, *temp);
        temp++;
    }
}