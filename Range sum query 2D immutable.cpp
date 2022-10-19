class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix):m_row(matrix.size()),m_col(matrix[0].size()),m_oneDim(),m_twoDim() {
     for(auto& elm : matrix){
         
        for(int i = 1; i<m_col; i++)
            elm[i] = elm[i] + elm[i-1];
         
      }
      m_oneDim = move(matrix);
      m_twoDim = m_oneDim;
      
      for(int i = 0; i<m_col; i++){
          for(int j = 1; j<m_row;  j++)
              m_twoDim[j][i] = m_twoDim[j][i] + m_twoDim[j-1][i];
      }
     
      
   }
    
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        if(row1 == row2 && col1 == col2){
            if(col1 == 0)
                return m_oneDim[row1][col1];
            else
                return m_oneDim[row1][col1] - m_oneDim[row1][col1-1];
        }
        else if(row1 == row2 && col1 != col2){
              if(col1 == 0 )
              return m_oneDim[row1][col2];
              else
              return m_oneDim[row1][col2] - m_oneDim[row1][col1-1];
        }
        else{
              if(row1 == 0 && col1 ==0)
              return m_twoDim[row2][col2];
              else if(row1 == 0)
              return m_twoDim[row2][col2] - m_twoDim[row2][col1-1];
              else if (col1 == 0)
              return m_twoDim[row2][col2] - m_twoDim[row1-1][col2];
              else
              return m_twoDim[row2][col2] - (m_twoDim[row1-1][col2]  + (m_twoDim[row2][col1-1] - m_twoDim[row1-1][col1-1]) );
            
        }
            
    }
    vector<vector<int>>m_oneDim;
    vector<vector<int>>m_twoDim;
    int m_row;
    int m_col;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
