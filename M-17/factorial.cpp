#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int factorial(int n)
{
    if(n==0) return 1;
    return n*factorial(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}