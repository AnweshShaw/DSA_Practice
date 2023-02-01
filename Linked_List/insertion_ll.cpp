#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val) // Initialising the head pointer of the linked list
    {
        data = val;
        next = NULL;
    }
};

// Insertion at beginning of Linked List
void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

// Insertion at end of Linked List
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    display(head);
    insertAthead(head, 40);
    display(head);
    cout << search(head, 10) << endl;
}
