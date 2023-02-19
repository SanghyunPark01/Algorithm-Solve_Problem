#include <iostream>
#include <math.h>

bool arr[1000001] = { false, };
int main(void) {
	int M, N;
	std::cin >> M >> N;
	for (int i = 2; i <= N; i++) {
		arr[i] = true;
	}
	for (int i = 2; i <= std::sqrt(N); i++) {
		if (!arr[i])continue;
		for (int j = i * i; j <= N; j += i) {
			arr[j] = false;
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i])std::cout << i << "\n";
	}

	return 0;
}