class Solution {
public:
    Solution(vector<int>& nums):m_map() {
        for(size_t i = 0; i<nums.size();i++){
           m_map[nums[i]].indexes.push_back(i);
        }
    }
    
    int pick(int target) {
        auto& INFO = m_map[target];
        size_t i = INFO.i;
        INFO.i = (INFO.i + 1) % INFO.size();
        return INFO.indexes[i];
    }
    struct info{
        std::vector<int>indexes;
        size_t i = 0;
    };
    std::unordered_map<int,info>m_map; // int and index == to target
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
