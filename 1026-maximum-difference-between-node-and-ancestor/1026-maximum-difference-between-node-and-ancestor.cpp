/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDiff(TreeNode* root, int maxv, int minv){
        
        if(root == NULL)
            return abs(maxv-minv);
        
        maxv = max(maxv, root->val);
        minv = min(minv, root->val);
        
        int l = maxDiff(root->left,maxv,minv);
        int r = maxDiff(root->right,maxv,minv);
        
        return max(l,r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        return maxDiff(root, root->val, root->val);
    }
};