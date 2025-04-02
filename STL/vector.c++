#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);//emplace_back is faster than push_back.

    vector<pair<int,int>>v2={{1,2},{3,4},{5,6}};
    v2.emplace_back(7,8);//for pair also we don't need to use {} brackets.
    v2.push_back({9,10});//we can use {} brackets in push_back.

    for(auto i:v2){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    // vector<int>v1={1,2,3,4,5};
    // vector<pair<int,int>>v2={{1,2},{3,4},{5,6}};
    // vector<vector<int>>v3={{1,2,3},{4,5,6},{7,8,9}};
    // vector<pair<int,pair<int,int>>>v4={{1,{2,3}},{4,{5,6}},{7,{8,9}}};
    // vector<vector<pair<int,int>>>v5={{{1,2},{3,4}},{{5,6},{7,8}},{{9,10},{11,12}}};

    // cout<<v1[0]<<" "<<v1[1]<<" "<<v1[2]<<" "<<v1[3]<<" "<<v1[4]<<endl;
    // cout<<v2[0].first<<" "<<v2[0].second<<endl;
    // cout<<v3[0][0]<<" "<<v3[0][1]<<" "<<v3[0][2]<<endl;
    // cout<<v4[0].first<<" "<<v4[0].second.first<<" "<<v4[0].second.second<<endl;
    // cout<<v5[0][0].first<<" "<<v5[0][0].second<<" "<<v5[0][1].first<<" "<<v5[0][1].second<<endl;

    return 0;
}