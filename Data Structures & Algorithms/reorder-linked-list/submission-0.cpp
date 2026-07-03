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
    void reorderList(ListNode* head) {
        ListNode*curr=head;
        ListNode*temp=head;
        vector<int>arr;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        int s=0;
        int e=arr.size()-1;
        while(s<e){
            temp->val=arr[s];
            temp=temp->next;
            temp->val=arr[e];
            temp=temp->next;
            s++;
            e--;
        }
        if(s==e){
            temp->val=arr[s];
        }
    }
};
