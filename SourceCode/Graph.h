#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <map>
using namespace std;
class Graph{
    private:
    class User{
        public:
        string username;
        string password;
        int age;
        list<int> friends;
        set<int> pending;
        set<int> requests;
        User(string username , string password , int age):username(username),password(password),age(age){

        }

    
      
    };
    vector<User> users;
    public:
    void signup();
    void login();
    void addFriend();
    void removeFriend();
    int select();
    void BFS(User user , map<int,int> & Visited);
    void DFS();
    void viewByName();
    void peopleYouMayKnow(User user);
};

