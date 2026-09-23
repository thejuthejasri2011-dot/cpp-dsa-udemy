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
};

int main() {
    graph* mygraph = new graph;
    mygraph->addVertex("A");
    mygraph->printGraph();
}