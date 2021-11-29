#include"sort.h"

void select_sort(vector<int>& arr){
    int length = arr.size();
    for(int i=0;i< length-1;i++){
        int minIndex =i;
        for(int j=i;j<length;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
