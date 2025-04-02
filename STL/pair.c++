#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,int>p1={1,2};
    pair<int,pair<int,int>>p2={3,{4,5}};
    pair<pair<int,int>,pair<int,int>>p3={{6,7},{8,9}};
    pair<string,pair<int,pair<int,pair<string,int>>>>p4={"ten",{11,{12,{"thirteen",14}}}};

    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p2.second.second<<endl;
    cout<<p4.second.first<<endl;
    cout<<p4.second.second.second.first<<endl;
}