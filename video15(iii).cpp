#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    if(head == NULL){
        return false;
    }
    while(fast!=NULL && fast->next!=NULL){



        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            return true;
            break;
        }

    }
    return false;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;
    while(ptr1 != ptr2){
        if(ptr1 == NULL){
            ptr1 = headB;
        }
        else{
            ptr1 = ptr1 -> next;
        }
        if(ptr2 == NULL){
            ptr2 = headA;
        }
        else{
            ptr2 = ptr2 -> next;
        }
    }
    return ptr1;
}

int main(){
    ListNode* head1 = new ListNode(10);
    ListNode* head2 = new ListNode(20);
    return 0;
}