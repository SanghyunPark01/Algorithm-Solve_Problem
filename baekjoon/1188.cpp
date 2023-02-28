#include <iostream>
int nGCD(int a, int b);
int main(void) {
	int N, M;
	std::cin >> N >> M;

	std::cout << M - nGCD(N, M);

	return 0;
}
int nGCD(int n1, int n2) {
	int nMin = n1 < n2 ? n1 : n2;
	int nMax = n1 > n2 ? n1 : n2;
	while (nMin != 0) {
		int temp = nMin;
		nMin = nMax % nMin;
		nMax = temp;
	}
	return nMax;
}