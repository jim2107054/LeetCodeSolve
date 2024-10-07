#include<bits/stdc++.h>
using namespace std;

//split a string into word
vector<string> split(string s){
    vector<string>ans;
    stringstream ss(s);
    string word;
    while(ss>>word){
        ans.push_back(word);
    }
    return ans;
}

bool solve(string &s1, string &s2){
    vector<string>word1 = split(s1);
    vector<string>word2 = split(s2);

    //We want s1 as the smallest string among them.
    if(s1.size()>s2.size()){
        swap(s1,s2);
    }

    int i=0,j=0;

    //prefix word matching
    while(i<s1.size() && s1[i]==s2[i]) i++;
    //suffix word matching
    while(j<s1.size() && s1[s1.size()-1-j]==s2[s2.size()-1-j]) j++;
    
    return i+j>=s1.size();
}

int main()
{
    string s1,s2;
    cout<<"Enter your first string ";
    getline(cin,s1);
    cout<<"Enter your second string ";
    getline(cin,s2);

    cout<<solve(s1,s2);
}