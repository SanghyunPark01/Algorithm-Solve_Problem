#include <iostream>

int Count[100001] = { 0, };
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		std::cin >> temp;
		Count[temp] += 1;
	}
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < Count[i]; j++) {
			std::cout << i << "\n";
		}
	}

	return 0;
}