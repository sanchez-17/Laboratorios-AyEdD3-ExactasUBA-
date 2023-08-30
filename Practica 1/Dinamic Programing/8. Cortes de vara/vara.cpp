#include "../../backtracking/utilities.h"
int N,L;
vector<int> C;vector<bool> usado;

int s(int i,int j, int cnt ){
	if(cnt==N) return j-i;
	else {
		int min_coste = 1e7;
		forn(k,N) if(!usado[k]){
			usado[k]=true;
			int coste_k = s(i,C[k],cnt+1) + s(C[k],j,cnt+1);
			min_coste = coste_k < min_coste ? coste_k : min_coste;
			usado[k]=false;
		}
		return (j-i) + min_coste;
	}
		
}

int main(){
	cin >> N >> L; C.rz(N);usado.rz(N,false);vector<int> I;
	forn(i,N) cin >> C[i];
	cout << s(0,L,0) << endl;
	return 0;
	
}
