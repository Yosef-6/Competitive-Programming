class Solution {
public:
      std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::vector <int> answer;
        std::sort(nums.begin(),nums.end());
        int i = 0;
        for (auto& num : nums){
            if(num == target)
                answer.push_back(i);
            i++;
        }
        return answer;
    }
};
