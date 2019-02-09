#include <iostream>
#include <vector>
#include <set>

#define UNVISITED 0
#define VISITED 1

using namespace std;

int vertices, edges;

vector<vector<int>> graph;
vector<int> visited;
vector<int> times;

int time_ = 1;
int hasOddCycle = false;

void dfs(int vertex, int last) {
    if (visited.at(vertex) == VISITED)
        return;
    visited.at(vertex) = VISITED;
    times.at(vertex) = time_;
    time_++;

    for (auto elem: graph.at(vertex)) {
        if (visited.at(elem) == VISITED) {
            if (times.at(vertex) - times.at(elem) % 2 == 0 && elem != last)
                hasOddCycle = true;
        } else {
            dfs(elem, vertex);
        }
    }
}

int main() {
    cin >> vertices >> edges;

    for (int i = 0; i <= vertices; i++) {
        visited.push_back(UNVISITED);
        graph.emplace_back(vector<int>());
        times.push_back(0);
    }

    int from, to;
    for (int i = 0; i < edges; i++) {
        cin >> from >> to;
        graph.at(from).push_back(to);
        graph.at(to).push_back(from);
    }

    for (int i = 1; i <= vertices; i++) {
        dfs(i, -1);
        if (hasOddCycle) {
            cout << "NIE" << endl;
            return 0;
        }
    }

    cout << "TAK" << endl;

    return 0;
}