class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); //control 
        stack<pair<int,int>> maximize;
        int area = 0;
        for(int i = 0; i<heights.size(); i++){
            
            if(!maximize.empty() && maximize.top().second > heights[i]){
                int saveIndex = i;
                while(!maximize.empty() && maximize.top().second > heights[i]){
                    auto& [index , hig] = maximize.top();
                    area = max(area,(i - index)*hig);
                    saveIndex = index;
                    maximize.pop();
                }
                
                 maximize.push({saveIndex , heights[i]});
            
                
            }
            else
                maximize.push({i , heights[i]});
            
        }
        return area;
        
    }
};
