class Solution {
public:
       int evalRPN(std::vector<std::string>& tokens) {
    std:: stack<long int> num;
     for(auto & i : tokens){
             char  j;
             if(i.size() > 1)
             j = '[';
             else
             j = i[0];
             if(j == '+' || j == '-'|| j== '*' || j=='/'){
                long int op2 = num.top();num.pop();
                long int op1 = num.top();num.pop();
                if(j == '+')
                    num.push(op1+op2);
                else if(j == '-')
                    num.push(op1 - op2);
                 else if(j == '*')
                    num.push(op1 * op2);
                 else if(j == '/')
                    num.push(op1 / op2);
                

             }
             else{
                long int jnum = 0;
                std::stringstream ss;
                ss<<i;
                ss>>jnum;
                num.push(jnum);
             }

     }
        return num.top();


}
};
