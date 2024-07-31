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
    // Approach 2
    
    void reorderList(ListNode* head) {
        stack<ListNode*>st;

        ListNode *curr=head;
        while(curr)
        {
            st.push(curr);
            curr=curr->next;
        }

        int k=st.size()/2;

        curr=head;
        while(k>0)
        {
            ListNode *top=st.top();st.pop();
            ListNode *tempcurr=curr->next;
            curr->next=top;
            top->next=tempcurr;

            curr=tempcurr;
            k--;
        }
        curr->next=nullptr;

        
    }
};