#include <iostream>

int two_cnt[1000];

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);

	int n_tc;
	std::cin >> n_tc;

	while (n_tc--)
	{
		int n_elems;
		std::cin >> n_elems;
		
		int two_sum = 0;
		for (int i = 0; i < n_elems; i++)
		{
			int x;
			std::cin >> x;
			if (x == 2)
				two_sum++;
			two_cnt[i] = two_sum;
		}

		int k = 0;
		for (; k < n_elems; k++)
		{
			if (two_cnt[k] * 2 == two_sum)
				break;
		}

		if (k == n_elems)
			std::cout << -1 << '\n';
		else
			std::cout << k + 1 << '\n';
	}
}
