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
    
    void makeGrp(unordered_map<int,vector<int>> &adj, int parent, TreeNode* curr){
        
        if(curr == NULL)
            return ;
        
        if(parent != -1)
            adj[curr->val].push_back(parent);
        
        if(curr->left != NULL)
            adj[curr->val].push_back(curr->left->val);
        
        if(curr->right != NULL)
            adj[curr->val].push_back(curr->right->val);
        
        makeGrp(adj,curr->val,curr->left);
        makeGrp(adj,curr->val, curr->right);
        
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int,vector<int>> adj;
        
        makeGrp(adj,-1,root);
        
        unordered_set<int> visited;
        queue<int> que;
        
        que.push(start);
        visited.insert(start);
        
        int minutes = 0;
        
        while(!que.empty()){
            
            int n = que.size();
            
            while(n--){
                
                int val = que.front();
                que.pop();
                
                for(int &ngbr : adj[val]){
                    
                    if(visited.find(ngbr) == visited.end()){
                        
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            
            minutes++;
        }
        
        return minutes-1;
    }
};