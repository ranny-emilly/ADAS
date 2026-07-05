#include <bits/stdc++.h>
using namespace std;

#define el "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    _;
    int n, q;
    vector <int> vec;
    
    cin >> n >> q;
    int a = n;

    while(n--){
        int y;
        cin >> y;
        vec.push_back(y);
    }
    vector <int> pre(a + 1);

    pre[0] = 0;

    for (int i = 0; i <= a; i++) {
        pre[i + 1] = pre[i] ^ vec[i];
      
    }


    while(q--){
        int a, b;
        cin >> a >> b;
        int res = pre[b] ^ pre[a-1];
        cout << res << el; 

    }



    return 0;
}
