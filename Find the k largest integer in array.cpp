class Solution {
public:
    std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
    auto comp = [](std::string& a, std::string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    };
    std::make_heap(nums.begin(), nums.end(),comp);
    int i = 1;
    while (i<=k-1) {
        std::pop_heap(nums.begin(), nums.end(), comp);
       nums.pop_back();
        i++;
    }
    return nums.front();
}

};
