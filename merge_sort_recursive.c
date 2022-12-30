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

void merge_sort(int *arr, int low, int high){
  if (low < high) {
  int mid = (low+high) / 2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid+ 1, high);
  merge(arr, low, mid, high);
  }
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
    merge_sort(list, 0,size-1);
    for(i=0 ; i<size ; i++)
        printf("%d ",list[i]);
    printf("\n");
}