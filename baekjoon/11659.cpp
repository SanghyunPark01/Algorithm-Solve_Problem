#include <iostream>

long long sum[100001] = { 0, };
int ni[100000] = { 0, };
int nj[100000] = { 0, };

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int nN, nM;

	std::cin >> nN >> nM;

	for (int i = 0; i < nN; i++) {
		long long nTemp;
		std::cin >> nTemp;
		sum[i + 1] = sum[i] + nTemp;
	}

	for (int i = 0; i < nM; i++) {
		std::cin >> ni[i] >> nj[i];
	}

	for (int i = 0; i < nM; i++) {
		std::cout << sum[nj[i]] - sum[ni[i] - 1] << "\n";
	}

	return 0;
}