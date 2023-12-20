#include <bits/stdc++.h>

using namespace std;

string input, s1;
int n;
vector<string> s;
vector<string> cut;

int main(){
    cin >> n;
    cin >> input;
    size_t idx = input.find('*');
    size_t end = input.size();
    cut.push_back(input.substr(0, idx));
    cut.push_back(input.substr(idx+1, end));
    for(int i=0;i<n;i++){
        cin >> s1;
        s.push_back(s1);
    }
    for(int i=0; i< s.size(); i++){
        size_t pos1, pos2;
        if(cut[0].length() + cut[1].length() > s[i].length()){
            cout << "NE" <<"\n";
            continue;
        }
        pos1 = s[i].find(cut[0]);
        if(pos1 != 0){
            cout << "NE" <<"\n";
            continue;
        }
        pos2 = s[i].substr(s[i].size()-cut[1].size(), s[i].size()).find(cut[1]);
        if(pos2 != 0){
            cout << "NE" <<"\n";
            continue;
        }
        cout << "DA" <<"\n";
    }
    return 0;
}