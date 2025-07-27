#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int d)
    {
        data = d;
        next = nullptr;
        child = nullptr;
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
// First Flatten
void flattenList(Node *head)
{
    Node *temp = head;
    while (temp)
    {

        Node *Next = temp->next;
        temp->next = nullptr;
        Node *prev = nullptr;
        while (temp->child)
        {
            temp->next = temp->child;
            temp->child = nullptr;
            temp = temp->next;
        }
        temp->next = Next;
        temp = Next;
    }
}

// Now sorting using merge sort
Node *midNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge(Node*list1,Node*list2){
     Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

   
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

 
    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    
    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

Node *sortLL(Node *head)
{
    if (head)
    {
        return nullptr;
    }
    Node *mid = midNode(head);
    Node *list1 = sortLL(head);
    Node *list2 = sortLL(mid->next);
    merge(list1, list2);
    return merge(list1, list2);
}
int main()
{
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);
    printLinkedList(head);
    flattenList(head);
    head=sortLL(head);
    printLinkedList(head);

    return 0;
}