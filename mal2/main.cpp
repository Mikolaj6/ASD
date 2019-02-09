#include <iostream>
#include <vector>
#include <math.h>

#define WHITE 1
#define BLACK -1
#define MIXED 0

using namespace std;

int next_power_2(int n) {
    return (int) pow(2, ceil(log2(n)));
}

int get_max_depth(int n) {
    return (int) log2(n);
}

vector<int> tree;
int max_depth;
int length;

int get_color(int node, int depth) {
    if(tree[node] == 0){
        return BLACK;
    } else if(tree[node] == 1 << (max_depth - depth)){
        return WHITE;
    } else {
        return MIXED;
    }
}

void fill_children(int depth, int pos, int node_col) {
    if(depth == max_depth)
        return;
    if(node_col == WHITE){
        tree[pos * 2] = 1 << (max_depth - depth - 1);
        tree[(pos * 2) + 1] = 1 << (max_depth - depth - 1);
    } else {
        tree[pos * 2] = 0;
        tree[(pos * 2) + 1] = 0;
    }
}

int insert_query(pair<int, int> &inter, int depth, int pos, bool to_white, int left, int right) {
    int node_col = get_color(pos, depth);
    if(node_col == BLACK || node_col == WHITE)
        fill_children(depth, pos, node_col);
    int x = 0;

    if(inter.first <= left && inter.second >= right) {
        if(to_white)
            tree[pos] = 1 << (max_depth - depth);
        else
            tree[pos] = 0;
        return tree[pos];
    } else if(inter.second < left || inter.first > right) {
        return tree[pos];
    } else {
        int val1 = insert_query(inter, depth + 1, pos * 2, to_white, left, left + ((right - left - 1)/2));
        int val2 = insert_query(inter, depth + 1, (pos * 2) + 1, to_white, left + ((right - left + 1)/2), right);
        tree[pos] = val1 + val2;
        return tree[pos];
    }
}

int main() {
    int queries;
    cin >> length >> queries;

    int act_lgh = next_power_2(length);
    tree = vector<int>((unsigned int)act_lgh * 2, 0);
    max_depth = get_max_depth(act_lgh);

    int left, right;
    char check_type;
    bool is_white;

    for(int i=0; i<queries; i++){
        cin >> left >> right >> check_type;
        is_white = true;
        pair<int, int> inter = make_pair(left, right);
        if(check_type == 'C')
            is_white = false;
        cout << insert_query(inter, 0, 1, is_white, 1, act_lgh) << endl;
    }

    return 0;
}