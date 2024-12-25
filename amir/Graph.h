#ifndef GRAPH
#define GRAPH
#include <iostream>
#include <list>
#include <set>
#include "HashTable.h"
#include "Dequeue.h"
#include "LinkedList.h"
#include "CustomMap.h"
// #include "User.h"
using namespace std;
template<typename Datatype>
class Graph {
private:
    class Node {
    public:

        Datatype data;
        LinkedList<int> edges;
        Node(Datatype d) :data(d) {}
        Node() :data(NULL) {}
    };
    Dequeue<Node>* myGraph;
public:

    Graph() {
        myGraph = new Dequeue<Node>;
    }
    void addNode(Datatype nodeData)
    {
        Node nd(nodeData);
        myGraph->push_back(nd);
    }
    void addEdge(int Node1, int Node2)
    {
        ((LinkedList<int>&)((Node&)myGraph->get(Node1)).edges).insert(Node2, 0);
        ((LinkedList<int>&)((Node&)myGraph->get(Node2)).edges).insert(Node1, 0);


    }


    void removeEdge(int Node1, int Node2)
    {
        ((LinkedList<int>&)((Node&)myGraph->get(Node1)).edges).erase(((LinkedList<int>&)((Node&)myGraph->get(Node1)).edges).search(Node2));
        ((LinkedList<int>&)((Node&)myGraph->get(Node2)).edges).erase(((LinkedList<int>&)((Node&)myGraph->get(Node2)).edges).search(Node1));

    }
    // void removeNode(int Node1){
    //     myGraph.
    // }
    bool empty() {
        return myGraph->empty();
    }
    Datatype get(int Node1) {
        return ((Node&)myGraph->get(Node1)).data;
    }
    bool found(Node Node1) {
        return (myGraph->find(Node1) != -1);

    }

    void getNodeEdges(int Node1, Dequeue<int>& edges) {
        for (auto it = ((LinkedList<int>&)((Node&)myGraph->get(Node1)).edges).begin(); it != 0; it = it->next)
            edges.push_back(it->data);
    }

    bool noEdges(int Node1) {
        return ((LinkedList<int>&)((Node&)myGraph->get(Node1)).edges).empty();
    }

    int size() {
        return myGraph->size();
    }
};
#endif