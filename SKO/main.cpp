#include <iostream>
#include <vector>
#include <set>

#define over 10000

using namespace std;

int vertices_num, edges;

vector<set<pair<int, int>>> vertices;
vector<long long> minVec;


int get_double(int i, int j) {
    if(vertices.at(i).empty())
        return -1;

    if(vertices.at(i).begin()->first == j)
        return vertices.at(i).begin()->second;

    if(vertices.at(i).size() == 2 && (++vertices.at(i).begin())->first == j)
        return (++vertices.at(i).begin())->second;

    return -1;
}


int main() {

    cin >> vertices_num >> edges;

    for(int i=0; i<=vertices_num; i++){
        vertices.emplace_back(set<pair<int, int>>());
        if(i!=0)
            minVec.push_back(10000);
        else
            minVec.push_back(0);
    }

    int v1, v2, c;
    for(int i = 1; i <= edges; i++) {
        cin >> v1 >> v2 >> c;
        if(v1 > v2)
            swap(v1, v2);
        vertices.at(v1).insert(make_pair(v2, c));
    }

    if(vertices_num%2 == 1){
        cout << -1 << endl;
        return 0;
    }

    for(int i=2; i<=vertices_num; i++){
        if(i%2 == 0){
            if(!vertices[i - 1].empty() && vertices[i - 1].begin()->first == i) {
                minVec[i] = minVec[i-2] + vertices[i - 1].begin()->second;
            }
            if(i >= 4) {
                int val1 = get_double(i-3, i-1);
                int val2 = get_double(i-2, i);
                if(val1 != -1 && val2 != -1){
                    minVec[i] = min(minVec[i], minVec[i-4] +  val1 + val2);
                }
            }
        }
    }

    if(minVec[vertices_num] >= over)
        cout << -1 <<endl;
    else
        cout << minVec[vertices_num] << endl;

    return 0;
}
