// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal

#include<iostream>
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
    TreeNode* Q[2001];
    int l = 0 , r = 0;
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        TreeNode* head = root;
        std::vector<std::vector<int>> ans;
        Q[r++] = head;
        bool reverse = false;
        while(l < r){
            int len = r - l;
            int i = reverse ? r - 1 : l;
            int step = reverse ? -1 : 1;
            std::vector<int> _ans;

            for(int k = 0 ; k < len ; i += step){
               _ans.push_back(Q[i]->val); 
            }

            reverse = !reverse;
            for(int k = 0 ; k < len ; k++){
                TreeNode* tmp = Q[l++];

                if(tmp->left)   Q[r++] = tmp->left;
                if(tmp->right)  Q[r++] = tmp->right;

            }

            ans.push_back(_ans);
        }
        return ans;
    }
};