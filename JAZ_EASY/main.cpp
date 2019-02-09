#include <iostream>
#include <vector>
#include <set>

#define UNVISITED 0
#define VISITED 1
#define FINISHED 2


using namespace std;

int vertices, edges;

vector<vector<int>> graph;
vector<int> visited;

bool hasCycle = false;


void dfs(int vertex) {
    if(visited.at(vertex))
        return;
    visited.at(vertex) = VISITED;

    for(auto elem: graph.at(vertex)){
        if(visited.at(elem) == FINISHED)
            hasCycle = true;
        else
            dfs(elem);
    }

    visited.at(vertex) = FINISHED;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> vertices >> edges;

    for (int i = 0; i <= vertices; i++){
        graph.emplace_back(vector<int>());
        visited.push_back(UNVISITED);
    }

    int from, to;
    for (int i = 0; i < edges; i++) {
        cin >> from >> to;
        graph.at(from).push_back(to);
        graph.at(to).push_back(from);
    }

    for(int i=1; i<vertices; i++) {
        dfs(i);
        if(hasCycle){
            cout << "TAK" << endl;
            return 0;
        }
    }

    cout << "NIE" << endl;

    return 0;
}