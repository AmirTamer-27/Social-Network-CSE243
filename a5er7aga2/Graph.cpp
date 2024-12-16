#include <iostream>
#include "Graph.h"
#include "User.h"
#include "STLs.h"
#include <string>
using namespace std;

void Graph::BFS(User user, CustomMap& Visited) {
    Dequeue <int> frontier;
    for (auto it = user.getfriends().begin(); it != 0;it = it->next)
        frontier.push_back(it->data);

    int degree = 1;
    int n = 0;
    int magdi = 1;
    int compareN = frontier.size();
    while (!frontier.empty() && degree < 5) {
        int popped = frontier.front();
        frontier.pop_front();
        if (degree == 2)
            Visited.insert(popped, 1);
        else if (Visited.contains(popped) == false) {
            Visited.insert(popped, 1 - degree);
        }

        for (auto it = users.get(popped)->getfriends().begin(); it != 0; it=it->next) {
            if (Visited.contains(it->data) == false && (user.getusername() != users.get(it->data)->getusername() && user.getpassword() != users.get(it->data)->getpassword()))
                frontier.push_back(it->data);
        }
        n++;
        if (n == compareN) {
            degree++;
            n = 0;
            compareN = frontier.size();
        }

    }
}
void Graph::search(string search, int currentUser) {
    Dequeue <int> searchResults;
    cout << "Search result" << endl;
    cout << "-----------------------" << endl;
    bool found = false;
    for (int i = 0; i < users.size(); i++) {
        if(i != currentUser)
        if (users.get(i)->getusername().rfind(search) != string::npos) {
            cout << searchResults.size() + 1 << " : " << users.get(i)->getusername() << endl;
            searchResults.push_back(i);
            found = true;
        }
    }
    if (!found){
        cout << "No search results found";
        return;
    }
    int x;
    cout << "Enter index of user u want to view or -1 to go back\n";
    cin >> x;
    if(x!=-1)
        viewUser(currentUser, searchResults.get(x-1));
}
void Graph::peopleYouMayKnow(User user) {
    if (user.getfriends().empty())
    {
        cerr << "shoflak so7ab" << endl;
        return;
    }
    CustomMap Visited;
    BFS(user, Visited);
    Priority_Queue<int, int> mayKnow;
    for (int i = 0;i < Visited.size();i++)
    {
        if (Visited.second(i) != 0)
        {
            bool found = false;
            for (auto it2 = user.getfriends().begin();it2 != 0;it2=it2->next) {
                if (it2->data == Visited.first(i))
                {
                    found = true;
                    break;
                }
            }

            if (!found && !user.getPending().found(Visited.first(i)) && !user.getRequests().found(Visited.first(i)))
                mayKnow.push(Visited.second(i), Visited.first(i));
        }
    }
    cout << "People you may know:" << endl;
    while (!mayKnow.empty())
    {
        cout << users.get(mayKnow.top2())->getusername() << " ";
        if (mayKnow.top1() > 0)
        {
            cout << "mutual friend: " << mayKnow.top1();
        }
        cout << "\n";
        mayKnow.pop();
    }

}

void Graph::viewUser(int currentUser, int userIndex){
    int view;
    if(userIndex == -1)
       view = currentUser;
    else
        view = userIndex;
    bool found = false;
    cout << "Username : ";
    cout << users.get(view)->getusername() << '\n';
    cout << "Age : "; 
    cout << users.get(view)->getage() << '\n';
    cout << "Friends list : \n";
    for(auto it = users.get(view)->getfriends().begin(); it != 0; it = it->next){
        if(it->data == currentUser){
            found = true;
            continue;
        }
        cout << users.get(it->data)->getusername() << " ";
    }
    short x;
    if(found){
        cout << "Status : friend\n";
        cout << "Remove(1) " << users.get(view)->getusername() <<" or -1 to go back\n";
        cin >> x;
        if(x == 1){
            removeFriend(currentUser,view);
        }
    }else if( userIndex != -1 and users.get(currentUser)->getRequests().found(view)){
        cout << "Status : Accept(1) or Decline(0) or -1 to go back\n";
        cin >> x;
        if(x == -1){
            return;
        }
        //hadary 3el2
    }else if(userIndex != -1 and users.get(currentUser)->getPending().found(view)){
        cout << "Status : Requested\n";
    }else
    if(userIndex != -1 and !found){
        cout << "Send Request(0) or -1 to go back\n";
        cin >> x;
        if(x == 0)
            sendRequest(currentUser, userIndex);
    }
}


void Graph::sendRequest(const int current, const int index) {
    users.get(index)->getRequests().insert(current);
    users.get(current)->getPending().insert(index);
    cout << "wslna" << endl;
    /*

    if (extra[hash(index)]->getusername() == "-1") {

        return;
    }
    else {
        NodePointer ptr = extra[hash(index)];
        while (ptr != 0) {
            if (extra[hash(index)]->getusername() == users[index]->getusername()) {
                users[index]->getRequests().insert(index);
                return;
            }
            ptr = ptr->next;
        }
    }
    */
}

void Graph::removeFriend(const int current, const int index) {
    users.get(current)->getfriends().erase(users.get(current)->getfriends().search(index));
    users.get(index)->getfriends().erase(users.get(index)->getfriends().search(current));
    cout << "wslna2" << endl;
}
// int Graph::login() {
    // string tempUserName;
    // string tempPassword;
    // bool found = false;
    // cout << "Welcome to dr.Ashraf's Project :) " << endl;
    // do {
    //     cout << "Username : ";
    //     cin >> tempUserName;
    //     cout << "Password : ";
    //     cin >> tempPassword;
    //     for (int i = 0; i < users.size(); i++){
    //         if (users.get(i)->getusername() == tempUserName && users.get(i)->getpassword() == tempPassword) {
    //             found = true;
    //             return i ;
    //         }}
    //     cout << "Either the username or the password are not correct"<<endl;
    //     cout << "If u want to signup enter 0 , retry enter any num";
    //     int signup;
    //     cin >> signup;
    //     if (!signup)
    //         return -1;

    // } while (!found);
// }
// int Graph :: login(){
//     string name;
//     string pass;
//     cout << "enter : ";
//     cin >> name;
//     cout << "enter pass :";
//     cin >> pass;
//     cout << users.get(0)->getusername();
//     cout << users.get(0)->getpassword();
    
//     if(users.get(0)->getusername() == name ){
//         cout << "nasdas";
//         return 0;
//         }
//     return -1;
// }


// void Graph::signup() {
//     string tempUserName;
//     string tempPassword;
//     string conPassword;
//     int tempAge;
//     bool correctData = false;
//     cout << "Welcome to dr.Ashraf's Project :) " << endl;
//     cout << "Please enter the following data ";
//     do {
//         cout << "Username :";//validate
//         cin >> tempUserName;
//         correctData = true;
//     } while (!correctData);
//     do {
//         cout << "Password :";//validate
//         cin >> tempPassword;
//         cout << "Confirm your password :";//validate
//         cin >> conPassword;
//         if (tempPassword == conPassword)
//             break;
//         else {
//             cerr << "Please enter matching passwords";
//             correctData = false;
//         }
//     } while (!correctData);
//     do {
//         cout << "Enter your age :";//validate
//         if (!(cin >> tempAge)) {
//             cin.clear(); // Clear the error flag
//             cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
//             cout << "Invalid input. Please enter a number: ";
//             correctData = false;
//         }
//         else if (tempAge < 18 && tempAge>0) {
//             cerr << "The minimum age for signing up is 18";
//             exit(-1);
//         }else if (tempAge < 0) {
//             cerr << "INVALID INPUT";
//             cout << "Please enter a valid age";
//             correctData = false;
//         }
//     } while (!correctData);

//     User u(tempUserName, tempPassword, tempAge);
//     users.push_back(u);
//     cout << users.get(0)->getusername();
//     cout << users.get(0)->getpassword();
//     cout << users.size();


// }
int Graph :: handleUser(int action , User &user){
    if(action == 1){
        string username , password;
        int age ;
        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        cout << "Enter age : ";
        cin >> age;
        User u(username,password,age);
        user = u;
        users.push_back(&user);
    }
    string username , password;
    cout << "Enter your account details to login" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Enter username : ";
    cin >> username;
    cout << "Enter password : ";
    cin >> password;
    for(int i  = 0  ; i < users.size() ; i++){
        if(users.get(i)->getusername() == username && users.get(i)->getpassword() == password){
            cout << "Logged in SUCCESFULLY" << endl;
            return i;
        }
    }
    cout << "Password or username are incorrect";
    return -1;
}

void Graph::showFriends(int index){
    int cnt = 0;
    for (auto it2 = users.get(index)->getfriends().begin();it2 != 0; it2 = it2 ->next) {
        cout << cnt +1 << " : " << users.get(it2->data)->getusername() << '\n';
        cnt++;
    }
}