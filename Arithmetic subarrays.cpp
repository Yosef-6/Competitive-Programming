class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool>answer;
        for(int i = 0; i<l.size();i++){
           bool check = true;
           int left  = l[i];
           int right = r[i];
           vector<int>test(nums.begin() + left,nums.begin() + right + 1);
           sort(test.begin(),test.end());
           int dif = test[1] - test[0];
           for(int j = 1; j < test.size(); j++)
               if (test[j] - test[j - 1] != dif){
                   check = false;
                   break;
               }
                   
           answer.push_back(check);
            
        }
    return answer;
    }
};
