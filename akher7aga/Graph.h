#include <iostream>
#include <list>
#include <set>
#include "STLs.h";
#include "User.h";
using namespace std;

class Graph {
private:
    Dequeue<User> users;
    public:
    void signup();
    void login();
    void sendRequest(const int current, const int index);
    void removeFriend(const int currUser , const int index);
    int select();
    void BFS(User user , CustomMap & Visited);
    void search(string username);
    void peopleYouMayKnow(User user);
};