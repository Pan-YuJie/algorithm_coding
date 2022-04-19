#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100001;
vector<int> v[MAXN]; 
double sum = 0.0; 
int t[MAXN]; 
int N;
double Z, r;

void Dfs(int x, double power) {
	if (t[x] != 0) {
		sum += (power * t[x]);
        return;
	}
	
	for (int i = 0; i < v[x].size(); i++) {
		Dfs(v[x][i], r * power);
	}
	
}

int main() {
  
  
	cin >> N >> Z >> r;

	r = (100 - r) / 100.0;
	
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		
		if (!k) {
			int b;
			cin >> b;
			t[i] = b;
		} 
		else {
			for (int j = 0; j < k; j++) {
			  
				int x;
				cin >> x;
				v[i].push_back(x);
				
			}
		}
		
	}

	Dfs(0, Z);

	cout << (int) sum;
	return 0;
}