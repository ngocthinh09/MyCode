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

bool check(string str){
    if ((int)str.length() <= 2) return false;
    if (str[0] != '1' || str[1] != '0') return false;

    string digit = "";
    for (int i=2;i< (int)str.length();i++ )
        digit += str[i];

    int num = 0;
    for (int i=0;i< (int)digit.length();i++ ){
        num = num * 10 + digit[i] - '0';
    }

    if (num < 2)    return false;

    if (to_string(num) != digit)    return false;
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        string str; cin>>str;
        cout<<(check(str) ? "YES" : "NO")<<'\n';
    }
}