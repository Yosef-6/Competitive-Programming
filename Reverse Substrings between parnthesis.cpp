class Solution {
public:
    string reverseParentheses(string s) {
        stringstream ss;
        string poped;
        stack<char>mstack;
        for(auto &elm : s){
            if(elm != ')')
                mstack.push(elm);
            else{
                   while(mstack.top() != '('){
                       ss<<mstack.top();
                       mstack.pop();
                                             }
                    mstack.pop();
                    poped = ss.str();
                    ss.clear();
                    ss.str(string());
                    for(auto & ch : poped)
                            mstack.push(ch);
                }
            
        }
         ss.clear();
        ss.str(string());
        while(!mstack.empty()){
             ss<<mstack.top();
              mstack.pop();
        }
        poped = ss.str();
        reverse(poped.begin(),poped.end());
        return poped;
        
    }
};
