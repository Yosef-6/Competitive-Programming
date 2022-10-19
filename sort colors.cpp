class Solution {
public:
      void sortColors(vector<int>& nums) {
       vector<int> structure[3];
       for(auto& num : nums)
           structure[num].push_back(num);
       nums.clear();
       int i = 0;
       while(i!=3){
         for(auto& elm : structure[i])
            nums.push_back(elm);
        i++;
       }

   }
};
