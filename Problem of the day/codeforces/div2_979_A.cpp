#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, ip, ans;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        if (n > 1) { 
            sort(a.begin(), a.end());
            int temp = a[n-1];
            a[n-1] = a[1];
            a[1] = temp;
        }

        /*for(auto u : a){
            cout << u << " ";
        }
        cout << endl;*/

        vector<int> b(n);
        vector<int> c(n);
        int d = a[0];
        int e = a[0];
        for(int i = 0; i < n; i++){
            d = min(a[i], d);
            b[i] = d;
            e = max(a[i], e);
            c[i] = e;
        }

        for(int i = 0; i < n; i++){
            ans += (c[i] - b[i]);
        }

        cout << ans << endl;
    }
}
