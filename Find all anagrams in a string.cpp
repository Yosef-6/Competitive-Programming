class Solution {
public:
    int pmap[26];
    int smap[26];
    
    vector<int> findAnagrams(string s, string p) {
        for (char c : p) pmap[c-'a']++;
        vector<int> ans;
        
        for (int i = 0; i < s.size(); ++i) {
            smap[s[i]-'a']++;
            if (i >= p.size()) smap[s[i-p.size()]-'a']--;
            
            if (equals()) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
    
    bool equals() {
        for (int i = 0; i < 26; ++i) {
            if (pmap[i] != smap[i]) return false;
        }
        return true;
    }
};
