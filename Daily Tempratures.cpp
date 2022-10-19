class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> answer(temperatures.size(),0);
    stack<pair<int,int>>mstack; // int index of element to be stored, int val of //elment
    for(int i = 0; i<temperatures.size();i++){
      
    
      if(!mstack.empty() && mstack.top().second >= temperatures[i] || mstack.empty())
          mstack.push({i,temperatures[i]});
        
      else{
             while(!mstack.empty() && mstack.top().second < temperatures[i]){
                 const auto &[index,val] = mstack.top();
                 answer[index] =  i - index;
                 mstack.pop();
             }
             mstack.push({i,temperatures[i]});
             
         }      
    }
    return answer;
    }
};
