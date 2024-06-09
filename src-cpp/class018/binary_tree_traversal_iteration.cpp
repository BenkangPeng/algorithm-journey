//非递归实现先序遍历
// https://leetcode.cn/problems/binary-tree-preorder-traversal/
#include<vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    TreeNode* st[101];
    int l = 0 , r = 0;
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        TreeNode* head = root;
        std::vector<int> ans;
        st[r++] = head;
        while(l < r){//栈不空   
            TreeNode* tmp = st[--r];
            ans.push_back(tmp->val);
            if(tmp->right)  st[r++] = tmp->right;
            if(tmp->left)   st[r++] = tmp->left;

        }

        return ans;
    }

};

//非递归实现中序遍历
// 	// 测试链接 : https://leetcode.cn/problems/binary-tree-inorder-traversal/

class Solution {
private:
    TreeNode* st[101];
    int l = 0 , r = 0;
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        st[r++] = root;
        while(l < r){
            
        }
    }
};