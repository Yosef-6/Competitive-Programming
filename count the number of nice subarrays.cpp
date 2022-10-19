class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      unordered_map<int,int>keys;
      int j=0;
      int currSum = 0;
      int nice = 0;
      while(j<nums.size()){
          if(nums[j]%2!=0)
              nums[j] = 1;
          else
              nums[j] = 0;
          
          currSum += nums[j];
          
          
          if(currSum == k)
              nice++;
          if(keys.find(currSum - k) != keys.end())
              nice += keys[currSum - k];
          
          keys[currSum]+=1;
          
          j++;
      }
      return nice;
    }
};
