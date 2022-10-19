class Solution {
public:
    vector<int> partitionLabels(string s) {
    vector<int> res;
    if(s.size() == 1){
    res.push_back(1);
    return res;
    }
        
    unordered_map<char,int>pos; // last occurence index;
    for(int i = 0; i<s.size();i++)
        if(pos.find(s[i]) == pos.end())
            pos[s[i]]  = s.find_last_of(s[i]);
        
    int left = 0;
    int partition = -1;
    for(int i = 0; i<s.size();i++){
        
      partition =  max(partition,pos[s[i]]); //
      if(i == partition){
          res.push_back(i - left + 1);
          left = i + 1;
      }
       
    }
     return res;
        
    }
};
