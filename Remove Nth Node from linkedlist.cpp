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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>ptr;
        ListNode * temp = head;

        while(temp){
            ptr.push_back(temp);
            temp = temp->next;
        }
        
        if(n == ptr.size()){
            temp =  head->next;
            delete head;
            head = temp;
        }
        else{
            ptr[ptr.size() - n - 1]->next = ptr[ptr.size()-n]->next;
            delete ptr[ptr.size()-n];
        }
        
        return head;
        
    }
};
