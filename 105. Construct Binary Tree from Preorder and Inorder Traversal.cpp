#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        unordered_map<int, int> index;
        for (int i=0; i<inorder.size(); i++){
            index[inorder[i]] = i;
        }
        return helper(preorder, inorder, index, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& index, int pstart, int pend, int istart, int iend){
        if (pstart>pend) return nullptr;
        if (pstart==pend) {
            TreeNode* root = new TreeNode(preorder[pstart]);
            return root;
        }
        int root_index = index[preorder[pstart]];
        int left_length = root_index-istart;
        TreeNode* root = new TreeNode(preorder[pstart]);
        root->left = helper(preorder, inorder, index, pstart+1, left_length+pstart, istart, root_index-1);
        root->right = helper(preorder, inorder, index, pstart+left_length+1, pend, root_index+1, iend);
        return root;
    }
};

int main105(){
    vector<int> preorder{1,2,3};
    vector<int> inorder{3,2,1};
    Solution solution;
    TreeNode* result;
    result = solution.buildTree(preorder, inorder);
    return 0;
}