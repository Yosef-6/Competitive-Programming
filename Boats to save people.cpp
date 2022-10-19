class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats  = 0;
        std::sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        while(i<=j){
            if(i == j){
                boats++;
                break;
            }
           else if(people[i] + people[j] <= limit){
                i++;
                j--;
                boats++;
            }
            else{
                j--;
                boats++;
            }
                
        }
        return boats;
    }
};
