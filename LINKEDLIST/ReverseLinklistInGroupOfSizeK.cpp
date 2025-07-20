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





// Function to reverse nodes in groups of K
// Node *kReverse(Node *head, int k)
// {
//     // Initialize a temporary
//     // node to traverse the list
//     Node *temp = head;

//     // Initialize a pointer to track the
//     // ;ast node of the previous group
//     Node *prevLast = NULL;

//     // Traverse through the linked list
//     while (temp != NULL)
//     {
//         // Get the Kth node of the current group
//         Node *kThNode = getKthNode(temp, k);

//         // If the Kth node is NULL
//         // (not a complete group)
//         if (kThNode == NULL)
//         {
//             // If there was a previous group,
//             // link the last node to the current node
//             if (prevLast)
//             {
//                 prevLast->next = temp;
//             }

//             // Exit the loop
//             break;
//         }

//         // Store the next node
//         // after the Kth node
//         Node *nextNode = kThNode->next;

//         // Disconnect the Kth node
//         // to prepare for reversal
//         kThNode->next = NULL;

//         // Reverse the nodes from
//         // temp to the Kth node
//         reverseLinkedList(temp);

//         // Adjust the head if the reversal
//         // starts from the head
//         if (temp == head)
//         {
//             head = kThNode;
//         }
//         else
//         {
//             // Link the last node of the previous
//             // group to the reversed group
//             prevLast->next = kThNode;
//         }

//         // Update the pointer to the
//         // last node of the previous group
//         prevLast = temp;

//         // Move to the next group
//         temp = nextNode;
//     }

//     // Return the head of the
//     // modified linked list
//     return head;
// }

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