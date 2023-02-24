#include <iostream>
#include <queue>
int main(void) {
	int N;
	std::cin >> N;
	std::queue<int> qQ;
	for (int i = 0; i < N; i++) {
		qQ.push(i+1);
	}
	int cnt = 1;
	while (qQ.size() >= 2) {
		if (cnt % 2 == 0) {
			qQ.push(qQ.front());
		}
		qQ.pop();
		cnt++;
	}
	std::cout << qQ.front();
	return 0;
}