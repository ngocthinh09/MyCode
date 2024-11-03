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
const int N = 200;

int n;
string str;
int dp[N + 5][N + 5][N + 5];
int num,val[N + 5],cnt[N + 5];

int solve(int l,int r,int k){
    if (dp[l][r][k] != -1)  return dp[l][r][k];
    if (l > r)  return 0;
    if (l == r)
        return (k + cnt[l])*(k + cnt[l]);
    
    dp[l][r][k] = max(dp[l][r][k],solve(l + 1,r,0) + (k + cnt[l])*(k + cnt[l]));

    for (int i=l + 1;i<= r;i++ )
        if (val[l] == val[i])
            dp[l][r][k] = max(dp[l][r][k],solve(l + 1,i - 1,0) + solve(i,r,k + cnt[l]));

    return dp[l][r][k];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp","r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n;
    cin >> str;
    str = ' ' + str;

    str[0] = '#';
    for (int i=1;i<= n;i++ ){
        if (str[i] == str[i - 1])
            cnt[num]++;
        else{
            val[++num] = str[i] - '0';
            cnt[num] = 1;
        }
    }

    // for (int i=1;i<= num;i++ ){
    //     cerr << val[i] <<' ' << cnt[i] <<'\n';
    // }

    memset(dp,-1,sizeof(dp));
    cout << solve(1,num,0);
}