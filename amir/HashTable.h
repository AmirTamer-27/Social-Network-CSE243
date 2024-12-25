#ifndef HASHTABLE
#define HASHTABLE
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "Dequeue.h"
using namespace std;
const int TableSize = 16383;
template<typename HashElement>

class HashTable {

private:

    class Node {
    public:
        HashElement value;
        Node* next;
        Node(HashElement value) {
            next = nullptr;
            this->value = value;
        }
        // Node(){next = nullptr;value=-1;}
    };


    Node** table;
    int hash(HashElement value) {
        return value % TableSize;
    }
public:
    int numberOfElements;
    HashTable() : numberOfElements(0) {
        table = new (nothrow) Node * [TableSize];
        for (int i = 0; i < TableSize; ++i) {
            table[i] = nullptr;
        }
    }


    void insert(HashElement value) {
        int loc = hash(value);
        if (table[loc] == nullptr) {
            table[loc] = new Node(value);
            numberOfElements++;
            return;
        }
        if (table[loc]->value == value) {
            cerr << "Item already exists";
            return;
        }
        else {
            Node* ptr = table[loc];
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = new Node(value);
            numberOfElements++;
        }
    }

    void remove(HashElement value) {
        int loc = hash(value);
        if (table[loc] == 0) {
            return;
        }
        if (table[loc]->value == value) {
            Node* ptr = table[loc]->next;
            delete table[loc];
            table[loc] = ptr;
            ptr = 0;
            numberOfElements--;
        }
        else {
            Node* pred = 0;
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
                numberOfElements--;
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
    void print(Dequeue<int>& requestingUsers) {
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
    ~HashTable() {
        for (int i = 0; i < TableSize; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
        delete[] table;
    }

};
#endif