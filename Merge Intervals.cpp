class Solution {
public:
 std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& vec1, std::vector<int>& vec2) ->bool { return vec1[0] < vec2[0]; });
    int j = 1;
    std::vector<std::vector<int>> answer;
    int temp[2] = {intervals[0][0],intervals[0][1]};
    
    while (j!=intervals.size()) {
        if (temp[1] >= intervals[j][0] && temp[1]<=intervals[j][1]) 
            temp[1] = intervals[j][1];
        else if (temp[1] < intervals[j][0] ) {
            std::vector <int> ans{ temp[0],temp[1] };
            answer.emplace_back(std::move(ans));
            temp[0] = intervals[j][0];
            temp[1] = intervals[j][1];       
        }
        j++;
    }
    answer.push_back(std::vector<int>{temp[0], temp[1]});
    return answer;
}
};
