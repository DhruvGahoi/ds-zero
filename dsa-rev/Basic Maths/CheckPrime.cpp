#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number : " ;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n*n; i++) {
        if(n % i == 0) {
            cnt++;
            if((n%i) != i) cnt++;
        }
    }
    if(cnt == 2) cout << "true";
    else cout << "false";

    return 0;
}