#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> vt;
	int a1, a2;
	int len;
	int result;
	int count = 2;
	int i = 1;
	cin >> a1 >> a2 >> len;
	vt.push_back(a1);
	vt.push_back(a2);
	while (true)
	{
		
		if (count >= len)
			break;
		result = a1 * a2;
		if (result < 10)
		{
			vt.push_back(result);
			count++;
		}
		else
		{
			string str = to_string(result);
			for (int i = 0; i < str.length(); i++)
			{
				int num = str[i] - '0';
				vt.push_back(num);
				count++;
			}
			
		}
		a1 = vt[i];
		a2 = vt[i + 1];
		i++;
	}
	for (int i = 0; i < len; i++)
		if (i != len-1)
			cout << vt[i] << " ";
		else
			cout << vt[i];
	return 0;
}
