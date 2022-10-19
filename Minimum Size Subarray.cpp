class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int length = INT_MAX; 
         int total  = 0;
         int left   = 0;
         int right  = 0;
         while(right!=nums.size()){
             total+=nums[right];
             while(total >= target){
                 length = min(length,right - left + 1);
                 total-= nums[left++];
             }
                     
          right++;
         }
        return length ==  INT_MAX ? 0 : length ;
        }
};
