
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         
        unordered_map<int,int>sum_count;
        int subArr=0;
        int prefixSum =0;
        int j = 0;
        while(j<nums.size()){
            
            prefixSum +=nums[j];
            if(prefixSum == k)
                subArr++;
            if(sum_count.find(prefixSum-k) != sum_count.end())
                subArr+=sum_count[prefixSum-k];
            
            sum_count[prefixSum] +=1;
            
            j++;
        }
        
       return subArr; 
    }
};
