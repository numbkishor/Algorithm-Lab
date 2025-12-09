#include<bits/stdc++.h>
using namespace std;

struct activity
{
    int st;
    int et;
};

bool custom(activity a1, activity a2){
    return a1.et<a2.et;
}


int main ()
{
    int n;
    cout<<"Enter the number of activity: ";
    cin>>n;
    vector<activity> t(n);
    for(int i=0; i<n; i++){
        cin>>t[i].st>>t[i].et;
    }
    sort(t.begin(), t.end(), custom);
    int prevet=0;
    int selected=0;
    for (int i = 0; i < n; i++)
    {
        if(t[i].st>=prevet){
            selected++;
            prevet=t[i].et;
        }
    }
    cout<<selected<<endl;
    

} 
