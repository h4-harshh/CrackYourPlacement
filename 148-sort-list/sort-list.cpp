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

 //approach 1->using array
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *curr=head;

        vector<int>arr;
        while(curr)
        {
            arr.push_back(curr->val);
            curr=curr->next;
        }
        sort(arr.begin(),arr.end());

        int i=0;
        curr=head;
        while(curr)
        {
            curr->val=arr[i];
            curr=curr->next;
            i++;
        }
        return head;
    }
};