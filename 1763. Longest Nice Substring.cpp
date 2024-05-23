#include<bits/stdc++.h>
using namespace std;


string longestNiceSubstring(string s){
    //Base case.
    if(s.size()<2) return "";

    unordered_set<char>uset(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(uset.count(tolower(s[i]))==true && uset.count(toupper(s[i]))==true) continue;

        string previous=longestNiceSubstring(s.substr(0,i));
        string next= longestNiceSubstring(s.substr(i+1));

        return previous.size()>=next.size()?previous:next;
    }
    return s;
}

int main()
{
    string s;
    cin>>s;
    cout<<longestNiceSubstring(s)<<endl;
}
