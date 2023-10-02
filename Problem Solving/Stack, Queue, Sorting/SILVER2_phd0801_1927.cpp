#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        if(x==0){
            if(q.empty()){
                cout << "0" << "\n";
            }
            else{
                cout << q.top() <<"\n";
                q.pop();
            }
        }
        else{
            q.push(x);
        }
    }
    return 0;
}