#include<bits/stdc++.h>
using namespace std;
int c_min(vector<int> &coins, int n, int amount){
    vector <vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX-1));
    for(int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for(int i=1; i<=n; i++){
        for (int j = 1; j <=amount; i++)
        {
            dp[i][j]=dp[i-1][j];
            if(coins[i-1]<=j){
                dp[i][j]=min(dp[i-1][j], 1+ dp[i][j-coins[i-1]]);
            }
        }
        
    }
    return dp[n][amount];
}
int main(){
    int n, amount;
    cout<<"Enter the number of Coins: ";
    cin>>n;
    vector<int>coins(n);
    for (int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    cout<<"Enter the amount: ";
    cin>>amount;
    cout<<c_min(coins, n, amount);
    return 0;
    
}