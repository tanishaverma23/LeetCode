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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp = head->next;
        int sum = 0;
        while (temp != NULL) {

            sum += temp->val;

            if (temp->val == 0) {
                ListNode* newNode = new ListNode(sum);
                curr->next = newNode;
                curr=curr->next;
                sum = 0;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};