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
        if(head==nullptr || head->next==nullptr) return head;

        ListNode *nextHead=removeNodes(head->next);

        if(head->val < nextHead->val)
        {
            
            delete(head);
            return nextHead;
        }
        head->next=nextHead;
        return head;
    }
};