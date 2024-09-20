
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+20;
int par[N];
int level[N];

void DSU_initialize(int n)
{
    for(int i=0;i<n;i++) 
    {
        par[i] = -1;
        level[i] = 0;
    }
}

int find(int n)
{
    if(par[n] == -1) return n;
    int p = find(par[n]);
    par[n] = p;
    return p;
}

void DSU_Union_by_level(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if(level[pa]> level[pb]) par[pb] = pa;
    else if(level[pa]< level[pb]) par[pb] = pa;
    else
    {
        par[pa] = pb;
        level[pb]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    DSU_initialize(7);
    DSU_Union_by_level(1,2);
    DSU_Union_by_level(2,3);
    DSU_Union_by_level(4,5);
    DSU_Union_by_level(5,6);
    cout<<find(1)<<endl;
    cout<<find(4)<<endl;
    DSU_Union_by_level(1,4);
    cout<<find(1)<<endl;
    cout<<find(4)<<endl;
    return 0;
}