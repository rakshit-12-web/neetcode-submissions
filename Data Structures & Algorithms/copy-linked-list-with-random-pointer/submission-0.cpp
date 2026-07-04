/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        Node* curr=head;
        Node* prev=NULL;
        Node* newHead=NULL;
        while(curr){
            Node* temp=new Node(curr->val);
            
            m[curr]=temp;
            if(prev==NULL){
                prev=temp;
                newHead=prev;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
            curr=curr->next;
        }
        curr=head;
        Node* newCurr=newHead;
        while(curr){
            if(curr->random==NULL){
                    newCurr->random=NULL;
            }
            else{
        newCurr->random=m[curr->random];
            }
        curr=curr->next;
        newCurr=newCurr->next;
        }
        return newHead;
        
    }
};
