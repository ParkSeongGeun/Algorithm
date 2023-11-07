#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#define INPUT 100000000

using namespace std;

int C;
string s;
unsigned long long N, T, L;
unsigned long long cnt;

int main(){
    cin >> C;
    for(int i=0;i<C;i++){
        cin >> s >> N >> T >> L;
        if (s == "O(N)") {
		    cnt = N * T;
		    if (cnt <= (L * INPUT)) {
			    cout << "May Pass.\n";
		    }
		    else    {
			    cout << "TLE!\n";
		    }
	    }
	    else if (s == "O(N^2)") {
		    if (N >= 31623) {
			    cout << "TLE!\n";
		    }
		    else {
			    cnt = (N * N * T);
			    if (cnt <= (L * INPUT)) {
				    cout << "May Pass.\n";
			    }
			    else {
				    cout << "TLE!\n";
			    }
		    }
	    }
	    else if (s == "O(N^3)") {
		    if (N >= 1001) {
			    cout << "TLE!\n";
		    }
		    else {
			    cnt = (N * N * N * T);
			    if (cnt <= (L * INPUT)) {
				    cout << "May Pass.\n";
			    }
			    else {
				    cout << "TLE!\n";
			    }
		    }
	    }
	    else if (s == "O(2^N)") {
		    if (N >= 30) {
			    cout << "TLE!\n";
		    }
		    else {
			    cnt = (unsigned long long)pow(2, N) * T;
			    if (cnt <= (L * INPUT)) {
				    cout << "May Pass.\n";
			    }
			    else {
				    cout << "TLE!\n";
			    }
		    }
	    }
	    else if (s == "O(N!)") {
		    if (N >= 13) {
			    cout << "TLE!\n";
		    }
		    else {
			    cnt = T;
			    for (unsigned long long i = 1; i <= N; i++) {
				    cnt *= i;
			    }
			    if (cnt <= (L * INPUT)) {
				    cout << "May Pass.\n";
			    }
			    else {
				    cout << "TLE!\n";
			    }
		    }
	    }
    }
    return 0;
}