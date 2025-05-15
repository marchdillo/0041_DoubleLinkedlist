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

        // step 3: insert at beginning in list empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nduplicate number not allowed" << endl;
                return;
            }
            // step 4: newNode.next = START
            newNode->next = START;

            // step 5: start.prev = newNode (if exists)
            if (START != NULL)
                START->prev = newNode;

            // step 6: newNode.prev = NULL
            newNode->prev = NULL;

            // step 7: start = newNode
            START = newNode;
            return;
        }
    }
};