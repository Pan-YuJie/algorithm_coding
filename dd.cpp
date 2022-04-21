#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> a;
	int n = 0, i = 0, k = 1, m = 3, p = 0;

	cin >> n;
	for (i = 0;i < n;i++) {	 
		a.push_back(i + 1);
	}
	p = k - 2;				
	while (a.size() > 1) {	
		for (i = 0;i < m;i++) {
			if (p+1 >= a.size())	{ 
				p = 0;
			}
			else {
				p++;
			}
		}
		a.erase(a.begin() + p);
		p--;
	}
	cout << a[0];
}
