#ifndef PAIR
#define PAIR
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
template<typename KeyType, typename ValueType>
class Pair {
private:
    KeyType key;
    ValueType value;
public:
    Pair() : key(KeyType()), value(ValueType()) {}
    KeyType& first() {
        return key;
    }
    ValueType& second() {
        return value;
    }
    void first(KeyType k)
    {
        key = k;
    }
    void second(ValueType v)
    {
        value = v;
    }
    void swapPair(Pair<KeyType, ValueType>& p1)
    {

        KeyType tk = p1.key;
        ValueType tv = p1.value;
        p1.key = key;
        p1.value = value;
        key = tk;
        value = tv;
        // cout<<p1.key<<"  "<<p1.value<<"  "<<key<<"  "<<value<<"\n";

    }
    const bool operator== (const Pair& rhs) {
        return (key == rhs.key);
    }
    bool operator> (const Pair& rhs) {
        return (key > rhs.key);
    }
    const bool operator< (const Pair& rhs) {
        return (key < rhs.key);
    }
    const bool operator>= (const Pair& rhs) {
        return (key >= rhs.key);
    }
    const bool operator<= (const Pair& rhs) {
        return (key <= rhs.key);
    }





};
#endif
