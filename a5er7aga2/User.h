#ifndef GRAPH
#define GRAPH
#include <iostream>
#include <list>
#include <set>
#include "STLs.h"
#include "User.h"
using namespace std;

class Graph {


public:
    Dequeue<User*> users;
    Graph() {}

    // void signup();
    // int login();
    void showFriends(int index);
    int handleUser(int);
    void handleRequests(const int  ,const  int  ,const  int );
    void sendRequest(const int current, const int index);
    void removeFriend(const int currUser, const int index);
    void BFS(int, CustomMap& Visited);
    void showRequests(int);
    void search(string username, int currentUser);
    void peopleYouMayKnow(int);
    void viewUser(int currentUser, int userIndex);
};
#endif
