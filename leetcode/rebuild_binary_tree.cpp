#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    vector<int> preorder;
    unordered_map<int, int> dic;
private:
    TreeNode* search(int root,int right,int left){
        if(right< left){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[root]);
        int i = dic[preorder[root]];
        node->left = search(root+1,i-1,left);
        node->right = search(root+i-left+1,right,i+1);
        return node;
    }   
public:
    TreeNode* buildtree(vector<int>& preorder,vector<int>& inorder){
        this->preorder = preorder;
        for(int i=0;i<inorder.size();i++){
            dic[inorder[i]]=i;
        }
        return search(0,preorder.size()-1,0);
    }
};

void print(TreeNode* & node,vector<int>& arr){
    if(node==NULL){
        arr.push_back(100);
        return ;
    }

    arr.push_back(node->val);
    print(node->left,arr);
    print(node->right,arr);
}


/*

        根节点索引              中序遍历左边界      中序遍历右边界
左子树   root + 1	            left	           i - 1
右子树   i - left + root + 1	i + 1	           right

作者：jyd
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-di-gui-fa-qin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution s;
    TreeNode* node= s.buildtree(preorder,inorder);
    vector<int> arr;
    print(node,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<< "\t";
    }
}