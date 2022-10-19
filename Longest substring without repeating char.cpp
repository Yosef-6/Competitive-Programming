
class Solution {
public:
   
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        vector<char> window;
        for(int i = 0; i<s.size(); i++){
           auto itr = find(window.begin(),window.end(),s[i]);
           if(itr != window.end())
               window.erase(window.begin(),itr+1);
            window.push_back(s[i]);
            len = max(len,(int)window.size());

        }
        return len;
    }
};
