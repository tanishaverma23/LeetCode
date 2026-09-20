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
    ListNode* Reverse(ListNode* head){
        ListNode* curr=head;
        ListNode*prev=NULL;
        while(curr!=NULL){
            ListNode* next=curr->next;

            curr->next=prev;

            prev=curr;
            curr=next;
        }
        return prev;
    }

public:
    int pairSum(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        
        int n=len/2;
        ListNode* last=head;
        while(n!=0){
            n--;
            last=last->next;

        }

        ListNode* secondhalf=last->next;
        last->next=NULL;

        ListNode* temp2=Reverse(secondhalf);
        ListNode* temp1=head;
        int maxi=INT_MIN;
        while(temp1!=NULL){
            maxi=max(maxi, temp1->val+temp2->val);

            temp1=temp1->next;
            temp2=temp2->next;
        }
        return maxi;
    }
};