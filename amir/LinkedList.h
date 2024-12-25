#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

template<typename ElementType>
class LinkedList {
private:

    class Node {
    public:

        ElementType data;
        Node* next;

        Node() : next(0) {}
        Node(ElementType dataValue) : data(dataValue), next(0) {}
    };

    typedef Node* NodePointer;
    NodePointer first;
    int mySize;

public:
    LinkedList() : first(0), mySize(0) {}

    LinkedList(const LinkedList<int>& origList) {
        if (mySize == 0) return;
        NodePointer origPtr, lastPtr;
        first = new Node(origList.first->data);
        lastPtr = first;
        origPtr = origList.first->next;
        while (origPtr != 0)
        {


            lastPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            lastPtr = lastPtr->next;
        }
    }
    ~LinkedList() {
        NodePointer prev = first, ptr;
        while (prev != 0)
        {
            ptr = prev->next;
            delete prev;
            prev = ptr;
        }
    }
    void reverse() {
        NodePointer ptr = first, nptr = first->next;
        while (ptr != 0)
        {
            NodePointer sptr = nptr->next;
            sptr = ptr;
            ptr = nptr->next;
            nptr->next = ptr;
            sptr->next = nptr;
            ptr = ptr->next;
            nptr = nptr->next;
            sptr = sptr->next;
        }
    }
    const LinkedList& operator=(const LinkedList<int>& rightSide) {
        mySize = rightSide.mySize;

        if (mySize == 0) {
            first = 0;
            return *this;
        }
        if (this != &rightSide)
        {
            this->~LinkedList<int>();
            NodePointer origPtr, lastPtr;
            first = new Node(rightSide.first->data);
            lastPtr = first;
            origPtr = rightSide.first->next;

            while (origPtr != 0)
            {
                lastPtr->next = new Node(origPtr->data);
                origPtr = origPtr->next;
                lastPtr = lastPtr->next;
            }
        }
        return *this;
    }

    bool empty() {
        return mySize == 0;
    }
    void insert(ElementType dataVal, int index) {
        if (index < 0 || index > mySize)
        {
            cerr << "Illegal location to insert -- " << index << endl;
            return;
        }

        mySize++;
        NodePointer newPtr = new Node(dataVal), predPtr = first;
        if (index == 0)
        {
            newPtr->next = first;
            first = newPtr;
        }
        else {
            for (int i = 1; i < index; i++)
                predPtr = predPtr->next;
            newPtr->next = predPtr->next;
            predPtr->next = newPtr;
        }
    }
    void erase(int index) {
        if (index < 0 || index >= mySize)
        {
            cerr << "Illegal location to delete -- " << index << endl;
            return;
        }
        mySize--;
        NodePointer ptr,
            predPtr = first;
        if (index == 0)
        {
            ptr = first;
            first = ptr->next;
            delete ptr;
        }
        else {
            for (int i = 1; i < index; i++)
                predPtr = predPtr->next;
            ptr = predPtr->next;
            predPtr->next = ptr->next;
            delete ptr;
        }
    }
    int size() {
        return mySize;
    }
    int search(ElementType dataVal) {
        int loc;
        NodePointer tempP = first;
        for (loc = 0; loc < mySize; loc++)
            if (tempP->data == dataVal)
                return loc;
            else
                tempP = tempP->next;
        return -1;
    }
    void display(ostream& out) const {
        NodePointer ptr = first;
        while (ptr != 0)
        {
            out << ptr->data << "  ";
            ptr = ptr->next;
        }
    }
    NodePointer begin()
    {
        return first;
    }
};

ostream& operator<<(ostream& out, const LinkedList<int>& aList)
{
    aList.display(out);
    return out;
}

#endif
