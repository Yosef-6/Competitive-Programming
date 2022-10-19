/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Node = head;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        unordered_map<int,int> myMap;
        while(temp){
            myMap[temp->val]+=1;
            temp = temp->next;
        }
        while(Node){
            
            if(myMap[Node->val] != 1){
            
                while(Node && myMap[Node->val] != 1){
                    ListNode* node = Node->next;
                    delete Node;
                    Node = node;
                }
                if(prev == nullptr)
                    head = Node;
                else
                    prev->next = Node;
                    
                
            }
            prev = Node;
            Node = Node == nullptr ?  Node : Node->next;

        }
        return head;
        
        
    }
};
