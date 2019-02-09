#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>


using namespace std;

struct node {
    int x, y, up{-1}, down{-1}, left{-1}, right{-1};

    node(int x, int y){
        this->x = x;
        this->y = y;
    }
};

vector<node> elements;

bool compare_x(int a, int b) {
    return elements[a].x < elements[b].x;
}

bool compare_y(int a, int b) {
    return elements[a].y < elements[b].y;
}

// id length
bool compare_DIJK(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

// a jest mniejsze
int x_length(int a, int b) {
    return elements[b].x - elements[a].x;
}
// a jest mniejsze
int y_length(int a, int b) {
    return elements[b].y - elements[a].y;
}

int main() {

    size_t islands;
    cin >> islands;
    int x, y;
    vector<int> indexes;

    for(int i = 0; i < islands; i++){
        cin >> x >> y;
        indexes.push_back(i);
        elements.emplace_back(node(x, y));
    }

    std::sort(indexes.begin(), indexes.end(), compare_x);

    int id_last = -1;
    for(int i = 0; i < islands; i++) {
        if(id_last != -1) {
            elements[id_last].right = indexes[i];
            elements[indexes[i]].left = id_last;
        }
        id_last = indexes[i];
    }

    std::sort(indexes.begin(), indexes.end(), compare_y);

    id_last = -1;
    for(int i = 0; i < islands; i++) {
        if(id_last != -1) {
            elements[id_last].up = indexes[i];
            elements[indexes[i]].down = id_last;
        }
        id_last = indexes[i];
    }

    auto bla = elements;

    int res = -1;
    vector<bool> visited(islands, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> koleja(compare_DIJK);
    koleja.push(make_pair(0, 0));

    while(!koleja.empty()){
        auto curr = koleja.top();
        koleja.pop();
        if(visited[curr.first])
            continue;
        if(curr.first == islands - 1) {
            res = curr.second;
            break;
        }
        visited[curr.first] = true;

        if (elements[curr.first].left != -1)
            koleja.push(make_pair(elements[curr.first].left, curr.second + x_length(elements[curr.first].left, curr.first)));
        if (elements[curr.first].right != -1)
            koleja.push(make_pair(elements[curr.first].right, curr.second + x_length(curr.first, elements[curr.first].right)));

        if (elements[curr.first].up != -1)
            koleja.push(make_pair(elements[curr.first].up, curr.second + y_length(curr.first, elements[curr.first].up)));
        if (elements[curr.first].down != -1)
            koleja.push(make_pair(elements[curr.first].down, curr.second + y_length(elements[curr.first].down, curr.first)));
        int x = 0;
    }

    cout << res << endl;

    return 0;
}
