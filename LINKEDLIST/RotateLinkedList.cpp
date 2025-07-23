#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int v)
    {
        data = v;
        next = nullptr;
    }
};
void printLinkedList(Node *head)
{
    Node *t = head;
    while (t)
    {
        cout << t->data << "->";
        t = t->next;
    }
    cout << "x" << endl;
}

Node* rotateLL(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

   
    int n = 0;
    Node* curr = head;
    while (curr) {
        n++;
        curr = curr->next;
    }

  
    k = k % n;
    if (k == 0) return head;

  
    int skip = n - k;
    Node* temp = head;
    Node* prev = nullptr;
    while (skip--) {
        prev = temp;
        temp = temp->next;
    }

   
    prev->next = nullptr;
    Node* newHead = temp;

    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
}

int main(){
    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    printLinkedList(head);
    head=rotateLL(head,12);
    printLinkedList(head);

    return 0;
}