#include"sort.h"


void merge2(vector<int>& arr, int low, int mid, int high){
    vector<int> tmp;
    int i =low;
    int j = mid+1;
    while(i<=mid&& j<=high){
        if(arr[i]<arr[j]){
            tmp.push_back(arr[i]);
            i +=1 ;
        }
        else{
            tmp.push_back(arr[j]);
            j +=1 ;
        }
    }
    while(i<=mid){
        tmp.push_back(arr[i]);
        i +=1 ;
    }
    while(j<=high){
        tmp.push_back(arr[j]);
        j +=1 ;     
    }

    copy(tmp.begin(),tmp.end(),arr.begin()+low);
}


void merge_sort_recurison(vector<int>& arr){
    int high = arr.size()-1;
    cout<< high<< endl;
    int k =0;
    while(k<=high){
        int i=0;
        k = k*2+1;
        while(i<= high){
            int j = i+k;
            if(j>=high ){
                j = high;
            }
            int mid  = (i+j)/2;
            merge2(arr,i,mid,j);  
            i = j+1;       
        }  
    }
}

// int main(){

//     vector<int> arr ={3,5,0,32,7,46,6};

//     int length = arr.size();

//     merge_sort_recurison(arr);


//     for(int i=0;i<arr.size();i++){
//         cout<< arr[i]<<"\t";
//     }
//     cout<< endl;

//     return 0;
// }