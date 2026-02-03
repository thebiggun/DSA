
/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};*/
class Solution {
public:
    int diam = 0;
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        diam = max(diam, left+right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // To be implemented by the user
        height(root);
        return diam;
    }
};