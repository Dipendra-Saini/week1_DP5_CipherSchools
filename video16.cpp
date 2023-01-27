#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates_sorted(ListNode* head) {
    ListNode *ans = new ListNode(0);
    ListNode *curr = ans;

    while(head) {
        while(head->next && head -> val == head -> next -> val) head = head -> next;
        curr -> next = head;
        curr = head;
        head = head -> next;
    }
    return ans->next;
}

void removeDuplicates_unsorted(struct ListNode* start)
{
    struct ListNode *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->val == ptr2->next->val) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

ListNode* rotateRight(ListNode* head, int k) {
    if(!head)
        return NULL;
    int n = 1;
    ListNode* tail = head;
    while(tail->next){
        n++;
        tail = tail->next;
    }
    tail->next = head;
    int sz = n - k % n;
    for(int i = 0; i < sz; i++){
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* res = dummy;
    int carry = 0;

    while(l1!=NULL || l2!=NULL){
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int result = x+y + carry;
        carry = result/10;
        res->next = new ListNode(result%10);

        res = res->next;
        if(l1!=NULL) l1 = l1->next;
        if(l2!=NULL) l2 = l2->next;
    }
    if (carry > 0) {
        res->next = new ListNode(carry);
    }
    return dummy->next;
}

int main(){
    ListNode* head1 = new ListNode(10);
    ListNode* head2 = new ListNode(20);
    return 0;
}
