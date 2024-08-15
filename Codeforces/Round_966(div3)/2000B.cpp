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
int a[N + 5];
bool used[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>n;
        for (int i=1;i<= n;i++ )    used[i] = false;
        for (int i=1;i<= n;i++ )
            cin>>a[i];  

        used[a[1]] = true;
        bool flag = true;
        for (int i=2;i<= n;i++ ){
            bool check = false;
            
            check |= (a[i] > 1 && used[a[i] - 1]);
            check |= (a[i] < n && used[a[i] + 1]);

            if (!check){
                flag = false;
                break;
            }
            used[a[i]] = true;
        }

        cout<<(flag ? "YES" : "NO")<<'\n';
    }
}