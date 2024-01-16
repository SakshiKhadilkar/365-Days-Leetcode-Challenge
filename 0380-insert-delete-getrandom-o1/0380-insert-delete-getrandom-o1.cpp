class RandomizedSet {
public:
    
    vector<int> vec;
    unordered_map<int,int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.find(val) != mp.end())
            return false;
        
        vec.push_back(val);
        mp[val] = vec.size()-1;
        
        return true;
    }
    
    bool remove(int val) {
        
        if(mp.find(val) == mp.end())
            return false;
        
        int idx = mp[val];
        int ele = vec.back();
        vec.pop_back();
        vec[idx] = ele;
        mp[ele] = idx;
        mp.erase(val);
        
        
        return true;
    }
    
    int getRandom() {
        
        int n = vec.size();
        
        int ranIndex = rand()%n;
        
        return vec[ranIndex];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */