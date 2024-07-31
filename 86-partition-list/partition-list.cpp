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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;

        ListNode *small=new ListNode(0);
        ListNode *large=new ListNode(0);
        ListNode *smallP=small;
        ListNode *largeP=large;

        ListNode *curr=head;
        while(curr)
        {
            if(curr->val<x){
                smallP->next=curr;
                smallP=smallP->next;
            }
            else{
                largeP->next=curr;
                largeP=largeP->next;
            }
            curr=curr->next;   
        }
        
        smallP->next=large->next;
        largeP->next=nullptr;


        return small->next;     
    }

};