#include <iostream>

using namespace std;

string s;

int main(){
    int cnt = 1;
    while(1){
        cin >> s;
        if(s=="0"){
            break;
        }
        cout << cnt << ". ";
        if(!(s[0]=='1')||!(s[s.size()-1]=='2')){
            cout << "NOT" << "\n";
        }
        for(int i=0;i<s.size();i++){
            
        }
    }
}