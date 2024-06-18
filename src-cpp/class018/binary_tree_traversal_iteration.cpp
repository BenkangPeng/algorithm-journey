//非递归实现先序遍历
// https://leetcode.cn/problems/binary-tree-preorder-traversal/
#include<vector>
#include<stack>
#include<algorithm>
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

// (1) 将所有左边界入栈
// (2) 弹出栈顶元素，对栈顶元素右结点重复(1)
class Solution {
private:
    TreeNode* st[101];
    int l = 0 , r = 0;
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        std::vector<int> ans;
        TreeNode* head = root;
        while(l < r || head){
            if(head){
                st[r++] = head;
                head = head->left;
            }
            else{
                TreeNode* tmp = st[--r];
                ans.push_back(tmp->val);
                head = tmp->right;
            }
        }
        return ans;
    }
};

//递归实现后序遍历
// https://leetcode.cn/problems/binary-tree-postorder-traversal/description/

//先序遍历：中、左、右
//要转换成：中、右、左，只需要将上面先序遍历迭代法while中两个if交换顺序即可
//while(l < r){//栈不空   
        //     TreeNode* tmp = st[--r];
        //     ans.push_back(tmp->val);
        //     if(tmp->left)  st[r++] = tmp->left;
        //     if(tmp->right)   st[r++] = tmp->right;

        // }

//得到 先‘ ：中、右、左
//再将 先’ 添加进ans的结点顺序反一下即可（用另一个栈）


//两个栈实现
class Solution {
private:
    int l = 0 , r = 0;
    TreeNode* node[101];

    int end = 0 , top = 0;
    TreeNode* st[101];
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   return {};

        TreeNode* head = root;
        node[r++] = head;

        while(l < r){
            TreeNode* tmp = node[--r];
            st[top++] = tmp;
            if(tmp->left)   node[r++] = tmp->left;
            if(tmp->right)  node[r++] = tmp->right;
        }

        std::vector<int> ans;
        while(end < top)    ans.push_back((st[--top])->val);

        return ans;
    }
};


//一个栈实现
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {

    }
};