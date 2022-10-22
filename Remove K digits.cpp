class Solution {
public:
    string removeKdigits(string num, int k) {
       if(num.size() == k)
           return "0";
       deque<char>mstack;
     
       for(char c : num){
           if(!mstack.empty()){
               if(mstack.back() <= c || k == 0)
                   mstack.push_back(c);
               else{
                   while(k > 0 && !mstack.empty() && mstack.back() > c){
                       mstack.pop_back();
                       k--;
                   }
                   mstack.push_back(c);
               }
           }
           else
           mstack.push_back(c);
           
       }
      
        
       string answer(mstack.begin(),mstack.end() - k);
       int j = 0;
       int sze = answer.size();
       while(sze != 1 &&answer[j] == '0'){
           j++;
           sze--;
       }
       
           
       return answer.substr(j,string::npos);
           
        
        
    }
};
