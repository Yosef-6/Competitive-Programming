class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    vector<int>answer(nums1.size(),-1);
    stack<int>mstack;
    unordered_map<int,int>next;
    for(int elm : nums2){
        
        if(!mstack.empty() && mstack.top() > elm || mstack.empty())
            mstack.push(elm);
            
         else{
             while(!mstack.empty() && mstack.top() < elm){
                 next[mstack.top()] = elm;
                 mstack.pop();
             }
             mstack.push(elm);
             
         }   
    }
    for(int i = 0; i<nums1.size(); i++){
        
        if(next.find(nums1[i]) != next.end())
            answer[i] = next[nums1[i]];
        
    }
        
     return answer;   
    }
};
