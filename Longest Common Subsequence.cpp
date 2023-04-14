class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t rows = text2.size() + 1;
        size_t cols = text1.size() + 1;
        int array[rows][cols];
        for(size_t i = 0; i < rows; i++)
            for(size_t j = 0; j< cols; j++)
                array[i][j] = 0;
        
         for(int i = rows-2; i >= 0; i--)
            for(int j = cols-2; j>= 0; j--){
                if(text2[i]==text1[j]) 
                    array[i][j] = 1 + array[i+1][j+1];
                else
                    array[i][j] = std::max(array[i+1][j],array[i][j+1]);
                
        }
        
        return array[0][0];
    }
};
