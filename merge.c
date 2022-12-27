#include <stdio.h>

void merge(int *list, int start, int mid, int end){
    int i=start, j=mid+1, k=0; 
    int temp[(end-start)+1];
    while (i<=mid && j<=end){
        if(list[i] < list[j])
            temp[k++] = list[i++];
        else
            temp[k++] = list[j++];
    }
    while (i<=mid)
        temp[k++] = list[i++];
    while(j<=end)
        temp[k++] = list[j++];
    for(i=start,k=0 ; k<sizeof(temp)/sizeof(temp[0]) ; i++,k++){
        list[i] = temp[k];
    }
}

void merge_sort(int *list, int size){
    int s, e, mid;
    int i,j;
    for(i=2 ; i<=size ; i=i*2){
        for(j=0 ; (j+i)-1<size ; j=j+i){
            s = j;
            e = (j+i)-1;
            mid = (s+e)/2;
            merge(list, s, mid, e);
        }
    }
    if(i/2 < size)
        merge(list, 0, (i/2)-1, size);
}

int main(){
    int size;
    printf("Enter number of numbers: ");
    scanf("%d",&size);
    int list[size];
    int i;
    for(i=0 ; i<size ; i++){
        printf("Enter a number: ");
        scanf("%d",&list[i]);
    }
    merge_sort(list, size);
    for(i=0 ; i<size ; i++)
        printf("%d ",list[i]);
    printf("\n");
}