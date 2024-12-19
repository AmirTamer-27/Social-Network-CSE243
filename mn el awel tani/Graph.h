#ifndef GRAPH
#define GRAPH
#include <iostream>
#include "STLs.h"
using namespace std;
template<typename Datatype>
class Graph {
private:
    class Node{
        public:
            Datatype data;
            LinkedList edges;
            Node(Datatype d):data(d){}
            
    };
    Dequeue<Node> *myGraph;
public:
    Graph() {
        myGraph = new Dequeue<Node>;
    }  
    void addNode(Datatype nodeData)
    {
        myGraph->push_back(new Node(nodeData));
    }
    void addEdge(int Node1,int Node2)
    {

    }
    void removeEdge(int,int);
    void removeNode(int);
    bool empty();
    Datatype get1(int){
    }
    bool found(Node);
    



    // void signup();
    // int login();
    // void showFriends(int index);
    // int handleUser(int);
    // void handleRequests(const int  ,const  int  ,const  int );
    // void sendRequest(const int current, const int index);
    // void removeFriend(const int currUser, const int index);
    // void BFS(int, CustomMap& Visited);
    // void showRequests(int);
    // void search(string username, int currentUser);
    // void peopleYouMayKnow(int);
    // void viewUser(int currentUser, int userIndex);
};
#endif