/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    int maxZigZag= 0;
    
    int longestCompute(TreeNode* root , bool left){
            if(root == nullptr)
                 return 0;
      
           
           if(left) {
                int l =  longestCompute(root->left,true);  
                int r =  longestCompute(root->right,false) + 1;
                maxZigZag= std::max(std::max(l,r),maxZigZag);
                return r;
           }
           else {
                int l = longestCompute(root->left,true) + 1 ;
                int r = longestCompute(root->right,false);
                maxZigZag= std::max(std::max(l,r),maxZigZag);
                return l;
                 
           }
           
        
            
    }
    int longestZigZag(TreeNode* root) {
   
         
            longestCompute(root->left,true);
            longestCompute(root->right,false);
            
            return maxZigZag;
          
    }
};
