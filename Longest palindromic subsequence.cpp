class Solution {
public:
    int longestPalindromeSubseq(string s) {
        std::string cp = s;
        std::reverse(cp.begin(),cp.end());
        size_t rows = cp.size() + 1;
        size_t cols = s.size() + 1;
        int array[rows][cols];
        for(size_t i = 0; i < rows; i++)
            for(size_t j = 0; j< cols; j++)
                array[i][j] = 0;
        
         for(int i = rows-2; i >= 0; i--)
            for(int j = cols-2; j>= 0; j--){
                if(cp[i]==s[j]) 
                    array[i][j] = 1 + array[i+1][j+1];
                else
                    array[i][j] = std::max(array[i+1][j],array[i][j+1]);
                
        }
        
        return array[0][0];
       
        
    }
};
