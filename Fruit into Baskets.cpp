class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int picked = 0;
    int bags   = 0;
    vector<int>window;
    for(int i =0 ;i<fruits.size();i++ ){
        auto iter = find(window.begin(),window.end(),fruits[i]);
        
        if(iter == window.end() && bags < 2)
            bags++;
        else if(iter == window.end() && bags == 2){
            int index = window.size() - 1;
            int val   = window.back();
            while(index >= 0 && window[index] == val)
                index--;
            window.erase(window.begin(),window.begin() + index + 1);
               
        }
        
        
        window.push_back(fruits[i]);
        picked = max((int)window.size(),picked);
        
        
    }
    return picked;
    
    
    }
};
