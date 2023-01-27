#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insetAtEnd(ListNode* &head,int val){
    ListNode* value = new ListNode(val);
    if(head==NULL){
        head->next = value;
        return;
    }
    ListNode* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = value;
//    value->next = NULL;
}

void print(ListNode* head){
    ListNode* temp = head;
    while(head!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* reverseList(ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;

        prev=curr;
        curr=next;
    }
    return prev;

}

ListNode* reverseKNodesLList(ListNode* head,int k){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;
    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;

        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
        head->next = reverseKNodesLList(next,k);
    return prev;
}

int main(){

    ListNode* head = new ListNode(10);
    for(int i = 20;i<=50;i+=10){
        insetAtEnd(head,i);
    }
    print(head);
    ListNode* newhead = reverseList(head);
    print(newhead);

    ListNode* newhead2 = reverseKNodesLList(head,2);
    print(newhead2);


    return 0;
}