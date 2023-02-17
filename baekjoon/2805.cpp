#include <iostream>

int main(void) {
	int N, M;
	std::cin >> N >> M;

	int* Tree = new int[N];
	int max = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> Tree[i];
		max = max > Tree[i] ? max : Tree[i];
	}
	int start = 0;
	int end = max;
	
	int maxHeight = 0;

	while (start <= end) {
		long long GetTree = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if ((Tree[i] - mid) > 0) {
				GetTree += Tree[i] - mid;
			}
		}
		if (GetTree < M)end = mid - 1;
		else if(GetTree == M){
			maxHeight = mid;
			break;
		}
		else {
			start = mid + 1;
			maxHeight = maxHeight > mid ? maxHeight : mid;
		}
	}
	std::cout << maxHeight;

	delete[] Tree;

	return 0;
}