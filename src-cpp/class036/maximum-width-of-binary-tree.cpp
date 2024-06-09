// https://leetcode.cn/problems/maximum-width-of-binary-tree/description/


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
    TreeNode* node[3001];
    int node_num[3001];
    int l = 0 , r = 0;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        node[r] = root;
        node_num[r] = 1;
        r++;
        int max_width = 0;

        while(l < r){
            int len = r - l;
            int width = node_num[r-1] - node_num[l] + 1;
            max_width = width > max_width ? width : max_width;
            for(int k = 0 ; k < len ; k++){
                TreeNode* tmp = node[l];
                int id = node_num[l];
                l++;

                if(tmp->left){
                    node[r] = tmp->left;
                    node_num[r] = id * 2;
                    r++;
                }
                if(tmp->right){
                    node[r] = tmp->right;
                    node_num[r] = id * 2 + 1;
                    r++;
                }
            }
        }

        return max_width;

    }
};