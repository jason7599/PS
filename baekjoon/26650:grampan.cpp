#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int a_cnt = 0;
	long long ans = 0;
	char n_char = 'A';

	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];

		if (c == 'A')
		{
			if (i and str[i - 1] == 'A')
				a_cnt++;
			else
				a_cnt = 1;
				
			n_char = 'A';
		}
		else if (c == n_char)
		{
			if (c == 'Z')
				ans += a_cnt;
		}
		else if (i and c == n_char + 1)
		{
			if (++n_char == 'Z')
				ans += a_cnt;
		}
		else
		{
			a_cnt = 0;
			n_char = 'A';
		}
	}

	cout << ans;
	return 0;
}