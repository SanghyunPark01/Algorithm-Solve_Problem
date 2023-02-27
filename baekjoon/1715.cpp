#include <iostream>
#include <queue>
int main(void) {
	int N;
	std::cin >> N;

	std::priority_queue<int> pPQ;
	for (int i = 0; i < N; i++) {
		int nTemp;
		std::cin >> nTemp;
		pPQ.push(-nTemp);
	}

	int nRes = 0;
	while (pPQ.size() > 1) {
		int nTemp1, nTemp2;
		nTemp1 = pPQ.top();
		pPQ.pop();
		nTemp2 = pPQ.top();
		pPQ.pop();
		pPQ.push(nTemp1 + nTemp2);
		nRes -= (nTemp1 + nTemp2);
	}
	std::cout << nRes;

	return 0;
}