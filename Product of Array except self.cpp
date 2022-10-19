class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer; 
        vector<int> forwardMul(nums.size(),nums.front());
        vector<int> backMul(nums.size(),nums.back());
        for(int i = 1,j = nums.size() - 2 ; i<nums.size(); i++ , j--){
            forwardMul[i]  = nums[i]*forwardMul[i-1];
            backMul[j]     = nums[j]*backMul[j+1];
        }
        for(int i = 0; i<nums.size();i++){
            
            if(i == 0)
                answer.push_back(backMul[1]);
            else if(i == nums.size() - 1)
                answer.push_back(forwardMul[nums.size()-2]);
            else
                answer.push_back(forwardMul[i-1] * backMul[i+1]);
                  
        }
        return answer;
        
    }
};
