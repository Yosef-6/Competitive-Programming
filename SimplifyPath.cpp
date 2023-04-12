
// yes C++ does not have a string split function  
class Solution {
public:
    string simplifyPath(string path) {
        
        std::vector<std::string> output;
         
        std::stringstream ss;
        size_t i = 1; 
        while(i < path.size() || ss.str().size() != 0 ){
          
            if(path[i] != '/')
            while(i <  path.size() && path[i] != '/'){
                ss<<path[i];
                i++;
    
            }
                std::string tempBuffer = ss.str();
                if(tempBuffer.size() != 0){
                    if(tempBuffer == ".."){
                        if(output.size() != 0)
                        output.pop_back();
                    }
                    else if(tempBuffer != "."){
                        output.push_back(tempBuffer);
                       
                    }
                     ss.str("");
                }
                i++;
            
             
        }
        
        ss.str("");
        
        for(auto & dir : output){
            ss<<"/"<<dir;
        }
        
        if(output.size() == 0)
        ss<<"/";
        
        return  ss.str();
        
     }
        
        
};
