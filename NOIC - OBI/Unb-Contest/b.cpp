#include <bits/stdc++.h>
using namespace std;

#define el "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    _;

    string num;

    cin >> num;

    if(num.size() == 2){
        cout << num[0] << " " << num[1] << el;
        return 0;
    }else if(num.size() == 4){
        cout << num[0] << num[1] << " " << num[2] << num[3] << el;
        return 0;
    }else if(num[1] == '0' || num[2] == '0'){
        if(num[1] == 0){
            cout << num[0] << num[1] << " " << num[2] << el;
        }else{
            cout << num[0] << " " << num[1] << num[2] << el;
        }
        return 0;
    }

    cout << "-1" << el;



    return 0;
}