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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;

        ListNode *head=new ListNode(0);
        ListNode *dummy=head;
        while(l1 && l2)
        {
            int curr_sum=l1->val+l2->val+carry;
            int rem=curr_sum%10;
            ListNode *newNode=new ListNode(rem);
            dummy->next=newNode;
            dummy=dummy->next;
            carry=curr_sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l2!=nullptr)
        {
            int curr_sum=l2->val+carry;
            int rem=curr_sum%10;
            ListNode *newNode=new ListNode(rem);
            dummy->next=newNode;
            dummy=dummy->next;
            carry=curr_sum/10;
            l2=l2->next;
        }
        while(l1!=nullptr)
        {
            int curr_sum=l1->val+carry;
            int rem=curr_sum%10;
            ListNode *newNode=new ListNode(rem);
            dummy->next=newNode;
            dummy=dummy->next;
            carry=curr_sum/10;
            l1=l1->next;
        }
        if(carry!=0)
        {
            ListNode *new_node=new ListNode(carry);
            dummy->next=new_node;
        }
        return head->next;
    }
};