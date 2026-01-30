#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;
int n;

bool hasEdge(int u, int v) {
    for (int x : adj[u]) {
        if (x == v) return true;
    }
    return false;
}

bool solve(int curr, int cnt) {
    if (cnt == n) {
        return hasEdge(curr, path[0]); 
    }

    for (int next : adj[curr]) {
        if (!visited[next]) {
            visited[next] = true;
            path.push_back(next);

            if (solve(next, cnt + 1))
                return true;

            visited[next] = false;
            path.pop_back();
        }
    }
    return false;
}

int main() {
    n = 5;
    adj = {
        {1, 3},
        {0, 2, 3, 4},
        {1, 4},
        {0, 1, 4},
        {1, 2, 3}
    };

    visited.assign(n, false);

    path.push_back(0);
    visited[0] = true;

    if (solve(0, 1)) {
        for (int v : path)
            cout << v << " ";
        cout << path[0]; 
    } else {
        cout << "No Hamiltonian Cycle";
    }

    return 0;
}
