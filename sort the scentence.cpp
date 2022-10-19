class Solution {
public:

    std::string sortSentence(std::string s) {
    std::stringstream ss;
    int i = 0;
    int j = s.size() - 1;
    int max = 0;
    std::string arr[10];
    while (i != j) {
        int arrN = 1;
        std::string temp = s.substr(i, s.find(" ",i) - i );
        if (s.find(" ", i) == std::string::npos)
            i = j;
        else
        i = s.find(" ", i) + 1;
        arrN = temp[temp.size() - 1] - '0';
        arr[arrN] = temp.substr(0, temp.size() - 1);
        if (arrN > max)
            max = arrN;
    }
    for (int i = 1; i <= max; i++)
    {
        if (i == max)
            ss << arr[i];
        else
            ss << arr[i] << " ";
    }
    return ss.str();
}

};
