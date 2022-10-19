class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    std::sort(points.begin(),points.end(), [](std::vector<int>& vec1, std::vector<int>& vec2) ->bool {

        int d1 = vec1[0] * vec1[0] + vec1[1] * vec1[1];
        int d2 = vec2[0] * vec2[0] + vec2[1] * vec2[1];
        return d1 < d2;
        }
    );
    return std::vector<std::vector<int>>(points.begin(),points.begin() + k);

}
};
