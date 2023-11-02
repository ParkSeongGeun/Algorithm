#include <iostream>
#include <algorithm>

using namespace std;

int N,A,B;
int first[2001];
int second[2001];
int res;

int main(){
    cin >> N >> A >> B;
    int indexa, indexb;
    indexa = A-1;
    indexb = B-1;
    for(int i=0;i<A;i++){
        cin >> first[i];
    }
    for(int i=0;i<B;i++){
        cin >> second[i];
    }
    sort(first, first+A);
    sort(second, second+B);
    if(N%2==1){
        res += first[indexa];
        indexa-=1;
        N-=1;
    }
    while(N>0){
        if(indexb<0){
            res += first[indexa] + first[indexa-1];
            indexa-=2;
        }
        else if(indexa<1){
            res += second[indexb];
            indexb-=1;
        }
        else{
            if(second[indexb]>first[indexa]+first[indexa-1]){
                res += second[indexb];
                indexb-=1;
            }
            else{
                res += first[indexa]+first[indexa-1];
                indexa-=2;
            }
        }
        N-=2;
    }
    cout << res << "\n";
    return 0;
}