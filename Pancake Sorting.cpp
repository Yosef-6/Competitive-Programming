class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
    vector<int>sequence;
    if(std::is_sorted(arr.begin(),arr.end()))
        return sequence;
    size_t size = arr.size();    
    for(size_t i = 0; i<arr.size(); i++){
        auto max = max_element(arr.begin(),arr.end() - i);
        
        if(max == arr.begin() + (size - (1  + i))) // if the max element is it right position dont flip
          continue;
        
        sequence.push_back(((int)(max - arr.begin())  +  1));
        sequence.push_back(size - i);
        reverse(arr.begin(),max + 1);
        reverse(arr.begin(),arr.end() - i);
    }
      return sequence;  
    }
};
