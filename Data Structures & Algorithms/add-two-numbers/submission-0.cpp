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

    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {

        ListNode* head=new ListNode(-1);
        ListNode* curr=head;

        int carry=0;
        while(t1&&t2){
            int sum=(t1->val)+(t2->val)+carry;
            int value=sum%10;
            carry=sum/10;
            ListNode* temp=new ListNode(value);
            curr->next=temp;
            curr=temp;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1){
             int sum=(t1->val)+carry;
            int value=sum%10;
            carry=sum/10;
            ListNode* temp=new ListNode(value);
            curr->next=temp;
            curr=temp;
                 t1=t1->next;
        
        }
         while(t2){
             int sum=(t2->val)+carry;
            int value=sum%10;
            carry=sum/10;
            ListNode* temp=new ListNode(value);
            curr->next=temp;
            curr=temp;
                
            t2=t2->next;
        }
        if(carry){
             ListNode* temp=new ListNode(carry);
            curr->next=temp;
            curr=temp;
        }
    return head->next;
    }
};
