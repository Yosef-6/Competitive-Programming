class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector <int> answer;
        answer.reserve(queries.size());
        for(int i = 1; i<arr.size(); i++)
            arr[i] = (arr[i]^arr[i-1]);
        for(auto & range : queries){
            if(range[0] == 0)
                answer.push_back(arr[range[1]]);
            else
                answer.push_back(arr[range[1]]^arr[range[0]-1]);
                
        }
        return answer;
        
    }
};
