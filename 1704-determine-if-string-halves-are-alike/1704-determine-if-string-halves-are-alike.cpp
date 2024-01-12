class Solution {
public:
    
    int no_of_vowels(string s){
        
        int vowels = 0;
        
        for(auto it: s){
            
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'||it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U')
                vowels++;
                
        }
        
        return vowels;
    }
    
    bool halvesAreAlike(string s) {
        
        int n = s.length();
        
        int lefthalf = no_of_vowels(s.substr(0,n/2));
        int righthalf = no_of_vowels(s.substr(n/2,n/2));
        
        return lefthalf == righthalf;
        
    }
};