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
    ListNode* removeNodes(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        stack<ListNode *>st;
        ListNode *curr=head;
        while(curr)
        {
            st.push(curr);
            curr=curr->next;
        }

        curr=st.top();
        st.pop();
        head=new ListNode(curr->val);
        int max=curr->val;
        while(!st.empty())
        {
            curr=st.top();
            st.pop();

            if(curr->val < max)
            {
                continue;
            }
            else{
                ListNode *newNode=new ListNode(curr->val);
                newNode->next=head;
                head=newNode;
                max=curr->val;
            }
        }
        return head;
    }
};