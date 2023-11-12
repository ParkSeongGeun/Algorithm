#include <iostream>
#include <stack>

using namespace std;
int K;
int cnt;
stack<int> s;

int main()
{
    cin >> K;
    for(int i=0;i<K;i++){
        cin >> cnt;
        if(cnt==0){
            s.pop();
        }
        else{
            s.push(cnt);
        }
    }
    if(s.empty()){
        cout << "0" << "\n";
    }
    else{
        cout << s.top() << "\n";
    }
    return 0;
}
