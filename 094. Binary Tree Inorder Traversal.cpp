#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Solution 1: use DFS
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversal_dfs(root);
        return result;
    }

    void inorderTraversal_dfs(TreeNode* root) {
        if (root) {
            if (root->left) inorderTraversal_dfs(root->left);
            result.push_back(root->val);
            if (root->right) inorderTraversal_dfs(root->right);
        }
    }

    // Solution 2: use hash map 100% & 100%
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> nodes;
        nodes.push(root);
        unordered_map<TreeNode*, bool> visited;
        while (!nodes.empty()){
            TreeNode* current = nodes.top();
            if (!visited[current] && current->left){
                nodes.push(current->left);
                visited[current] = true;
            }
            else {
                result.push_back(current->val);
                nodes.pop();
                if (current->right) {
                    nodes.push(current->right);
                }
            }
        }
        return result;
    }
};