#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];

int coinChange(int amount, int i, int coins[])
{
    if(amount==0) return 1;
    if(i<0 || amount <0) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];
    if(amount>=coins[i]){
        int op1=coinChange(amount-coins[i], i, coins);
        int op2=coinChange(amount, i-1, coins);
        return dp[i][amount]= op1+op2;
    }else{
        return dp[i][amount]= coinChange(amount, i-1, coins);
    }
}
int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cout<<"Enter the number of coins: ";
    cin>>n;
    int coins[n], amount;
    for (int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    cin>>amount;
    cout<<coinChange(amount, n-1, coins);
    return 0;

    
}