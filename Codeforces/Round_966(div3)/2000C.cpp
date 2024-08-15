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

int n,m,a[N + 5];
string charr;
vector<int> value;
map<int,int> lastNum,lastChar;


bool check(const string &str){
    if (n != (int)str.length() - 1) return false;
    int limit = min(n,(int)str.length() - 1);
    lastNum.clear();
    lastChar.clear();

    for (int i=1;i<= limit;i++ ){
        int lastPosNum = lastNum[a[i]];
        if (lastPosNum != 0){
            if (str[i] != str[lastNum[a[i]]])
                return false;
        }
        lastNum[a[i]] = i;

        int lastPosChar = lastChar[str[i] - 'a'];
        if (lastPosChar != 0){
            if (a[i] != a[lastChar[str[i] - 'a']])
                return false;
        }
        lastChar[str[i] - 'a'] = i;
    }

    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n;
        for (int i=1;i<= n;i++ )
            cin>>a[i];
            
        cin>>m;
        for (int i=1;i<= m;i++ ){
            cin>>charr;
            charr = ' '  + charr;
            cout<<(check(charr) ? "YES" : "NO")<<'\n';
        }
        
    }
}