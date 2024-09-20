#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define py cout<<"YES\n";
#define pn cout<<"NO\n";

int n, m;
bool vis[1005][1005];
int dis[1005][1005];
vector<pair<int,int>>v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Directions
vector<char> ans;
char ch[1005][1005];
pair<int, int> parent[1005][1005];
vector<char> move_labels = {'R', 'L', 'D', 'U'};
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    dis[i][j] = 0;
    parent[i][j] = {-1, -1};
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        if (ch[a][b] == 'B') {
            py
            while (parent[a][b] != make_pair(-1, -1)) {
                pair<int, int> pp = parent[a][b];
                int pa = pp.first, pb = pp.second;
                for (int i = 0; i < 4; i++) {
                    if (pa + v[i].first == a && pb + v[i].second == b) {
                        ans.pb(move_labels[i]);
                        break;
                    }
                }
                a = pa;
                b = pb;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (char c : ans) cout << c;
            cout << endl;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int ci = a + v[k].first;
            int cj = b + v[k].second;

            if (valid(ci, cj) && !vis[ci][cj] && ch[ci][cj] != '#') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a, b};
            }
        }
    }
    pn
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    ans.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && ch[i][j] == 'A') {
                BFS(i, j);
                return 0; 
            }
        }
    }
    pn
    return 0;
}
