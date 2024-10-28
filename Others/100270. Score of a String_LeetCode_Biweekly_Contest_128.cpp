#include <bits/stdc++.h>
using namespace std;

int scoreOfString(string s) {
    int score = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
        score += abs(static_cast<int>(s[i]) - static_cast<int>(s[i + 1]));
    }
    return score;
}

int main() {
    string s = "hello";
    int score = scoreOfString(s);
    cout << "Score of \"" << s << "\": " << score << endl;
    return 0;
}
