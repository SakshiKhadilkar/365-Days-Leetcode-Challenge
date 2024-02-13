class Solution {
public:
    
    bool is_palindrome(string s){
        
        int n = s.length();
        
        int i = 0;
        int j = n-1;
        
        while(i<j){
            
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
        
    }
    
    string firstPalindrome(vector<string>& words) {
        
        int n = words.size();
        
        for(int i=0; i<n; i++){
            
            if(is_palindrome(words[i]))
                return words[i];
            
        }
        
        return "";
    }
};