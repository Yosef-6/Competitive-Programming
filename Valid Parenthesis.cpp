class Solution {
public:
    
bool isValid(const std::string &s) {
    std::stack<char> brace;
    auto Pair = [](char c) {
        if (c == '}')
            return '{';
        else if (c == ']')
            return '[';
        else
            return '(';
    };
    for (size_t i = 0; i < s.size(); i++) {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            brace.push(s[i]);
        else {
            if (brace.empty()||Pair(s[i]) != brace.top())
                return false;
            else
                brace.pop();
        }

    }
    return brace.empty() ? true : false;
}
    
};
