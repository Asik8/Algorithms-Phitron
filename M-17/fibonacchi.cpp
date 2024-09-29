#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int fibonacchi(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacchi(n-1)+fibonacchi(n-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<fibonacchi(n)<<endl;
    return 0;
}