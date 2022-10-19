class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numbersToShift = k%nums.size();
        if(numbersToShift == 0)
            return;
        int pointer = nums.size()-numbersToShift;
        vector<int>right(nums.begin()+pointer,nums.end());
        vector<int>left(nums.begin(),nums.begin() + pointer);
        nums.clear();
        nums.reserve(right.size() + left.size());
        nums.insert(nums.end(),right.begin(),right.end());
        nums.insert(nums.end(),left.begin(),left.end());
      }
};
