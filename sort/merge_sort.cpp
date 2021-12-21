#include"sort.h"

void merge(vector<int>& arr, int low, int mid ,int high){
    int i= low;
    int j =mid+1;
    vector<int> tmp; 
    while(i<=mid && j<= high){
        if(arr[i]<arr[j]){
            tmp.push_back(arr[i]);
            i += 1;
        }
        else{
            tmp.push_back(arr[j]);
            j +=1;
        }
    }
    while(i<=mid){
        tmp.push_back(arr[i]);
        i += 1;  
    }
    while(j<=high){
        tmp.push_back(arr[j]);
        j +=1;       
    }

    copy(tmp.begin(),tmp.end(),arr.begin()+low);
    //arr.assign(tmp.begin(),tmp.end());
}

void merge_sort(vector<int>& arr, int low, int high){
    if(low<high){
        int mid =(low+high)/2;

        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        // for (auto i : arr)
        //     cout << i << ' ';
        // cout<< endl;
        merge(arr,low,mid,high);
    }
}

