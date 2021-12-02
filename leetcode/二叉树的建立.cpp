#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Order{
private:
    void dfs(TreeNode* root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        arr.push_back(root->val);
        dfs(root->left,arr);
        dfs(root->right,arr);
    }
public:
    vector<int> preorder(TreeNode* root){
        vector<int> arr;
        dfs(root,arr);
        return arr;
    }
};


class BST {
private:
    bool dfs(TreeNode*root,long long lower,long long higher){
        if(root== NULL){
            return true;
        }
        if(root->val>lower && root->val< higher){
            return true;
        }
        return dfs(root->right,root->val,higher) &&dfs(root->left,lower,root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
};


TreeNode* create_tree(TreeNode* root,int ch[],int i,int len){
    root->val=ch[i];
    if(2*i+1<len){
        TreeNode* nodeleft = new TreeNode;
        root->left =create_tree(nodeleft,ch,2*i+1,len);
    } 
    else{
        root->left =NULL;

    }
    if(2*i+2<len){
        TreeNode* noderight = new TreeNode;
        root->right =create_tree(noderight,ch,2*i+2,len);        

    } 
    else{
        root->right =NULL;
    }
    return root;
}

int main(){ 

    int ch[] = {0,3,2,5,7,9};

    int len = sizeof(ch)/sizeof(ch[0]);
    TreeNode* root = create_tree(new TreeNode,ch,0,len);
    cout<< root->left->val << endl;

    
    // Order o;
    // vector<int> arr =o.preorder(root);
    // for(int i=0;i<arr.size();i++){
    //     cout<< arr[i]<<"\t";
    // }
    // cout<< endl;

    BST s;
    bool value = s.isValidBST(root);
    cout<<value;


    return 0;
}