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
    //approach 1 by reversing linekd list
    
    ListNode *reverse(ListNode *head)
    {
        if(!head) return head;

        ListNode *curr=head;
        ListNode *prev=nullptr;
        while(curr)
        {
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(!l1) return l2;
        if(!l2) return l1; 
        l1=reverse(l1);
        l2=reverse(l2);

        ListNode *result=new ListNode(0);
        
        int carry=0;
        int sum=0;
        while(l1 || l2)
        {
            if(l1!=nullptr)
            {
               sum+=l1->val;
               l1=l1->next;
            }
            if(l2!=nullptr)
            {
               sum+=l2->val;
               l2=l2->next;
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