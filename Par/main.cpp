#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>

#define SIZE 20

using namespace std;

int nodes;

struct Node {
    int father;
    pair<int, int> childeren;
    pair<int, int> left;
    pair<int, int> right;
    int depth;
    pair<int, int> furthest_up;
    pair<int, int> furthest;
    vector<int> positions_up;

    inline Node(){
        father = -1;
        childeren = make_pair(-1,-1);
        left = make_pair(-1,-1);
        right = make_pair(-1,-1);
        furthest_up = make_pair(-1,-1);
        furthest = make_pair(-1,-1);
        positions_up = vector<int>(SIZE,1);
        depth = -1;
    }
};


class Tree {
private:
    vector<bool> visited;

public:
    vector<Node> tree;

    inline Tree(int n) {
        tree.resize((unsigned long long) (n + 1), Node());
        visited.resize((unsigned long long) (n + 1), false);
    }

    inline void addNode(int node, int left, int right) {
        if(left != -1){
            tree[left].positions_up[0] = node;
            tree[left].father = node;
        }
        if(right != -1){
            tree[right].positions_up[0] = node;
            tree[right].father = node;
        }

        tree[node].childeren.first = left;
        tree[node].childeren.second = right;
    }

    inline pair<int, int> children(int node) {
        return tree[node].childeren;
    }

    inline void clearVisited() {
        fill_n(visited.begin(), visited.size(), false);
    }

    inline bool isVisited(int n) {
        return visited[n];
    }

    inline void visit(int n) {
        assert(visited[n] == false);
        visited[n] = true;
    }

    inline bool is_leaf(int node){
        if(tree[node].childeren.first == -1 && tree[node].childeren.second == -1)
            return true;
        else
            return false;
    }


    // empty child has left, right == (-1, -1)
    inline pair<int, int> fill_tree(int node, int depth) {
        if(node == -1) {
            return make_pair(-1, -1);
        }
        tree[node].depth = depth;
        if(is_leaf(node))
            return make_pair(node, 1);

        tree[node].left = fill_tree(tree[node].childeren.first, depth + 1);
        tree[node].right = fill_tree(tree[node].childeren.second, depth + 1);

        if(tree[node].left.second >= tree[node].right.second)
            return make_pair(tree[node].left.first, tree[node].left.second + 1);
        else
            return make_pair(tree[node].right.first, tree[node].right.second + 1);
    }

    int get_other_child(int node, int father){
        if(tree[father].childeren.first == node)
            return tree[father].childeren.second;
        else
            return tree[father].childeren.first;
    }

    pair<int, int> max_from_node(int node){
        if(node == -1)
            return make_pair(-1, -1);
        if(tree[node].left.second == -1 && tree[node].right.second == -1)
            return make_pair(node, 0);
        if(tree[node].left.second >= tree[node].right.second)
            return tree[node].left;
        else
            return tree[node].right;
    }

    int calc_vec_val(int node, int jump) {
        int middle = tree[node].positions_up[jump - 1];
        return tree[middle].positions_up[jump - 1];
    }

    void calc_furthests(int node) {
        if(node == 1) {
            if(tree[1].left.second >= tree[1].right.second)
                tree[1].furthest = tree[1].left;
            else
                tree[1].furthest = tree[1].right;
            tree[1].furthest_up.first = 1;
            tree[1].furthest_up.second = 0;
        } else {
            int father = tree[node].father;
            pair<int, int> father_up =  tree[father].furthest_up;
            int other_child = get_other_child(node, father);
            pair<int, int> max_sibbling = max_from_node(other_child);

            if(max_sibbling.first == -1){
                tree[node].furthest_up.first = father_up.first;
                tree[node].furthest_up.second = father_up.second + 1;
            } else {
                if(father_up.second > max_sibbling.second + 1){
                    tree[node].furthest_up.first = father_up.first;
                    tree[node].furthest_up.second = father_up.second + 1;
                } else {
                    tree[node].furthest_up.first = max_sibbling.first;
                    tree[node].furthest_up.second = max_sibbling.second + 2;
                }
            }

            pair<int, int> curr_max = max_from_node(node);
            if(curr_max.second > tree[node].furthest_up.second){
                tree[node].furthest.first = curr_max.first;
                tree[node].furthest.second = curr_max.second;
            } else {
                tree[node].furthest.first = tree[node].furthest_up.first;
                tree[node].furthest.second = tree[node].furthest_up.second;
            }

            /* */
            int i = 1;
            while (true) {
                int new_jump = calc_vec_val(node, i);
                tree[node].positions_up[i] = new_jump;
                i++;
                if(new_jump == 1)
                    break;
            }

        }
        if(tree[node].childeren.first != -1)
            calc_furthests(tree[node].childeren.first);
        if(tree[node].childeren.second != -1)
            calc_furthests(tree[node].childeren.second);
    }

    // NIe może być tm samym nodem
    int find_node(int starting, int length){
        if(length < 0)
            return -1;
        if(length == 0)
            return starting;

        int final_depth = tree[starting].depth - length;
        int curr_node = starting;

        while(true){
            int i{10}, front{0}, back{19};


            while(true) {
                if (tree[tree[curr_node].positions_up[i]].depth ==
                    final_depth) {
                    return tree[curr_node].positions_up[i];
                }
                if (tree[tree[curr_node].positions_up[i]].depth > final_depth &&
                    tree[tree[curr_node].positions_up[i + 1]].depth <
                    final_depth) {

                    break;
                }
                if (tree[tree[curr_node].positions_up[i]].depth > final_depth) {
                    front = i + 1;
                    i = (i + back + 1) / 2;
                } else {
                    back = i;
                    i = (front + i) / 2;
                }
            }

            curr_node = tree[curr_node].positions_up[i];
            if(tree[tree[curr_node].father].depth == final_depth)
                return tree[curr_node].father;
            int sad = 0;
        }
    }


    int process_query(int from, int how_far) {
        if(how_far == 0)
            return from;

        int max_node = tree[from].furthest.first;
        int max_lgh = tree[from].furthest.second;
        if(tree[from].furthest.first != tree[from].furthest_up.first){
            if(max_lgh < how_far)
                return -1;
            return find_node(max_node, max_lgh - how_far);
        } else {
            if(tree[from].depth > tree[max_node].depth) {
                int to_equalize = tree[from].depth - tree[max_node].depth;
                if (how_far <= to_equalize)
                    return find_node(from, how_far);
                int middle = find_node(from, to_equalize);
                int new_how_far = how_far - to_equalize;
                if(new_how_far <= (max_lgh - to_equalize)/2)
                    return find_node(middle, new_how_far);
                else
                    return find_node(max_node, (max_lgh - to_equalize- new_how_far));
            } else if (tree[from].depth == tree[max_node].depth){
                if(how_far <= max_lgh/2)
                    return find_node(from, how_far);
                else
                    return find_node(max_node, (max_lgh - how_far));
            } else {

                int to_equalize = tree[max_node].depth - tree[from].depth;
                if ((max_lgh - how_far) <= to_equalize)
                    return find_node(max_node, (max_lgh - how_far));
                int middle = find_node(max_node, to_equalize);
                int new_how_far = (max_lgh - how_far) - to_equalize;
                if(new_how_far <= (max_lgh - to_equalize)/2)
                    return find_node(middle, new_how_far);
                else
                    return find_node(from, how_far);
            }
        }
    }

};
Tree given(500001);



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes;

/**/
    given.tree[1].father = 1;

    int left, right;
    for(int i = 1; i<=nodes; i++){
        cin >> left >> right;
        given.addNode(i, left, right);
    }
    given.fill_tree(1, 0);
    given.calc_furthests(1);


    /* */
    int from, how_far;
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++) {
        cin >> from >> how_far;
        cout << given.process_query(from, how_far) << endl;
    }


auto asd = given;
int ad = 0;



return 0;
}
/*
20
2 -1
3 -1
4 -1
5 -1
6 -1
7 -1
8 -1
9 -1
10 -1
11 -1
12 -1
13 -1
14 -1
15 -1
16 -1
17 -1
18 -1
19 -1
20 -1
-1 -1
4
11 12
*/
/*
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
*/
