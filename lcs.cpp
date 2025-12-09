#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int lcs(string &a, string  &b, int i, int j){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i]==b[j]){
        return dp[i][j]= 1+lcs(a,b,i-1, j-1);
    }else {
        int op1=lcs(a,b,i-1, j);
        int op2=lcs(a,b,i, j-1);
        return dp[i][j] = max(op1, op2);

    }
}
int main(){
    string a,b;
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));
    int n=a.size()-1;
    int m=b.size()-1;
    cout<<lcs(a,b,n,m);
    return 0;

}