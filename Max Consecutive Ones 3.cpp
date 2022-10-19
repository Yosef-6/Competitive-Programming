class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int len = 0;
    int left = 0;
    int zeros = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == 0)
        zeros++;
        if(zeros > k){
            while(true){
                if(nums[left] == 0)
                    break;
                left++;
            }
            left++;
            zeros-=1;
        }
        else
            len = max(len,i - left + 1);
    }
        return len;
    }
};
