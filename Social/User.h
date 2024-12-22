#ifndef USER
#define USER
#include <iostream>
#include "HashTable.h"
#include "Dequeue.h"
#include "LinkedList.h"
using namespace std;
class User {
private:
    string username;
    string password;
    int age;
    HashTable<int> pending;
    HashTable<int> requests;
    
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
    HashTable<int>& getPending() {
        return pending;
    }
    HashTable<int>& getRequests() {
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
        cout << "BIG MAN BADRA";
        
    }
};
#endif