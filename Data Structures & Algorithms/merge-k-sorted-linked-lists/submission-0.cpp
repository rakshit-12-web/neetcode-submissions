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

class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // Min Heap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& list) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i=0;i<list.size();i++){
            if(list[i]!=NULL){
            ListNode*temp=list[i];
            pq.push(temp);
            }
        }
        ListNode*dummy=new ListNode(-1);
            ListNode* curr=dummy;
        while(!pq.empty()){
ListNode*temp=pq.top();
pq.pop();
curr->next=temp;
curr=curr->next;
if(temp->next!=NULL){
pq.push(temp->next);
}
        }
        return dummy->next;
    }
};
