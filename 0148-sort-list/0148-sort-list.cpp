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
    ListNode* findMiddle(ListNode* head){
         ListNode* slow=head;
          ListNode* fast = head->next;
          while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
          }
          return slow;
    }
public:
    ListNode* merge(ListNode* head1 , ListNode* head2){
    ListNode* DummyNode= new  ListNode(-1);
    ListNode*temp=DummyNode;
    while(head1!=NULL && head2 !=NULL){
        if(head1->val < head2->val){
            temp->next=head1;
            temp=head1;
            head1=head1->next;
        }
        else{
            temp->next=head2;
            temp=head2;
            head2=head2->next;

        }

    }
    if(head1){
        temp->next=head1;
    }
    if(head2){
        temp->next=head2;
    }

    return DummyNode->next;
     } 
public:
    ListNode* sortList(ListNode* head) {
   if(head== NULL || head->next == NULL)return head;
   ListNode* middle=findMiddle(head);
   ListNode* lefthead= head;
   ListNode* righthead = middle->next;
   middle->next=NULL;

   lefthead= sortList(lefthead);
   righthead = sortList(righthead);
   return merge(lefthead,righthead);
        
    }
};
