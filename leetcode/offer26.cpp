#include<iostream>



struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}                                            
};

class Solution {
private:
    bool test(TreeNode*& A, TreeNode*& B){
        if(B==NULL){
            return true;
        }
        if(A==NULL){
            return false;
        }
        if(A->val==B->val){
            return test(A->left,B->left)&&test(A->right,B->right);
        }
        else{
            return false;
        }

    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==NULL || A==NULL){
            return false;
        }
        if(A->val==B->val && test(A->left,B->left) && test(A->right,B->right)){
            return true;
        }
    }
};



