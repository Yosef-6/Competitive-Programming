class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    vector<int> rightPref(nums.size(),nums.front());
    vector<int> leftPref(nums.size(),nums.back());
    for (int i = 1, j = nums.size() - 2; i<nums.size(); i++, j--){
        rightPref[i] = nums[i] + rightPref[i - 1];
        leftPref[j]  = nums[j] + leftPref [j + 1];
    }
    int maxLen = 0;
    for(int i = firstLen - 1 ; i<nums.size(); i++){
        int l1sum = i == firstLen - 1  ? rightPref[i] : rightPref[i] - rightPref[i-(firstLen)];
        int r_sum = 0;
        int l_sum = 0;
        
        for(int r = i + secondLen; r<nums.size();r++)
            l_sum= max(l_sum,rightPref[r] - rightPref[r - secondLen]);
    
        
        for(int l = i - firstLen - (secondLen - 1); l>=0; l--)
            r_sum= max(r_sum,leftPref[l] - leftPref[l + secondLen]);
            
            
        maxLen = max(maxLen,l1sum +  max(l_sum,r_sum));
        
        }
        
        return maxLen;
        
        
    }
};
