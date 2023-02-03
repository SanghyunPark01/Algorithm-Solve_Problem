#include <iostream>
#include <algorithm>

int N;
int A[100000];
int A_prime[100000];

int Find(int n);
int main(void) {

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::sort(A, A + N);
	int M;
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> A_prime[i];
	}
	for (int i = 0; i < M; i++) {
		std::cout << Find(A_prime[i]) << "\n";
	}

	return 0;
}
int Find(int n) {
	int Start = 0;
	int End = N - 1;

	while (Start <= End) {
		int Middle = (Start + End) / 2;
		if (A[Middle] == n)return 1;
		else if (A[Middle] < n)Start = Middle + 1;
		else End = Middle - 1;
	}
	return 0;
}
