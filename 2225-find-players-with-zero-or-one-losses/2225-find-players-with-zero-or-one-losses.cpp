class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> ans(2);
        unordered_map<int,int> mp;
    
        int n = matches.size();
        
        for(int i=0; i<n; i++){
            
            int winner = matches[i][0];
            int loser = matches[i][1];
            
            if(mp.find(winner) == mp.end())
                mp[winner] = 0;
            
            
            mp[loser]++;
            
            
        }
        
        for(auto it: mp){
            
            if(it.second == 0)
                ans[0].push_back(it.first);
            
            if(it.second == 1)
                ans[1].push_back(it.first);
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        
        return ans;
    }
};