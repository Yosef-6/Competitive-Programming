class Solution {
public:
    int leastInterval(const std::vector<char>& tasks, int n) {

    if(tasks.size() == 0)
        return 0;
    std::priority_queue<int> maxHeap; //default maxHeap
    std::queue<std::pair<int,int>>instructionQueue;
    std::unordered_map<char,int>insKeys;

    for(char i : tasks)
        insKeys[i]+=1;
    for(const auto & pair : insKeys)
    maxHeap.push(pair.second);

    size_t time = 1; //ya i start with one

    while(!maxHeap.empty() || !instructionQueue.empty()){


     if(!instructionQueue.empty()){
         const auto& pair = instructionQueue.front();
         if(pair.second == time){
            maxHeap.push(pair.first);
            instructionQueue.pop();
         }
    }

    if(!maxHeap.empty()){
        int elm =  maxHeap.top();
        if(elm - 1  != 0)
        instructionQueue.push(std::make_pair(elm-1,time + n + 1));
        maxHeap.pop();
    }



        time++;
    }

   return  --time;
}
};
