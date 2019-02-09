#include <iostream>
#include <queue>
#include <unordered_set>

#define array_size 18

using namespace std;
using VerInf = pair<int, pair<int, int>>;
unsigned int N, K, U;
bool finished = false;


VerInf get_min(queue<VerInf> &normal_dist, queue<VerInf> &u_dist);

bool is_elem(queue<VerInf> &normal_dist, queue<VerInf> &u_dist);

pair<int,int> next_pos(vector<char> &mapa, pair<int, int> &curr_elem);

int next_non_jump(vector<char> &mapa, int curr);

void manage_move(vector<char> &mapa, int position, int jump_k, int time, queue<VerInf> &normal_dist, queue<VerInf> &u_dist);


int main() {
    cin >> N >> K >> U;
    vector<vector<bool>> nodes(N + 1, vector<bool>(array_size, false));
    vector<char> mapa(N + 1);
    queue<VerInf> normal_dist;
    queue<VerInf> u_dist;
    for(int i=1; i<=N; i++)
        cin >> mapa[i];
    int time_ret = -2;
    normal_dist.push(make_pair(0, make_pair(1, 1)));

    while(!finished){
        if(!is_elem(normal_dist, u_dist)){
            time_ret= -1;
            break;
        }
        VerInf curr_elem = get_min(normal_dist, u_dist);
        if(nodes[curr_elem.second.first][curr_elem.second.second])
            continue;
        nodes[curr_elem.second.first][curr_elem.second.second] = true;

        if(curr_elem.second.first == N) {
            time_ret = curr_elem.first;
            break;
        }

        pair<int,int> positions = next_pos(mapa, curr_elem.second);
        manage_move(mapa, positions.first, curr_elem.second.second, curr_elem.first, normal_dist, u_dist);
        manage_move(mapa, positions.second, curr_elem.second.second, curr_elem.first, normal_dist, u_dist);
    }

    cout << time_ret << endl;

    return 0;
}


void manage_move(vector<char> &mapa, int position, int jump_k, int time, queue<VerInf> &normal_dist, queue<VerInf> &u_dist) {
    if(position == -1 || mapa[position] == '#')
        return;

    if(mapa[position] == 'U')
        u_dist.push(make_pair(time + U + 1, make_pair(position, jump_k)));
    if(mapa[position] == '*'){
        if(jump_k == array_size - 1)
            normal_dist.push(make_pair(time + 1, make_pair(position, jump_k)));
        else
            normal_dist.push(make_pair(time + 1, make_pair(position, jump_k + 1)));
    }
    if(mapa[position] == '.')
        normal_dist.push(make_pair(time + 1, make_pair(position, jump_k)));
}


bool is_elem(queue<VerInf> &normal_dist, queue<VerInf> &u_dist){
    if(normal_dist.empty() && u_dist.empty())
        return false;
    else
        return true;
}


VerInf get_min(queue<VerInf> &normal_dist, queue<VerInf> &u_dist){
    VerInf to_ret;
    if(normal_dist.empty()){
        to_ret = u_dist.front();
        u_dist.pop();
    } else if(u_dist.empty()){
        to_ret = normal_dist.front();
        normal_dist.pop();
    } else{
        if(normal_dist.front().first < u_dist.front().first){
            to_ret = normal_dist.front();
            normal_dist.pop();
        } else {
            to_ret = u_dist.front();
            u_dist.pop();
        }
    }
    return to_ret;
}


int next_non_jump(vector<char> &mapa, int curr){
    unordered_set<int> set1;

    while (curr <= N && curr > 0 && (mapa[curr] == '>' || mapa[curr] == '<')
            && set1.find(curr) == set1.end()) {

        set1.insert(curr);
        if (mapa[curr] == '>')
            curr += K;
        else if (mapa[curr])
            curr -= K;
    }

    if(curr <= N && curr > 0 && mapa[curr] != '>' && mapa[curr] != '<')
        return curr;
    else
        return -1;
}


pair<int,int> next_pos(vector<char> &mapa, pair<int, int> &curr_elem) {
    int next_pos_1{-1}, next_pos_S{-1};

    int curr = curr_elem.first + (1 << curr_elem.second);

    if(curr <= N && curr > 0) {
        if(mapa[curr] == '>' || mapa[curr] == '<')
            next_pos_1 = next_non_jump(mapa, curr);
        else
            next_pos_1 = curr;
    }

    curr = curr_elem.first + 1;

    if(curr <= N && curr > 0) {
        if(mapa[curr] == '>' || mapa[curr] == '<')
            next_pos_S = next_non_jump(mapa, curr);
        else
            next_pos_S = curr;
    }

    return make_pair(next_pos_1, next_pos_S);
}