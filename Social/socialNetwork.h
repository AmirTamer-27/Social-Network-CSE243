#ifndef SOCIALNETWORK
#define SOCIALNETWORK
#include <iostream>
#include "User.h"
#include "Graph.h"
#include "CustomMap.h"
#include "priority_heap.h"
class SocialNetwork{
    public:
    Graph<User*> users;
    SocialNetwork(){
    

    }
        void BFS(int currentUser, CustomMap<int, int>& Visited) {
            Dequeue <int> frontier;
            users.getNodeEdges(currentUser, frontier);
            // for (auto it = users.get(currentUser)->getfriends().begin(); it != 0;it = it->next)
            //     frontier.push_back(it->data);
            //cout<<frontier<<endl;
            int degree = 1;
            int n = 0;
            int compareN = frontier.size();
            while (!frontier.empty() && degree < 5) {
                int popped = frontier.front();
                frontier.pop_front();
                if (degree == 2)
                    Visited.insert(popped, 1);
                else if (Visited.contains(popped) == false) {
                    Visited.insert(popped, 1 - degree);
                }
                Dequeue<int> temp;
                users.getNodeEdges(popped, temp);
                for (int i = 0; i < temp.size(); i++) {
                    if (Visited.contains(temp.get(i)) == false)
                        frontier.push_back(temp.get(i));
                }
                n++;
                if (n == compareN) {
                    degree++;
                    n = 0;
                    compareN = frontier.size();
                }

            }
    }
    void  search(string search, int currentUser) {
        Dequeue <int> searchResults;
        cout << "Search result" << endl;
        cout << "-----------------------" << endl;
        bool found = false;
        int cnt=0;
        short x;
        for (int i = 0; i < users.size() && cnt<11; i++) {
            if (i != currentUser)
                if (users.get(i)->getusername().rfind(search) != string::npos) {
                    cout << searchResults.size() + 1 << " : " << users.get(i)->getusername() << endl;
                    searchResults.push_back(i);
                    cnt++;
                    found = true;
                }
                if(cnt==11)
                {
                    cout<<"View more(0) else (1)"<<endl;
                    cin>>x;
                    if(x==0)
                        cnt=0;

                }
        }
        if (!found) {
            cout << "No search results found";
            return;
        }
        int y;
        
        cout << "Enter index of user u want to view or -1 to go back\n";
        cin >> y;
        if (y != -1)
            viewUser(currentUser, searchResults.get(y- 1));
    }

    void  peopleYouMayKnow(int currentUser) {
        if (users.noEdges(currentUser))
        {
            cerr << "shoflak so7ab" << endl;
            return;
        }
        CustomMap<int,int> Visited;
        BFS(currentUser, Visited);
        PriorityQueue<pair <int, int> >mayKnow;

        Dequeue<int> temp;
        users.getNodeEdges(currentUser, temp);

        for (int i = 0;i < Visited.size();i++)
        {
            
            if (Visited.second(i) != 0)
            {   bool found = false;
                if(temp.find(Visited.first(i)) != -1){
                    found = true;
                }

                if (!found && !users.get(currentUser)->getPending().found(Visited.first(i)) && !users.get(currentUser)->getRequests().found(Visited.first(i)) && Visited.first(i) != currentUser)
                    mayKnow.push(make_pair(Visited.second(i), Visited.first(i)));
            }
        }
        cout << "People you may know:" << endl;
        while (!mayKnow.empty())
        {
            cout << users.get(mayKnow.top().second)->getusername() << " ";
            if (mayKnow.top().first > 0)
            {
                cout << "mutual friend: " << mayKnow.top().first;
            }
            else{
                cout << "Degree : " << -1*mayKnow.top().first;
            }
            cout << "\n";
            mayKnow.pop();
        }

    }

    void  viewUser(int currentUser, int userIndex) {
        int view;
        if (userIndex == -1)
            view = currentUser;
        else
            view = userIndex;
        bool found = false;
        cout << "Username : ";
        cout << users.get(view)->getusername() << '\n';
        cout << "Age : ";
        cout << users.get(view)->getage() << '\n';
        cout << "Friends list : \n";
        int cnt=0;
        short x;
        Dequeue<int> friends;
        users.getNodeEdges(view, friends);

        for (int i = 0 ; i < friends.size() && cnt<11; i++) {
            if (friends.get(i) == currentUser) {
                found = true;
                continue;
            }
            cout << users.get(friends.get(i))->getusername() << " ";
            cnt++;
            if(cnt==11)
                {
                    cout<<"\nView more(0) else (1)"<<endl;
                    cin>>x;
                    if(x==0)
                        cnt=0;

                }
        }
    
        if (found) {
            cout << "Status : friend\n";
            cout << "Remove(1) " << users.get(view)->getusername() << " or -1 to go back\n";
            cin >> x;
            if (x == 1) {
                removeFriend(currentUser, view);
            }
        }
        else if (userIndex != -1 && users.get(currentUser)->getRequests().found(view)) {
            cout << "Status : Accept(1) or Decline(0) or -1 to go back\n";
            cin >> x;
            if (x == -1) {
                return;
            }
            handleRequests(currentUser,userIndex,x);
        }
        else if (userIndex != -1 && users.get(currentUser)->getPending().found(view)) {
            cout << "Status : Requested\n";
        }
        else
            if (userIndex != -1 && !found) {
                cout << "Send Request(0) or -1 to go back\n";
                cin >> x;
            
             cout << "YOYOYO";
                if (x == 0){
                    sendRequest(currentUser, userIndex);
            }
            }
    }

    void  showRequests(int currentUser){
        Dequeue<int> requestingUsers;
        users.get(currentUser)->getRequests().print(requestingUsers);
        int userIndex=0,cnt=0,count=1;
        short x;
        for(int i=0;i<requestingUsers.size() && cnt<11;i++)
        {
            cout << count << ": " << users.get(requestingUsers.get(i))->getusername() << endl;
                count++;
                cnt++;
                if(cnt==11)
                {
                    cout<<"View more(0) else (1)\n";
                    cin>>x;
                    if(x==0)
                        cnt=0;

                }
                
            }
        
        while(!requestingUsers.empty())
        {
            cout<<"Enter index of user u want to view or -1 to go back\n";
            cin>>userIndex;
            if(userIndex==-1)
                break;
            viewUser(currentUser,requestingUsers.get(userIndex-1));    

        }

    }

    void sendRequest(const int current, const int index) {
        users.get(index)->getRequests().insert(current);
        users.get(current)->getPending().insert(index);
    }

    void  removeFriend(const int current, const int index) {
       users.removeEdge(current,index);

    }
    // int  login() {
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


    // void  signup() {
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
    void  handleRequests(const int currentUser ,const  int userIndex ,const  int action) {
        users.get(currentUser)->getRequests().remove(userIndex);
        users.get(userIndex)->getPending().remove(currentUser);

        if (action == 1)
        {
           users.addEdge(currentUser,userIndex);
        }

        
    }
    int  handleUser(int action) {
        if (action == 1) {
            string username, password;
            int age;
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter password : ";
            cin >> password;
            cout << "Enter age : ";
            cin >> age;
            // User u(username, password, age);
            // user = u;

            users.addNode(new User(username, password, age));
        }
        string username, password;
        cout << "Enter your account details to login" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        cout << users.get(0)->getusername();
        for (int i = 0; i < users.size(); i++) {
            if (users.get(i)->getusername() == username && users.get(i)->getpassword() == password) {
                cout << "Logged in SUCCESFULLY" << endl;
                return i;
            }
        }
        cout << "Password or username are incorrect";
        return -1;
    }

    void  showFriends(int index) {
        int count = 0,cnt=0;
        short x;
        Dequeue<int> friends;
        users.getNodeEdges(index,friends);
         for (int i = 0 ; i < friends.size() && cnt<11; i++)  {
            cout << cnt + 1 << " : " << users.get(friends.get(i))->getusername() << '\n';
            count++;
            cnt++;
            if(cnt==11)
                {
                    cout<<"\nView more(0) else (1)"<<endl;
                    cin>>x;
                    if(x==0)
                     cnt=0;

                }
        }
    }
};
#endif