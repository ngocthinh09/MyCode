#include <bits/stdc++.h>
#define problem "test"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).resize(unique(ALL(v)) - (v).begin())
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
using namespace std;
const int N = 2e5;

int n;
ll prefix[N + 5];
string str;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n;
        for (int i=1;i<= n;i++ ){
            cin>>prefix[i];
            prefix[i] += prefix[i - 1];
        }
        cin>>str;
        str = ' ' + str;
        int r = n;
        ll res = 0;
        for (int l=1;l< r;l++ ){
            while (l + 1 < r && str[r] != 'R')
                r--;
            if (str[l] == 'L' && str[r] == 'R'){
                res += prefix[r] - prefix[l - 1];
                str[l] = str[r] = '.';
                r--;
            }
        }

        cout<<res<<'\n';
    }
}