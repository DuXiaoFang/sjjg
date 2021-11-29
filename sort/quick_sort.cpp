#include"sort.h"


void quick_sort(int l,int r,vector<int>& arr){
    int left =l;
    int right =r;
    if(left>=right){
        return;
    }    
    int base =arr[left];
    //cout<< left << right << endl;   
    while(left<right){
        while(arr[right]>base&&left<right){
            right--;
        }  
        arr[left] = arr[right];      
        while(arr[left]<=base&&left<right){
            left++;
        }
        arr[right]= arr[left];
        //cout<< left << right << endl;
    }
    arr[left] = base;

    quick_sort(l,left-1,arr);
    quick_sort(left+1,r,arr);
}
