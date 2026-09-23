#include<bits/stdc++.h>
using namespace std;
class graph{
    private:
    unordered_map<string,unordered_set<string>> adjList;
    public:
    void printGraph() {
        for(auto [vertex,edges] : adjList) {
            cout << vertex << ":[";
            for(auto edge : edges) {
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }
    bool addVertex(string vertex) {
        if(adjList.count(vertex) == 0){
            adjList[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(string vertex1,string vertex2) {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0 ){
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }

    bool removeEdge(string vertex1,string vertex2) {
             if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0 ) {
                adjList.at(vertex1).erase(vertex2);
                adjList.at(vertex2).erase(vertex1);
                return true;
             }
             return false;
    }

    bool removeVertex(string vertex) {
        if(adjList.count(vertex) == 0) return false;
        for(auto otherVertex : adjList.at(vertex)){
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main() {
    graph* mygraph = new graph;
    mygraph->addVertex("A");
    mygraph->addVertex("B");
    mygraph->addVertex("C");
    mygraph->addVertex("D");

    mygraph->addEdge("A","B");
    mygraph->addEdge("A","C");
    mygraph->addEdge("B","C");
    mygraph->addEdge("B","D");
    mygraph->addEdge("C","D");

    mygraph->removeEdge("A","B");

    mygraph->removeVertex("D");


    mygraph->printGraph();
}