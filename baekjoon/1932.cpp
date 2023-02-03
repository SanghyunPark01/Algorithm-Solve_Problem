#include <iostream>

long long naTriangleDP[500][500] = { 0, };
int main(void) {
	int nDepth;
	std::cin >> nDepth;

	long long nMax = 0;

	for (int i = 0; i < nDepth; i++) {
		for (int j = 0; j <= i; j++) {
			long long nTemp;
			std::cin >> nTemp;
			if (i == 0) {
				naTriangleDP[i][j] = nTemp;
				nMax = nTemp;
			}
			else {
				long long nLocalMax;
				if (j - 1 < 0) {
					nLocalMax = naTriangleDP[i - 1][j];
				}
				else if (j >= i) {
					nLocalMax = naTriangleDP[i - 1][j - 1];
				}
				else {
					nLocalMax = naTriangleDP[i - 1][j] > naTriangleDP[i - 1][j - 1] ? naTriangleDP[i - 1][j] : naTriangleDP[i - 1][j - 1];
				}
				naTriangleDP[i][j] += (nLocalMax + nTemp);
				nMax = nMax > naTriangleDP[i][j] ? nMax : naTriangleDP[i][j];
			}
		}
	}
	std::cout << nMax;

	return 0;
}