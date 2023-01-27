#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
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

ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    if(list1->val<list2->val){
        list1->next = mergeTwoLists(list1->next,list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1,list2->next);
        return list2;
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* mergelist=NULL;
    int len = lists.size();
    for(int i=0;i<len;i++){
        mergelist = mergeTwoLists(mergelist,lists[i]);
    }
    return mergelist;
}

int main(){

    ListNode* list1 = new ListNode(10);
    ListNode* list2 = new ListNode(20);
    for(int i = 20;i<=50;i+=10){
        insetAtEnd(list1,i);
    }
    for(int i = 60;i<=100;i+=10){
        insetAtEnd(list2,i);
    }
    print(list1);
    print(list2);

    return 0;
}