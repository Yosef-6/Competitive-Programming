class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
     if(position.size() == 1)
         return 1;
     int fleet = position.size(); // sze of total fleet which could be all the number of cars in the worst case
     vector<pair<int,int>> loc;
     for(int i = 0; i<position.size();i++)
        loc.emplace_back(position[i],speed[i]); 
     sort(loc.begin(),loc.end(),[](const auto& p1 , const auto& p2){
         return p1.first < p2.first;
     });
     float leastTime = (target - loc.back().first)/(float)loc.back().second;
     for(int i = loc.size() - 2; i >= 0 ; i--){//u can sort it in the reverse order or use rbegin and rend reverse iterators
             if( (target -  loc[i].first )/(float)loc[i].second   <=  leastTime)
             fleet--;
         else
             leastTime = (target -  loc[i].first )/(float)loc[i].second;
     
      }
     
      return fleet;
        
    }
};
