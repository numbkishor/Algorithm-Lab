#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int knap(int capacity, int i, int weight[], int value[])
{
    if(i<0 || capacity==0) return 0;
    if(dp[i][capacity]!=-1){
        return dp[i][capacity];
    }

     if(capacity>=weight[i]){
        
         int op1=knap(capacity-weight[i], i-1, weight, value)+ value[i];
         int op2=knap(capacity, i-1, weight, value);
         return dp[i][capacity] =max(op1,op2);
     }else{
        return dp[i][capacity]=knap(capacity, i-1, weight, value);
     }

}
int main(){
    memset(dp, -1, sizeof(dp));
    int capacity, n ;
    cout<<"Enter the capacity: ";
    cin>>capacity;
    cout<<"Enter the number of items: ";
    cin>>n;
   int weight[n], value[n];
    cout<<"Enter the weights: ";
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }
    cout<<"Enter the value: ";
    for(int i=0; i<n; i++){
        cin>>value[i];
    }
    cout<<knap(capacity, n-1, weight, value);
    return 0;
}