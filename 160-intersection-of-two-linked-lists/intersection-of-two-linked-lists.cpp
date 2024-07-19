/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findlength(ListNode *head)
    {
        int count=1;

        ListNode *curr=head;

        while(curr!=nullptr)
        {
            count++;
            curr=curr->next;
        }
        return count;
    }

    ListNode *getIntersection(int x,ListNode *headA,ListNode *headB)
    {
        while(x--)
        {
            headA=headA->next;
        }
        if(headA==headB) return headA;
        while(headA && headB)
        {
            if(headA->next==headB->next)
            {
                return headA->next;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
       if(head1==head2) return head1;
        
        int count1=findlength(head1);
        int count2=findlength(head2);

        if(count1>count2)
        {
            int d=count1-count2;
            return getIntersection(d,head1,head2);
        }
        else{
            int d=count2-count1;
            return getIntersection(d,head2,head1);
        }

        return nullptr;
    }
};