#include <iostream>
#include <stack>

using namespace std;

stack<int> q;
int N;

void go(int a){
    if(a==1){
        int num;
        cin >> num;
        q.push(num);
    }
    else if(a==2){
        if(!q.empty()){
            cout << q.top() << "\n";
            q.pop();
        }
        else{
            cout << "-1" << "\n";
        }
    }
    else if(a==3){
        cout << q.size() << "\n";
    }
    else if(a==4){
        if(!q.empty()){
            cout << "0" << "\n";
        }
        else{
            cout << "1" << "\n";
        }
    }
    else{
        if(!q.empty()){
            cout << q.top() << "\n";
        }
        else{
            cout << "-1" << "\n";
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin >> N;
    int a;
    for(int i=0;i<N;i++){
        cin >> a;
        go(a);
    }
    return 0;
}