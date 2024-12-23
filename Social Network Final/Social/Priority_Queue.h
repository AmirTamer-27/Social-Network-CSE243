#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

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
#endif