#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
ll n;

bool check(ll a)
{
    if(a == n) return true;
    else if(a>n) return false;
    else return check(a*10) || check(a*20);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        bool f = check(1);   
        if(f) py
        else pn
    }
    return 0;
}