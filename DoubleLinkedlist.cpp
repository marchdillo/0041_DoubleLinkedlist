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
        // insert in between node
        // step 8: locate potition for insertion
        node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }
        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll number not allowed" << endl;
            return;
        }
        // step 9: insert between current and current next
        newNode->next = current->next; // step 9a
        newNode->prev = current;       // step 9b

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c

        current->next = newNode; // step 9d: current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nlist is empty" << endl;
        }

        cout << "\nenter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        node *current = START;

        // step 1; traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "record not found" << endl;
            return;
        }

        // step 2: if node is at the beginning
        if (current == START)
        {
            START = current->next; // step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; // step 2b: START.prev = NULL
        }
        else
        {
            // step 3: link previous node to next of current
            current->next->prev = current->next;

            // step 4: if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }
        // step 5: delete the node
        delete current;
        cout << "record with roll number " << rollNo << "deleted" << endl;
    }
    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nlist is empty" << endl;
            return;
        }

        // step 1: mark first node as currentNode
        node *currentNode = START;

        // step 2: repeat untill currentNode == NULL
        cout << "\nrecords in ascending order of roll number are :\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // step 3: move to next node
            currentNode = currentNode->next;
            i++;
        }
    }
    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nlist is empty" << endl;
            return;
        }

        // step 1: move to last node
        node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        // step 2: traverse backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // step 3: move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }
    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        node *current = START;

        // step 1: traverse to find matching rull number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        // step 2: output result
        if (current == NULL)
        {
            cout << "record not found\n";
        }
        else
        {
            cout << "record found\n";
            cout << "roll number: " << current->noMhs << endl;
        }
    }
    int main()
    {
        doubleLinkedList list;
        char choice;

        do
        {
            cout << "\nMenu: \n";
            cout << "1. add record\n";
            cout << "2. delete record\n";
            cout << "3. view ascending\n";
            cout << "4. view descending\n";
            cout << "5. search record\n";
            cout << "6. exit\n";
            cout << "enter your choice: ";

            cin >> choice;

            switch (choice)
            {
            case '1':
                list.addNode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.revtraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "invalid option\n";
            }
            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();
            cout << endl;
            system("clear");
        } while (choice != '6');
    }
};