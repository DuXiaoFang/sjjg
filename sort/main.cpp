
#include"sort.h"
// #include<time.h>
// typedef long clock_t;
using namespace std;

int main(){

    vector<int> arr ={3,5,0,32,7,46,6};

    int length = arr.size();

    // clock_t startTime,endTime;
    // startTime = clock();
    //bubble_sort(arr);
    //quick_sort(0,length-1,arr); 
    //select_sort(arr);  
    //merge_sort(arr,0,length-1);
    merge_sort_recurison(arr);
    // endTime= clock();
    // cout<< endTime-startTime << endl;

    for(int i=0;i<arr.size();i++){
        cout<< arr[i]<<"\t";
    }
    cout<< endl;

    return 0;
}