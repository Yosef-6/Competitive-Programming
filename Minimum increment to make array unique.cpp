//O(N^2) brute force time limit exceeds 
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
    int moves = 0;
    unordered_map<int,int>dup;
    for(int i : nums){
        if(dup.find(i) != dup.end()){
            while(dup.find(i) != dup.end()){
                i++;
                moves++;
            }
            dup[i] = 1;
        }
        else
            dup[i] = 1;
    }
    return moves;
        
    }
};
//O(Nlog(n))solution
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
    int count=0;
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i++)
        if(nums[i]==nums[i-1]){
            ++nums[i];
            ++count;  }
        else if(nums[i]<nums[i-1]){
            int k = nums[i-1]-nums[i];
            count+=k+1;
            nums[i]+=k+1;
        }
    return count;
    }
};
