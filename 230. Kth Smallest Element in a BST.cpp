struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// very slow solution
class Solution {
public:
    int k;
    int kthSmallest(TreeNode* root, int k) {
        Solution::k = k;
        kthSmallest_dfs(root);
        return result;
    }

    void kthSmallest_dfs(TreeNode* root){
        if (root){
            kthSmallest_dfs(root->left);
            k --;
            if (k==0){
                result = root->val;
                return;
            }
            kthSmallest_dfs(root->right);
        }
    }

private:
    int result =0;
};