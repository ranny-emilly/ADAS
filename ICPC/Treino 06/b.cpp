#include<bits/stdc++.h>
using namespace std;

#define el "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){

    _;

    int n, k, sum = 0, qtdt = 0;
    cin >> n >> k;
    int menor = 10e18;


    vector<long long>j(n+1);
    vector<long long>pre(n+1);

    j[0] = 0;
    pre[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> j[i];
        pre[i] = pre[i-1]+j[i];
    }



    for(int i = 1; i <= n - k + 1; i++){
            sum =pre[i+k-1]-pre[i-1];
            if(menor > sum){
                menor = sum;
                qtdt = i;
            }
        }

    cout << qtdt << el;


    


    return 0;
}