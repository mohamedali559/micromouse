#include <bits/stdc++.h>
#define ln "\n"
#include "./API.h"
typedef long long ll;
using namespace std;

int n = 256;
vector<bool> visited;
vector<vector<pair<char, int>>> adj;

int num_to_remove;

void update_adj(int u)
{
    if (API::wallFront())
    {
        for (auto v : adj[u])
        {
            if (v.first == 't')
                v.second = -1;
        }
    }
}

void move(char m)
{
    switch (m)
    {
    case 't':
        API::moveForward(1);
        break;
    case 'r':
        API::turnRight();
        API::moveForward(1);
        break;
    case 'l':
        API::turnLeft();
        API::moveForward(1);
        break;
    case 'b':
        API::turnRight();
        API::turnRight();
        API::moveForward(1);
        break;
    default:
        break;
    }
}

void dfs(int u)
{
    visited[u] = 1;
    fprintf(stderr, "%s\n", "dfs");
    fflush(stderr);
    // update_adj(u);
    for (auto v : adj[u])
    {
        // update_adj(v.second);
        if (!visited[v.second] && v.second >= 0)
        {
            dfs(v.second);
            // move(v.first);
        }
    }
}

void solve()
{
    dfs(0); // ممكن تفعل دي لو حابب تجرب DFS
    //  while (true) {
    //     fprintf(stderr, "%s\n", "dddd");
    //     fflush(stderr);
    //     if (!API::wallLeft()) {
    //         API::turnLeft();
    //     }
    //     while (API::wallFront()) {
    //         API::turnRight();
    //     }
    //     API::moveForward();
    // }


    adj.assign(n, {});
    visited.assign(n, 0);

    for (int i = 0; i < 256; i++)
    {
        int row = i / 16;
        int col = i % 16;

        // فوق
        if (row > 0)
            adj[i].push_back({'t', (i - 16)});

        // تحت
        if (row < 15)
            adj[i].push_back({'b', i + 16});

        // يسار
        if (col > 0)
            adj[i].push_back({'l', i - 1});

        // يمين
        if (col < 15)
            adj[i].push_back({'r', i + 1});
    }

    // عرض الجيران
    // for (int i = 0; i < 256; i++)
    // {
    //     cout << i << " => ";
    //     for (auto u : adj[i])
    //     {
    //         cout << "{" << u.first << "," << u.second << "}" << " ";
    //     }

    //     cout << ln;
    // }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
    fprintf(stderr, "%s\n", "Starting...");
    solve();
}
