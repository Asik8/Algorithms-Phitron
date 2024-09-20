#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+20;
int par[N];
int group_size[N];

void DSU_initialize(int n)
{
    for(int i=0;i<n;i++) 
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}

int find(int n)
{
    if(par[n] == -1) return n;
    int p = find(par[n]);
    par[n] = p;
    return p;
}

void DSU_Union_by_Size(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if(group_size[pa]> group_size[pb])
    {
        par[pb] = pa;
        group_size[pa]+= group_size[pb];
    }
    else
    {
        par[pa] = pb;
        group_size[pb]+= group_size[pa];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    DSU_initialize(7);
    DSU_Union_by_Size(1,2);
    DSU_Union_by_Size(2,3);
    DSU_Union_by_Size(4,5);
    DSU_Union_by_Size(5,6);
    cout<<find(1)<<endl;
    cout<<find(4)<<endl;
    DSU_Union_by_Size(1,4);
    cout<<find(1)<<endl;
    cout<<find(4)<<endl;
    return 0;
}