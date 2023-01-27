#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(NULL) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node* copyRandomList(Node* head) {
    map<Node*, Node*> m;
    int i=0;
    Node* ptr = head;
    while (ptr) {
        m[ptr] =new Node(ptr->val);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr) {
        m[ptr]->next = m[ptr->next];
        m[ptr]->random = m[ptr->random];
        ptr = ptr->next;
    }
    return m[head];
}

Node* oddEvenList(Node* head)
{
    Node* temp = head;
    vector<int> odd;
    vector<int> even;

    int cnt = 1;
    while(temp)
    {
        if(cnt%2 == 1)
        {
            odd.push_back(temp->val);
        }
        else
        {
            even.push_back(temp->val);
        }

        cnt++;
        temp = temp->next;
    }

    for(int i=0;i<even.size();i++)
    {
        odd.push_back(even[i]);
    }

    Node* res = new Node();
    temp = res;
    for(int i=0;i<odd.size();i++)
    {
        temp->next = new Node(odd[i]);
        temp = temp->next;
    }

    return res->next;
}

int main(){
    ListNode* head1 = new ListNode(10);
    ListNode* head2 = new ListNode(20);
    return 0;
}