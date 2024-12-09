#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "Graph.h"
#include "hed.h"
# include <string>
using namespace std;

void Graph :: BFS(User user , CustomMap &Visited){
    Dequeue <int> frontier;
    for (auto it = user.friends.begin(); it != 0;it=it->next)
        frontier.push_back(it->data);
    
    int degree = 1;
    int n = 0;
    int magdi = 1;
    int compareN = frontier.size();
    while(!frontier.empty() && degree < 5){
        int popped = frontier.front();
        frontier.pop();
        if(degree == 2)
            Visited[popped]++;
        else if (Visited[popped]==0){
                Visited[popped]--;
        }
        
        for( auto it = users[popped].friends.begin(); it!=users[popped].friends.end() ; it++){
            if(Visited[*it]==0 && (user.username != users[*it].username && user.password != users[*it].password))
                frontier.push(*it);
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
    deque <int> searchResults;
    cout << "Search result" << endl;
    cout << "-----------------------"<< endl;
    bool found = false;
    for(int i = 0 ; i < users.size() ; i++){
        if(users[i].username.find(search)!= string :: npos){
            cout << searchResults.size()+1 << " : " << users[i].username << endl;
            searchResults.push_back(i);
            found = true;
        }
    }
    if(!found)
        cout << "No search results found";
}
void Graph :: peopleYouMayKnow(User user){
    if(user.friends.empty())
    {
        cerr<<"shoflak so7ab"<<endl;
        return;
    }
    map<int,int> Visited;
    BFS(user,Visited);
    priority_queue<pair<int,int>> mayKnow;
    for(auto it:Visited)
    {
        if(it.second)
        {
            bool found=false;
            for(auto it2=user.friends.begin();it2!=user.friends.end();it2++){
                if(*it2==it.first)
                {
                    found=true;
                    break;
                }
            }
            if(!found && !user.pending.count(it.first) && !user.requests.count(it.first))
                mayKnow.push(make_pair(it.second,it.first));
        }
    }
    cout<<"People you may know:"<<endl;
    while(!mayKnow.empty())
    {
        cout<<users[mayKnow.top().second].username<<" ";
        if(mayKnow.top().first>0)
        {
            cout<<"mutual friend: "<<mayKnow.top().first;
        }
        cout<<"\n";
        mayKnow.pop();
    }

}
