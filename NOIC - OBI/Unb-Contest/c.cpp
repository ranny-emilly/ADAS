#include <bits/stdc++.h>
using namespace std;

#define el "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    _;

    long long k, n, max = 0, ac = 0, mult = 0;

    cin >> k >> n;

    vector<int>tres;
    vector <int> play;

    for(int i =0; i < k; i++){
        cin >> play[i];
    }
    for(int i = 0; i < k; i++){
        // 1 4 -5 6 19 20 -1 4 5 -3 0 10
       tres[i] = play [i];

       cout << tres[i];
       
       if(tres[i] > max){
        max = tres[i];
        cout << max;
       }
       
       if(i%n == 0){
        ac+=max;
        tres.clear();
        mult++;
       }

       i = 0;
       i = i+n*mult;
    }

    cout << ac << el;

    return 0;
}