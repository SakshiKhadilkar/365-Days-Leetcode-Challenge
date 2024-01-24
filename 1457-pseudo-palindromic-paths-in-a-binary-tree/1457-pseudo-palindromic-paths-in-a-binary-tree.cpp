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
    int result = 0;
    
    void solve(TreeNode* root, int count){
        
        if(root == NULL)
            return ;
        
        count = (count ^ (1 << root->val));
        
        if(root->left == NULL && root->right == NULL){
            
            if((count & (count - 1)) == 0)
                result += 1;
        }
        
        solve(root->left,count);
        solve(root->right, count);
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
     
        
        solve(root,0);
        
        return result;
    }
};