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
    //approach 2 using stack


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(!l1) return l2;
        if(!l2) return l1; 
        stack<ListNode *>st1;
        stack<ListNode *>st2;

        ListNode *curr=l1;
        while(curr)
        {
            st1.push(curr);
            curr=curr->next;
        }
        curr=l2;
        while(curr)
        {
            st2.push(curr);
            curr=curr->next;
        }

        ListNode *result=new ListNode(0);
        
        int carry=0;
        int sum=0;
        while(!st1.empty() || !st2.empty())
        {
            if(!st1.empty())
            {
               sum+=st1.top()->val;
               st1.pop();
            }
            if(!st2.empty())
            {
               sum+=st2.top()->val;
               st2.pop();
            }

            result->val=sum%10;
            carry=sum/10;

            ListNode *newNode=new ListNode(carry);
            newNode->next=result;
            result=newNode;

            sum=carry;            
        }
        return carry==0?result->next:result;
    }
};