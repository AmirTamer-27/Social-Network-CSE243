#ifndef CUSTOMMAP
#define CUSTOMMAP
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
const int DEFAULT_CAPACITY_Map = 10000;
template<typename KeyType,typename ValueType>
class CustomMap {
private:
    pair<KeyType, ValueType>* data;
    int myCapacity;
    int mySize;

public:
    CustomMap(int numElements = DEFAULT_CAPACITY_Map) {
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
ostream& operator<< (ostream& out, const CustomMap<int,int>& aList) {
    aList.display(out);
    return out;
}

#endif