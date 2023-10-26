#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int k;

int main(){
    cin >> k;
    stack<char> q;
    while(1){
        if(k==1||k==2){
            if(k==1){
                q.push('4');
                break;
            }
            else{
                q.push('7');
                break;
            }
        }
        if((k-1)%2==0){
            q.push('4');
            k = (k-1)/2;
        }
        else if((k-2)%2==0){
            q.push('7');
            k = (k-2)/2;
        }
    }
    while(!q.empty()){
        cout << q.top();
        q.pop();
    }
    cout << "\n";
    return 0;
}