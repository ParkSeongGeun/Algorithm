#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll N, M, P, power;
ll MAP[501];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M >> P;
    power = P;
    for(int i=0;i<N;i++){
        int item = 0;
        for(int j=0;j<M;j++){
            cin >> MAP[j];
            if(MAP[j] == -1){
                item++;
                MAP[j] = 0;
            }
        }
        sort(MAP, MAP+M);
        // for(int j=0;j<M;j++){
        //     cout << MAP[j] << " ";
        // }
        //cout << "\n";
        for(int j=0;j<M;j++){
            while(item>0&&power<MAP[j]){
                power *= 2;
                item--;
            }
            if(MAP[j]>power){
                cout << "0" << "\n";
                return 0;
            }
            else{
                power = power + MAP[j];
            }
            //cout << "power : " << power << "\n";
        }
        while(item--){
            power *= 2;
        }
    }
    cout << "1" << "\n";
    return 0;
}