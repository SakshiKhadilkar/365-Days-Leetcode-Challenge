class Solution {
public:
    unordered_map<string,int> mp;
    bool hasDuplicate(string &s1, string &s2){
        
        int arr[26] = {0};
        
        for(char &ch: s1){
            
            if(arr[ch-'a'] > 0)
                return true;
            
            arr[ch-'a']++;
                
        }
        
        for(char &ch: s2){
            
            if(arr[ch-'a'] > 0)
                return true;
        }
        
        return false;
    }
    
    int solve(int i, vector<string> &arr, string temp, int n){
        
        
        if(i >= n)
            return temp.length();
        
        int include = 0;
        int exclude = 0;
        
        if(mp.find(temp) != mp.end())
            return mp[temp];
        
        if(hasDuplicate(arr[i],temp)){
            
            exclude = solve(i+1,arr,temp,n);
        }
        
        else {
            
            include = solve(i+1,arr,temp+arr[i],n);
            
            exclude = solve(i+1, arr, temp, n);
        }
        
        return mp[temp] = max(exclude,include);
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        string temp = "";
        mp.clear();
        
        return solve(0,arr,temp,n);
    }
};