#include <iostream>

long long nN[100000] = { 0, };
long long nSum[100000] = { 0, };
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	long long nMax = 0;

	for (int i = 0; i < N; i++) {
		std::cin >> nN[i];
		if (i == K-1) {
			for (int j = i - K + 1; j <= i; j++) {
				nSum[0] += nN[j];
			}
			nMax = nSum[0];
		}
		else if (i > K - 1) {
			nSum[i - K + 1] = nSum[i - K] + nN[i] - nN[i - K];
			nMax = nMax > nSum[i - K + 1] ? nMax : nSum[i - K + 1];
		}
	}
	
	std::cout << nMax;

	return 0;
}