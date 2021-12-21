#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


void quick_sort(int l,int r,vector<int>& arr);
void bubble_sort(vector<int>& arr);
void select_sort(vector<int>& arr);
void insert_sort(vector<int>& arr);
void merge_sort_recurison(vector<int>& arr);
void merge_sort(vector<int>& arr, int low, int high);
void shell_sort(vector<int>& arr);