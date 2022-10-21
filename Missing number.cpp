class Solution {
public:
    int missingNumber(vector<int>& nums) {
    long sum = nums.size();
    return sum*(sum + 1)/2 - accumulate(nums.begin(),nums.end(),0);
    }
};
