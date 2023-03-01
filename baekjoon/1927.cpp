#include <iostream>
#include <queue>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::priority_queue<int> pqQ;
	for (int i = 0; i < N; i++) {
		int nTemp;
		std::cin >> nTemp;
		if (nTemp == 0) {
			if (pqQ.empty()) {
				std::cout << "0";
			}
			else {
				std::cout << -pqQ.top();
				pqQ.pop();
			}
			std::cout << "\n";
		}
		else {
			pqQ.push(-nTemp);
		}
	}

	return 0;
}