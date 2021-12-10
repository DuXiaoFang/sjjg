#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    void test(vector<vector<bool>>& temp,vector<vector<int>>& matrix,vector<int>& res,int i,int j,int flag){
        int lenx = matrix.size();
        int leny = matrix[0].size();
        if(temp[i][j]==true){
            return;
        }
        else{
            if(i==flag&&0<=j&& j<leny-1){
                res.push_back(matrix[i][j]);
                temp[i][j] = true;
                test(temp,matrix,res,i,j+1,flag);
            }
            else if(i==lenx-flag-1&&0<j&&j<=leny-1){
                res.push_back(matrix[i][j]);
                temp[i][j] = true;
                test(temp,matrix,res,i,j-1,flag);
            }
            else if((j==leny-flag-1)&&0<=i&& i<lenx-1){
                res.push_back(matrix[i][j]);
                temp[i][j] = true;
                test(temp,matrix,res,i+1,j,flag);
            }
            else if(j==flag &&0<i&&i<=lenx-1){
                res.push_back(matrix[i][j]);
                temp[i][j] = true;
                if(j==flag && i==flag+1) {
                    test(temp,matrix,res,i,j+1,flag+1);
                }
                else{
                    test(temp,matrix,res,i-1,j,flag);             
                }
            }  
        }

    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<bool>> temp(matrix.size(), vector<bool>(matrix[0].size()));
        if(matrix.size()==0){
            return res;
        }
        test(temp,matrix,res,0,0,0);
        return res;
    }
};

int main(){
    vector<vector<int> > matrix(3);//一定要初始化大小，不然下面m[i]就不能这样用
    int k=1;
    for(int i=0;i<3;i++){        
        for(int j=0;j<3;j++){
            matrix[i].push_back(k++);            
        }           
    }
    Solution slt;
    vector<int> res = slt.spiralOrder(matrix);
    for(int i=0;i<res.size();i++){
        cout<< res[i]<<"\t";
    }
    return 0;
}