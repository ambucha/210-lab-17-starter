// COMSC-210 | Lab 17 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);

// deleteNodeAt(): deletes node at given position
// arguments: reference to a pointer of Node linked list
// returns: nothing
void deleteNodeAt(Node*&);

// insertNode(): inserts node after given after given position
// arguments: reference to a pointer of Node linked list, as well as the position to be deleted
// returns: nothing
void insertNode(Node*&);

// deleteList(): deletes the linked list
// arguments: reference to a pointer of Node linked list
// returns : nothing
void deleteList(Node*&);

// backAdd(): adds value to the tail of the linked list
// arguments: reference to a pointer of Node linked list, value
// returns: nothign
void backAdd(Node*&, int);

// backAdd(): adds value to the head of the linked list
// arguments: reference to a pointer of Node linked list, value
// returns: nothing
void frontAdd(Node*&, int);


int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);
    
    // Call functions
    deleteNodeAt(head);
    insertNode(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void deleteNodeAt(Node* & head){
    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // Am getting an error when trying to delete at position 1 or 0, need to make some protection
    if(entry <= 0){
        cout << "Invalid entry.\n\n";
        return;
    }

    if(entry == 1){
        Node * x = head;
        head = head->next;
        delete x;
        output(head);
        return;
    }

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}


void insertNode(Node*& head){
    // insert a node
    Node * current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node *prev = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}

void deleteList(Node*& head){
    // deleting the linked list
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}

