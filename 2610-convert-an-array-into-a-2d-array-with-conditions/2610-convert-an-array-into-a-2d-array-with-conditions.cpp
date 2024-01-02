class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> mp(n+1,0);

        for(int i=0; i<n; i++){

            int freq = mp[nums[i]];

            if(result.size() == mp[nums[i]]){

                result.push_back({});

            }

            result[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }

        return result;
    }
};