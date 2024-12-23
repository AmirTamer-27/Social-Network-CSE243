#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <fstream>
#include <utility>
#include <stdexcept>
using namespace std;
int CAP = 1000;

template<typename Element>
class PriorityQueue {
private:
	Element* myArray;
	int mySize;
	bool compare(const Element& a, const Element& b) {
		return a > b;
	}
	template<typename t1, typename t2>
	bool compare(const pair<t1, t2>& a, const pair<t1, t2>& b) {
		return a.first > b.first;
	}

public:
	PriorityQueue() {
		myArray = new (nothrow) Element[CAP];
		mySize = 0;
	}

	~PriorityQueue()
	{
		delete[] myArray;
	}

	bool empty() const{
		return mySize == 0;
	}

	int size() const {
		return mySize;
	}

	Element top() const {
		if (empty()) {
			cerr << "Nothing!!!" << '\n';
			throw runtime_error("PriorityQueue is empty");
		}

		return myArray[1];
	}

	void push(const Element& item) {
		if (mySize == CAP-1) {
			cerr << "was full resizing try push command again\n";
			Element* newArray = new Element[2 * CAP];
			for (int i = 1; i <= mySize; ++i) {
				*(newArray+i) = *(myArray+i);
			}
			delete[] myArray;
			myArray = newArray;
			CAP *= 2;
		}

		mySize++; 
		*(myArray + mySize) = item; 

		int loc = mySize;
		int ploc = mySize / 2;

		while (loc > 1 and compare(myArray[loc], myArray[ploc])) {
			
			Element temp = myArray[loc];
			myArray[loc] = myArray[ploc];
			myArray[ploc] = temp;

			loc = ploc;
			ploc = loc / 2;
		}
	}

	template<typename t1, typename t2>
	void push(const pair<t1, t2>& item) {
		if (mySize == CAP - 1) {
			cerr << "was full resizing try push command again\n";
			Element* newArray = new Element[2 * CAP];
			for (int i = 1; i <= mySize; ++i) {
				*(newArray + i) = *(myArray + i);
			}
			delete[] myArray;
			myArray = newArray;
			CAP *= 2;
			return;
		}

		mySize++;
		*(myArray + mySize) = item;

		int loc = mySize;
		int ploc = mySize / 2;

		while (loc > 1 and compare(myArray[loc], myArray[ploc])) {

			Element temp = myArray[loc];
			myArray[loc] = myArray[ploc];
			myArray[ploc] = temp;

			loc = ploc;
			ploc = loc / 2;
		}

	}

	void pop() {
		if (empty()) {
			cerr << "nothing to pop\n";
			return;
		}

		*(myArray+1) = *(myArray + mySize);
		mySize--;

		int loc = 1, l = 2 * loc, r = (2 * loc) + 1, big;

		while (l <= mySize) {

			big = l;

			if (r <= mySize and compare(myArray[r], myArray[l])) {
				big = r;
			}

			if (myArray[loc] >= myArray[big]) {
				break;
			}

			Element temp = myArray[loc];
			myArray[loc] = myArray[big];
			myArray[big] = temp;

			loc = big;
			l = 2 * loc;
			r = (2 * loc) + 1;
		}
	}
};