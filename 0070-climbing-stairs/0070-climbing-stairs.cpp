class Solution {
public:
    
    int no_of_ways(int n, vector<int> &temp){
        
        if(n == 0 || n == 1)
            return 1;
        
        if(temp[n] != -1)
            return temp[n];
        
        return temp[n] = no_of_ways(n-1,temp) + no_of_ways(n-2,temp);
    }
    int climbStairs(int n) {
        
        vector<int> temp(n+1,-1);
        
        return no_of_ways(n,temp);
    }
};