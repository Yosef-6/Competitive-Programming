class Solution {
public:
      vector<int> smallerNumbersThanCurrent(const std::vector<int>& nums) {
        vector<int> answer;
        for(int i = 0; i<nums.size(); i++){
            int count = 0;
            for(int j = 0; j<nums.size(); j++){
                if(nums[j] < nums[i])
                    count++;

            }
            answer.push_back(count);
        }
        return answer;

}
};
