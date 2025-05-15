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
};