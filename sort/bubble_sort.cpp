#include"sort.h"


void bubble_sort(vector<int>& arr){
    int length = arr.size();

    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp =arr[j+1];
                arr[j+1] =arr[j];
                arr[j]= temp;
            }
        }
    }
}

