#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
    node *prev;
};

class doubleLinkedList
{
private:
    node *START;

public:
    doubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student";
        cin >> nim;

        // step 1: alocate memory for new node
        node *newNode = new node();

        // step 2: assign value to the data fields
        newNode->noMhs = nim;
    }
};