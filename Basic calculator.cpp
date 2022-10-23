//not an efficent soln two pass is made 
class Solution {
public:
    int calculate(string s) {
    deque<string>mstack;
    char  op = '.'; // starting point
    stringstream ss;
    int j=0;

    while(j < s.size()){
        if(s[j] == '+' || s[j] == '-'){
            op = s[j];
            ss<<s[j];
            mstack.push_back(ss.str());
            ss.clear(); ss.str(string(""));
            j++;
        }
        else if(s[j]=='/' || s[j]== '*'){
            op = s[j];
            j++;
        }
        else if(s[j] != ' '){
            
            while(j < s.size() && (s[j] != '+' && s[j] != '-' && s[j] != '*' && s[j] != '/' && s[j] != ' '))
                ss<<s[j++];
              
            if(op == '*' || op == '/'){
                int op2;
                int op1;
                ss>>op2;
                ss.clear(); ss.str(string(""));
                ss<<mstack.back();
                ss>>op1;
                mstack.pop_back();
                ss.clear(); ss.str(string(""));
                ss<< (op == '/' ?   op1/op2   :   op1*op2);
                mstack.push_back(ss.str());
                ss.clear(); ss.str(string(""));
            }
            else{ 
                  mstack.push_back(ss.str());
                  ss.clear(); ss.str(string(""));
                }
            
        }
        else
            j++;
     
    }
        
    int result = 0;

    while(mstack.size()!=1){
            char fop = ' ';
            int op1;     
            int op2;
            ss<<mstack.front();mstack.pop_front();fop = mstack.front()[0];mstack.pop_front();
            ss>>op1;ss.clear(); ss.str(string(""));
            ss<<mstack.front();
            ss>>op2;ss.clear(); ss.str(string(""));;mstack.pop_front();
            
            ss<< (fop == '+' ? op1 + op2 : op1 - op2 );
            mstack.push_front(ss.str());
            ss.clear(); ss.str(string(""));
            
    }
    ss<<mstack.back();
    ss>>result;
        
        
     return result;  
        
        
        
        
    
    }
};

// one pass soln










