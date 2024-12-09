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
    void addFriend();
    void removeFriend();
    int select();
    void BFS(User user , CustomMap & Visited);
    void search(string username);
    void peopleYouMayKnow(User user);
};