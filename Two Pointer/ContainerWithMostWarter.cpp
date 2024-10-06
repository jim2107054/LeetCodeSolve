#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&v){
    int height,maximum=INT_MIN, i=0, j = v.size()-1;

    while(i<j){
        height = min(v[i],v[j]);
        maximum = max(maximum,((height*(j-i))));

        if(v[i]<v[j]) i++;
        else j--;
    }
    return maximum;
}

int main()
{
    //cout<<"Hello"<<endl;
    int n,a;
    cin>>n;
    vector<int>v(n);
    while(n--){
        cin>>a;
        v.push_back(a);
    }

    cout<<"Maximum water is: "<<solve(v)<<endl;

    return 0;
}