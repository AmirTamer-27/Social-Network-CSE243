#include <iostream>
#include <list>
#include <set>
#include "hed.h"
using namespace std;
class User {
private:
    string username;
    string password;
    int age;
    LinkedList friends;
    set<int> pending;
    set<int> requests;
public:
    User(string username, string password, int age) :username(username), password(password), age(age) {}
    LinkedList getfriends() {
        return friends;
    }
    string getusername() {
        return username;
    }
    string getpassword() {
        return password;
    }
    int getage() {
        return age;
    }
};
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


