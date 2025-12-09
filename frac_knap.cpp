#include<bits/stdc++.h>
using namespace std;

double frac_knap(vector<int> &weight, vector<int> &value, int n, int cap){
    vector<pair <double, pair< int, int>>>item(n);
    for (int i = 0; i < n; i++)
    {
        item[i]={(double)value[i]/weight[i],{value[i], weight[i]}};
    }
    sort(item.rbegin(), item.rend());
    double totalv=0.0;
    int rem_cap=cap;
    for (int i = 0; i < n; i++)
    {
        int val=item[i].second.first;
        int wt=item[i].second.second;
        if(wt<=rem_cap){
            totalv+=val;
            rem_cap-=wt;

        }else{
            totalv+=val*((double)rem_cap/wt);
        }
    }
    return totalv;
    
}

int main (){
    int n, cap;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<int> value (n), weight(n);
    cout<<"Enter the weights: ";
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    cout<<"Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin>>value[i];
    }

    cout<<"Enter the capacity: ";
    cin>>cap;

    double max=frac_knap(weight, value, n, cap);
    cout<<max;
    return 0;
    
}