class Solution {
public:
    int minSteps(string s, string t) {
        
        int operations = 0;
        int n = s.length();
        vector<int> vec(26,0);
        
        for(int i=0; i<n; i++){
            
            vec[s[i]-'a']++;
        }
        
        for(int i=0; i<t.length(); i++){
            
            if(vec[t[i]-'a'] <= 0)
                operations++;
            
            vec[t[i]-'a']--;
        }
        
        return operations;
    }
};