#include <iostream>
#include <string>
#include <vector>
#include<stack>
#include <queue>
using namespace std;

template<class T>
struct TreeNode
{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x): val(x),left(NULL),right(NULL) {}
};


template<class T>
class recursion{
private:
    void preorder(vector<T>& res,TreeNode* node){
        if(root == NULL){
            return;
        }
        res.push_back(node->val);
        preorder(res,node->left);
        preorder(res,node->right);
    }
    void inorder(vector<T>& res,TreeNode* node){
        if(root == NULL){
            return;
        }
        inorder(res,node->left);
        res.push_back(node->val);        
        inorder(res,node->right);
    }
    void posorder(vector<T>& res,TreeNode* node){
        if(root == NULL){
            return;
        }
        posorder(res,node->left);
        posorder(res,node->right);        
        res.push_back(node->val);        
    }
public:
    vector<T> recursion(TreeNode* root){
        vector<T> res;
        preorder(res,root);
        //inorder(res,root);
        //pos(res,root);
        return res;
    }
};

template<class T>
class Nonrecursion{
private:
    void preoder(vector<T>& res,TreeNode* node){
        stack<TreeNode*> s;
        while(node != NULL && !s.empty()){
            while(node != NULL){
                res.push_back(node->val);
                s.push(node);
                node = node->left;
            }
            if( !s.empty()){
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
    }

    void inorder(vector<T>& res,TreeNode* node){
        stack<TreeNode*> s;
        while(node != NULL && !s.empty()){
            while(node!=NULL){
                s.push(node);
                node = node->left;
            }
            if(!s.empty()){
                node = s.top();
                res.push_back(node->val);
                s.pop();
                node = node->right;                
            }
        }
    }

    void posorder(vector<T>& res,TreeNode* node){
        stack<TreeNode*> s;
        while(node != NULL && !s.empty()){
            while(node!=NULL){
                s.push(node);
                node = node->left;
            }
            
        }
    }
};


int main(){
    return 0;
}