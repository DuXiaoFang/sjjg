#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


void sift(vector<int>& li, int low, int high){
    int i = low;
    int j =2*i+1;
    int temp = li[i];
    while(j<=high){
        if(j<high && li[j+1]>li[j]){//如果右孩子存在且大于左
            j = j+1;//j指向右孩子
        }
        if(li[j]>temp){
            li[i] = li[j];
            i =j;
            j =2*i+1;//往下看一层
        }
        else{//temp放在i位置
            break;
        }
    }
    li[i]=temp;
}

void build_heap(vector<int>& li){
    int len = li.size();
    for(int i =(len/2)-1;i>=0;i--){
        sift(li,i,len-1);
    }

    for(int i=0;i<len-1;i++){
        cout<< li[i]<<"\t";
    }
    cout<< endl;
}


void heap_sort(vector<int>& li){
    int i=0;
    int j = li.size()-1;
    while(j>=i){
        int temp = li[i];
        li[i] = li[j];
        li[j] = temp;
        j = j-1;
        sift(li,i,j);
    }

    cout<< "ok" <<endl;
    // for(int i=0;i<li.size();i++){
    //     cout<< li[i]<<"\t";
    // }
    // cout<< endl;

}

int main(){

    vector<int> li(100);
    for(int i=0;i<100;i++){
        li[i] = i;
    }

    build_heap(li);
    heap_sort(li);


    for(int i=0;i<100;i++){
        cout<< li[i]<<"\t"; 
    }

    return 0;
}