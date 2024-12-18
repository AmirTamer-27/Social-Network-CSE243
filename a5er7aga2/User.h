#ifndef USER
#define USER
#include <iostream>
#include "STLs.h"
using namespace std;
class User {
private:
    string username;
    string password;
    int age;
    
public:
    LinkedList friends;
    HashTable pending;
    HashTable requests;
    User() {}
    User(string username, string password, int age) :username(username), password(password), age(age){}
    LinkedList& getfriends() {
        return friends;
    }
    string& getusername() {
        return username;
    }
    string& getpassword() {
        return password;
    }
    int getage() {
        return age;
    }
    HashTable& getPending() {
        return pending;
    }
    HashTable& getRequests() {
        return requests;
    }
    ~User(){
    }
};
#endif
