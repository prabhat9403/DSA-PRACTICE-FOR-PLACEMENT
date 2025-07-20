#include <bits/stdc++.h>
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
Node *reverseLinkedList(Node *Head)
{
    Node *temp = Head;
    Node *prev = nullptr;
    while (temp)
    {
        Node *nex = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nex;
    }
    return prev;
}
Node *getKthNode(Node *t, int k)
{

    k -= 1;
    while (t && k > 0)
    {
        k--;
        t = t->next;
    }
    return t;
}
Node*kReverse(Node*head,int k){

    Node*temp=head;
    Node*prevLast=nullptr;

    while(temp){
        Node*kthNode=getKthNode(temp,k);
        if(kthNode==nullptr){
            if(prevLast){
                prevLast->next=temp;
            }
            break;
        }
        Node*nex=kthNode->next;
        kthNode->next=nullptr;
        reverseLinkedList(temp);
        if(temp==head){
            head=kthNode;
        }
        else{
            prevLast->next=kthNode;
        }
        prevLast=temp;
        temp=nex;

    }
    return head;

}







int main()
{
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = kReverse(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}