#ifndef DEQUEUE
#define DEQUEUE
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
// #include "User.h"
using namespace std;
const int DEFAULT_CAPACITY = 10000;
template <typename QueueElement>
class Dequeue {

public:
    Dequeue(int numElements = DEFAULT_CAPACITY) : myFront(0), myBack(0), mySize(0) {
        if (numElements <= 0) {
            cerr << "Error: Negative or zero capacity required -- terminating execution\n";
            exit(1);
        }
        myCapacity = numElements;
        myArray = new (nothrow) QueueElement[myCapacity];

        if (myArray == 0) {
            cerr << "Error: Inadequate memory to allocate queue -- terminating execution\n";
            exit(1);
        }
    }
    Dequeue(const Dequeue& original) : myFront(original.myFront), myBack(original.myBack), myCapacity(original.myCapacity), mySize(original.mySize) {
        myArray = new (nothrow) QueueElement[myCapacity];
        if (myArray == 0) {
            cerr << "Error: Inadequate memory to allocate queue -- terminating execution\n";
            exit(1);
        }
        else {
            for (int pos = myFront; pos < myBack; pos++) {
                myArray[pos] = original.myArray[pos];
            }
        }
    }
    ~Dequeue() {
        delete[] myArray;
    }
    const Dequeue& operator= (const Dequeue& rhs) {
        if (this != &rhs) {
            if (myCapacity != rhs.myCapacity) {
                this->~Dequeue();
                myCapacity = rhs.myCapacity;
                myArray = new(nothrow) QueueElement[myCapacity];
                if (myArray == 0) {
                    cerr << "Error: Inadequate memory to allocate stack -- terminating execution\n";
                    exit(1);
                }
            }
            myFront = rhs.myFront;
            myBack = rhs.myBack;
            for (int pos = myFront; pos < myBack; pos++) {
                myArray[pos] = rhs.myArray[pos];
            }
        }
        mySize = rhs.mySize;
        return *this;
    }
    bool empty() const {
        return myFront == myBack;
    }
    void push_back(const QueueElement& value) {
        int newBack = (myBack + 1) % myCapacity;
        if (newBack != myFront) {
            myArray[myBack] = value;
            myBack = newBack;
            mySize++;
        }
        else {
            cerr << "Dequeue-full! " << endl;
            exit(1);
        }
    }
    int size() {
        return mySize;
    }
    void display(ostream& out) const {
        if (empty()) {
            cerr << "Dequeue-empty!" << endl;
            return;
        }
        for (int i = myFront; i != myBack; i = (i + 1) % myCapacity) {
            out << myArray[i] << ' ';
        }
        cout << endl;
    }
    QueueElement front() const {
        if (!empty())
            return myArray[myFront];
        /* else {
             cerr << "Dequeue Empty -- Returning garbage." << endl;
             QueueElement garbage;
             return garbage;
         }*/
    }
    QueueElement back() const {
        if (!empty())
            return myArray[myBack - 1];
        /** else {
             cerr << "Dequeue Empty -- Returning garbage." << endl;
             QueueElement garbage;
             return garbage;
         }*/
    }
    void pop_front() {
        if (!empty())
        {
            myFront = (myFront + 1) % myCapacity;
            mySize--;
        }
        else {
            cerr << "Dequeue Empty!" << endl;
        }
    }
    void pop_back() {
        if (!empty())
        {
            if ((myBack - 1) < 0)
                myBack = ((myBack - 1) + myCapacity) % myCapacity;
            else
                myBack = (myBack - 1) % myCapacity;
            mySize--;
        }
        else {
            cerr << "Dequeue Empty!" << endl;
        }
    }
    void push_front(const QueueElement& value) {
        int newFront;
        if ((myFront - 1) < 0)
            newFront = ((myFront - 1) + myCapacity) % myCapacity;
        else
            newFront = (myFront - 1) % myCapacity;
        if (newFront != myBack) {
            myFront = newFront;
            myArray[myFront] = value;
            mySize++;

        }
        else {
            cerr << "Dequeue-full! " << endl;
            exit(1);
        }
    }
    QueueElement& get(int i)
    {
        int index = (myFront + i) % myCapacity;
        if (index >= myFront and index < myBack)
            return myArray[(myFront + i) % myCapacity];
        else {
            cerr << "index out of bound" << endl;
            return myArray[(myFront + i) % myCapacity];
        }

    }
    int find(const QueueElement& value)
    {
        int i = myFront;
        while (i != myBack)
        {
            if (myArray[i] == value)
                return i;
            else
                i = (i + 1) % myCapacity;

        }
        return -1;
    }
    int getCapacity() {
        return myCapacity;
    }

private:
    QueueElement* myArray;
    int mySize;
    int myFront, myBack, myCapacity;
};
template <typename QueueElement>
ostream& operator<< (ostream& out, const Dequeue<QueueElement>& aList) {
    aList.display(out);
    return out;
}
#endif