#include <iostream>

long long FIBO[91];
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int nNum;
	std::cin >> nNum;

	FIBO[0] = 0;
	FIBO[1] = 1;

	int n = 2;
	while (nNum >= n) {
		if (nNum == 0 || nNum == 1)break;
		FIBO[n] = FIBO[n - 1] + FIBO[n - 2];
		n++;
	}

	std::cout << FIBO[nNum];

	return 0;
}