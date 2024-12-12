#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "Graph.h"
#include "STLs.h"
# include <string>
using namespace std;

void Graph :: BFS(User user , CustomMap &Visited){
    Dequeue <int> frontier;
    for (auto it = user.getfriends().begin(); it != 0;it=it->next)
        frontier.push_back(it->data);
    
    int degree = 1;
    int n = 0;
    int magdi = 1;
    int compareN = frontier.size();
    while(!frontier.empty() && degree < 5){
        int popped = frontier.front();
        frontier.pop_front();
        if(degree == 2)
            Visited.insert(popped,1);
        else if (Visited.contains(popped) == false) {
                Visited.insert(popped, 1-degree);
        }
        
        for( auto it = users.get(popped).getfriends().begin(); it != 0; it->next) {
            if(Visited.contains(it->data) == false && (user.getusername() != users.get(it->data).getusername() && user.getpassword() != users.get(it->data).getpassword()))
                frontier.push_back(it->data);
        }
        n++;
        if(n==compareN){
            degree++;
            n = 0 ;
            compareN = frontier.size();
        }
        
    }
}
void Graph :: search(string search){
    Dequeue <int> searchResults;
    cout << "Search result" << endl;
    cout << "-----------------------"<< endl;
    bool found = false;
    for(int i = 0 ; i < users.size() ; i++){
        if(users.get(i).getusername().find(search) != string::npos) {
            cout << searchResults.size()+1 << " : " << users.get(i).getusername() << endl;
            searchResults.push_back(i);
            found = true;
        }
    }
    if(!found)
        cout << "No search results found";
}
void Graph :: peopleYouMayKnow(User user){
    if(user.getfriends().empty())
    {
        cerr<<"shoflak so7ab"<<endl;
        return;
    }
    CustomMap Visited;
    BFS(user,Visited);
    Priority_Queue<int, int> mayKnow;
    for(int i=0;i<Visited.size();i++)
    {
        if(Visited.second(i) !=0)
        {
            bool found=false;
            for(auto it2=user.getfriends().begin();it2!=0;it2->next){
                if(it2->data== Visited.first(i))
                {
                    found=true;
                    break;
                }
            }
           
            if(!found && !user.getPending().found(Visited.first(i)) && !user.getRequests().found(Visited.first(i)))
                mayKnow.push(Visited.second(i), Visited.first(i));
        }
    }
    cout<<"People you may know:"<<endl;
    while(!mayKnow.empty())
    {
        cout<<users.get(mayKnow.top2()).getusername()<<" ";
        if(mayKnow.top1()>0)
        {
            cout<<"mutual friend: "<<mayKnow.top1();
        }
        cout<<"\n";
        mayKnow.pop();
    }

}

void Graph::sendRequest(const int current, const int index) {
    HashTable extra = users.get(index).getRequests();

    HashTable extra1 = users.get(index).getPending();

    extra.insert(current);
    extra1.insert(index);

    /*

    if (extra[hash(index)].getusername() == "-1") {

        return;
    }
    else {
        NodePointer ptr = extra[hash(index)];
        while (ptr != 0) {
            if (extra[hash(index)].getusername() == users[index].getusername()) {
                users[index].getRequests().insert(index);
                return;
            }
            ptr = ptr->next;
        }
    }
    */
}

void Graph::removeFriend(const int current, const int index) {
    users.get(current).getfriends().erase(index);
}
void Graph::login() {
    string tempUserName;
    string tempPassword;
    bool found = false;
    cout << "Welcome to dr.Ashraf's Project :) " << endl;
    do {
        cout << "Username : ";
        cin >> tempUserName;
        cout << "Password : ";
        cin >> tempPassword;

        for (int i = 0; i < users.size(); i++)
            if (users.get(i).getusername() == tempUserName && users.get(i).getpassword() == tempPassword) {
                found = true;
                return;
            }
        cout << "Either the username or the password are not correct , Please re-enter your data to continue....";
    } while (!found);
}


void Graph::signup() {
    string tempUserName;
    string tempPassword;
    string conPassword;
    int tempAge;
    bool correctData = false;
    cout << "Welcome to dr.Ashraf's Project :) " << endl;
    cout << "Please enter the following data ";
    do {
        cout << "Username :";//validate
        cin >> tempUserName;
        for(int i = 0 ; i < users.size() ; i++){
        if (users.get(i).getusername() != tempUserName)
            correctData = true;
        else {
            cerr << "Username already exists \n"; //check yal hadary
            cout << "Please enter another username";
        }}
    } while (!correctData);
    do {
        cout << "Password :";//validate
        cin >> tempPassword;
        cout << "Confirm your password :";//validate
        cin >> conPassword;
        if (tempPassword == conPassword)
            break;
        else {
            cerr << "Please enter matching passwords";
            correctData = false;
        }
    } while (!correctData);
    do {
        cout << "Enter your age :";//validate
        if (!(cin >> tempAge)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number: ";
            correctData = false;
            if (tempAge < 18 && tempAge>0) {
                cerr << "The minimum age for signing up is 18";
                exit(-1);
            }if (tempAge < 0) {
                cerr << "INVALID INPUT";
                cout << "Please enter a valid age";
                correctData = false;
            }
        }}while (!correctData);

        User u (tempUserName, tempPassword, tempAge);


}
