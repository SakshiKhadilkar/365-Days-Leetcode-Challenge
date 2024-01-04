class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        int result = 0;
        
        for(int i=0; i<n; i++){
            
            mp[nums[i]]++;
        }
        
        for(auto it: mp){
            
            int count = it.second;
            int ans = 0;
            
            if(count == 1)
                return -1;
            
            int temp = 0;
            
            if(count%3 != 0){
                
                temp += (count/3) + 1;
                ans += (count)/2;
            }
            
            else if(count%2 != 0){
                
                temp += (count/2) + 1;
                ans += (count/3);
            }
            
            else {
                
                temp = INT_MAX;
                ans += (count/3);
            }
            
            result += min(ans,temp);
        }
        
        return result;
    }
};