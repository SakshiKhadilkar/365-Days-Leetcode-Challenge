class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int orgsum=0;
        int calsum=0;
        int n = nums.size();
        
        for(int i=1; i<=n; i++)
            calsum += i;
        
        for(int i=0; i<n; i++)
            orgsum += nums[i];
        
        return abs(calsum - orgsum);
    }
};