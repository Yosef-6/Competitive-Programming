class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>sim;
        int j = 0;
        unordered_map<int,bool>loc;
        while(pushed[j] != popped[0]){
        loc[pushed[j]] = true;
        sim.push(pushed[j]);
        j++;
        }
        j++;
        for(int i = 1; i<popped.size(); i++){
          
            if(loc.find(popped[i]) != loc.end()){
                if(sim.top() == popped[i])
                    sim.pop();
                else
                    return false;
            }
            else{
                   while( j < pushed.size() &&pushed[j] != popped[i]){
                   loc[pushed[j]] = true;
                   sim.push(pushed[j]);
                   j++;
                   }
                   j++;
                
                
            }
            
        }
        return true;
       
        
    }
};
