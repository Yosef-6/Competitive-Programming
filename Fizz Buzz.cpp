class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::stringstream ss;
        std::vector<string>answer;
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0)
            answer.emplace_back("FizzBuzz");
            else if(i%3==0 )
            answer.emplace_back("Fizz");
             else if(i%5==0 )
            answer.emplace_back("Buzz");
            else {
            ss<<i;
            answer.emplace_back(ss.str());
                ss.clear();
                ss.str("");
            
            }
        }
        return answer;
    }
};
