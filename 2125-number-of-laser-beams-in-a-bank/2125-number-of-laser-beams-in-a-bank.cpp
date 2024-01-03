class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n = bank.size();
        int ans = 0;
        int prev = 0;
        
        for(int i=0; i<n; i++){
            
            int count = 0;
            
            for(auto it: bank[i]){
                
                if(it == '1')
                    count++;
                
            }
            
            if(count != 0){
                
                ans += prev*count;
                prev = count;
            }
        }
        
        return ans;
    }
};