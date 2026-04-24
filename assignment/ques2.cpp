#include <bits/stdc++.h>
using namespace std;

class ques2 {
public:
    int V;
    vector<vector<int>> graph;
    vector<int> path;

    bool isSafe(int v, int pos) {
        if (graph[path[pos - 1]][v] == 0)
            return false;

        for (int i = 0; i < pos; i++) {
            if (path[i] == v)
                return false;
        }
        return true;
    }
    bool solve(int pos) {
        if (pos == V) {
            return graph[path[pos - 1]][path[0]] == 1;
        }
        for (int v = 1; v < V; v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;
                if (solve(pos + 1))
                    return true;

                path[pos] = -1;
            }
        }
        return false;
    }

    void printSolution() {
        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl;
    }
};

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    ques2 obj;
    obj.V = V;
    obj.graph = graph;
    obj.path.assign(V, -1);

    obj.path[0] = 0;

    if (obj.solve(1)) {
        obj.printSolution();
    } else {
        cout << "No Hamiltonian Cycle exists\n";
    }

    return 0;
}
