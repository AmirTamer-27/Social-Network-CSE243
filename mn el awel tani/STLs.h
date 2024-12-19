#ifndef STL
#define STL
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
            for (int pos = myFront; pos < myBack; pos++) { // Smaller than BUT NOT EQUAL!!!!!!!!!!!!!11!1!!!!!
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
            for (int pos = myFront; pos < myBack; pos++) { // Smaller than BUT NOT EQUAL!!!!!!!!!!!!!11!1!!!!!
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
        if (newBack != myFront) { // i.e., queue isn't full
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
        if (newFront != myBack) { // i.e., queue isn't full
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
/*template class Dequeue<int>;
template class Dequeue<User>;
template ostream& operator<<(ostream& out, const Dequeue<int>& aList);*/
typedef int KeyType;
typedef int ValueType;
// bool pairCompare(const pair<KeyType, ValueType>& a, const pair<KeyType, ValueType>& b) {
//     return a.first < b.first;
// }


const int DEFAULT_CAPACITY_map = 10000;
class CustomMap {
private:
    pair<KeyType, ValueType>* data;
    int myCapacity;
    int mySize;

public:
    CustomMap(int numElements = DEFAULT_CAPACITY) {
        myCapacity = numElements;
        data = new (nothrow) pair<KeyType, ValueType>[myCapacity];
        mySize = 0;

    }
    int size() {
        return mySize;
    }
    void insert(const KeyType& key, const ValueType& value) //value will be added to the initial value
    {
        sort(data, data + mySize );
        int l = 0, r = mySize - 1, m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (data[m].first < key)
            {
                l = m + 1;

            }
            else if (data[m].first > key)
                r = m - 1;
            else
            {
                data[m].second += value;
                return;
            }
        }

        if (myCapacity > mySize)
        {
            data[mySize].first = key;
            data[mySize].second = value;
            mySize++;
        }
    }
    bool contains(const KeyType& key) {
        sort(data, data + mySize );
        int l = 0, r = mySize - 1, m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (data[m].first < key)
            {
                l = m + 1;
            }
            else if (data[m].first > key)
                r = m - 1;
            else
                return true;
        }
        return false;
    }
    ValueType second(int i)
    {
        if (mySize > i)
        {
            return data[i].second;
        }
    }
    KeyType first(int i)
    {
        if (mySize > i)
        {
            return data[i].first;
        }

    }
    const ValueType& at(const KeyType& key) const {
        sort(data, data + mySize );
        int l = 0, r = mySize - 1, m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (data[m].first < key)
            {
                l = m + 1;
            }
            else if (data[m].first > key)
                r = m - 1;
            else
            {

                return data[m].second;
            }
        }

        cerr << "Key not found";

    }
    void display(ostream& out) const {
        if (mySize == 0) {
            cerr << "Map-empty!" << endl;
            return;
        }
        for (int i = 0; i < mySize; i++)
        {
            out << "key: " << data[i].first << " value: " << data[i].second << " ";
        }
        cout << endl;
    }
};
ostream& operator<< (ostream& out, const CustomMap& aList) {
    aList.display(out);
    return out;
}



template<typename type1, typename type2>
class Priority_Queue {
private:
    class Node {
    public:
        type1 value;
        type2 index;
        Node* next;

        Node(type1 item, type2 key) {
            value = item;
            index = key;
            next = 0;
        }

    };
    Node* mytop;
    int size;
public:
    Priority_Queue() {
        mytop = 0;
        size = 0;
    }
    ~Priority_Queue() {
        while (mytop != 0) {
            Priority_Queue<type1, type2>::Node* ptr = mytop;
            mytop = mytop->next;
            delete ptr;
        }
    }
    bool empty() const {
        return size == 0;
    }

    int get_size() const {
        return size;
    }
    void push(const type1& item, const type2& key) {

        Priority_Queue<type1, type2>::Node* ptr1 = mytop;
        Priority_Queue<type1, type2>::Node* ptr2 = new Node(item, key);

        if (empty() or item > mytop->value) {
            ptr2->next = mytop;
            mytop = ptr2;
            size++;
            return;
        }

        while (ptr1->next != 0 and ptr1->next->value >= item) {
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr1->next;
        ptr1->next = ptr2;

        size++;
        return;
    }
    void pop() {
        if (empty()) {
            cerr << "nothing to pop\n";
            return;
        }

        Priority_Queue<type1, type2>::Node* ptr = mytop;
        mytop = mytop->next;
        delete ptr;
        size--;
        return;
    }
    type1 top1() const {
        if (empty()) {
            cerr << "nothing in top\n";
            type1 garbage = NULL;
            return garbage;
        }
        return mytop->value;
    }
    type2 top2() {
        if (empty()) {
            cerr << "nothing in top\n";
            type2 garbage = NULL;
            return garbage;
        }
        return mytop->index;
    }


};
//template class Priority_Queue<int, int>;
//template class Priority_Queue<int, string>;

typedef int ElementType;

class LinkedList {
private:
    // Nested node class
    class Node {
    public:

        ElementType data;
        Node* next; // How does it refer to itself although it isn't created yet?

        Node() : next(0) {}
        Node(ElementType dataValue) : data(dataValue), next(0) {}
    };

    typedef Node* NodePointer;
    NodePointer first;
    int mySize;

public:
    LinkedList() : first(0), mySize(0) {}

    LinkedList(const LinkedList& origList) {
        if (mySize == 0) return;
        LinkedList::NodePointer origPtr, lastPtr;
        first = new Node(origList.first->data);  // copy first node
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
        LinkedList::NodePointer prev = first, ptr;
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
    const LinkedList& operator=(const LinkedList& rightSide) {
        mySize = rightSide.mySize;

        if (mySize == 0) {
            first = 0;
            return *this;
        }
        if (this != &rightSide)
        {
            this->~LinkedList();
            LinkedList::NodePointer origPtr, lastPtr;
            first = new Node(rightSide.first->data);  // copy first node
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
        LinkedList::NodePointer newPtr = new Node(dataVal), predPtr = first;
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
        LinkedList::NodePointer ptr,
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
        LinkedList::NodePointer tempP = first;
        for (loc = 0; loc < mySize; loc++)
            if (tempP->data == dataVal)
                return loc;
            else
                tempP = tempP->next;
        return -1;
    }
    void display(ostream& out) const {
        LinkedList::NodePointer ptr = first;
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

ostream& operator<<(ostream& out, const LinkedList& aList)
{
    aList.display(out);
    return out;
}
const int TableSize = 16383;
typedef int HashElement;
class HashTable {

private:

    class Node {
    public:
        HashElement value; // Student name
        Node* next;
        Node(HashElement value) {
            next = nullptr;
            this->value = value;
        }
    };

    int numberOfElements;
    Node** table;
    int hash(HashElement value) {
        return value % TableSize;
    }
public:
    HashTable() :numberOfElements(0) {
        table = new (nothrow) Node*[TableSize];
    }
    void insert(HashElement value) {
        int loc = hash(value);
        if (table[loc]->value == value) {
            cerr << "Item already exists";
            return;
        }
        if (table[loc] == nullptr) {
            table[loc] = new Node(value);
            numberOfElements++;
        }
        else {
            Node* ptr = table[loc];
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = new Node(value);
        }
    }

    void remove(HashElement value) {
        int loc = hash(value);
        if (table[loc]->value == value) {
            delete table[loc];
        }
        else {
            Node* pred;
            Node* ptr = table[loc];
            while (ptr != nullptr && ptr->value != value) {
                pred = ptr;
                ptr = ptr->next;
            }
            if (ptr == nullptr) {
                cout << "Item not found";
                return;
            }
            else {
                pred->next = ptr->next;
                delete ptr;

            }
        }
    }
    void getIndices(Dequeue<int>& requestingUsers) {
         int count = 1;
         short x;
         for (int i = 0; i < TableSize; i++) {
             if (table[i] == nullptr)
                 continue;
             count++;
             requestingUsers.push_back(table[i]->value);
             if (table[i]->next != nullptr) {
                 Node* ptr = table[i]->next;
                 while (ptr != nullptr) {
                     count++;
                     requestingUsers.push_back(ptr->value);
                     ptr = ptr->next;
                 }
             }
         }
     }
    bool found(HashElement value) {
        if (table[hash(value)] == nullptr)
            return false;
        Node* ptr = table[hash(value)];
        while (ptr != nullptr) {
            if (ptr->value == value)
                return true;
            ptr = ptr->next;
        }
        return false;
    }
};

#endif /* HTable_hpp */
