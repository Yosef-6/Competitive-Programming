class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int left = 0;
    int longest = 0;
    int zeros = 0;
    for(int i = 0; i<nums.size();i++){
        
        if(nums[i] == 0 && zeros == 1){
            while(nums[left]!=0)
                left++;
            left++;
        }
        else if(nums[i] == 0)
            zeros++;
        
        
        
        longest = max(longest,i - left);
        
        
    }
        return longest;
    }
};
