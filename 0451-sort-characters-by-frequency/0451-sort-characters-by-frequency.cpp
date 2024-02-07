class Solution {
public:
    
    string frequencySort(string s) {
        
        unordered_map<char,int> mp;
        string ans = "";
        
        for(int i=0; i<s.length(); i++){
            
            mp[s[i]]++;
        }
        
        vector<pair<char,int>> freq(mp.begin(),mp.end());
        
        sort(freq.begin(),freq.end(),[](const auto &a,const auto &b){
            return a.second > b.second;
        });
        
        mp.clear();
        
        for(const auto &p : freq){
            
            for(int i=0; i<p.second; i++)
                ans += p.first;
        }
        
        return ans;
    }
};