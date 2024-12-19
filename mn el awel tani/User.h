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
    HashTable pending;
    HashTable requests;
    
public:
   
    User() {}
    User(string username, string password, int age) :username(username), password(password), age(age){}
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
    Dequeue<int>& getRequestsIndices(){
        Dequeue<int> requestingUsers;
        requests.getIndices(requestingUsers);
        return requestingUsers;
    }
    void updateRequests (int index){
        requests.insert(index);
    }
    void updatePending (int index){
        pending.insert(index);
    }
    //Update data inshalla

    ~User(){
        delete &pending;
        delete &requests;
    }
};
#endif