#include <iostream>
#include <queue>

void Test(void);
int main(void) {
	int nTestCase;
	std::cin >> nTestCase;
	for (int i = 0; i < nTestCase; i++) {
		Test();
	}

	return 0;
}
void Test(void) {
	int N, M;
	std::cin >> N >> M;
	
	std::queue<std::pair<int, int>> qQ;
	std::priority_queue<int> qImportanceArrange;

	for (int i = 0; i < N; i++) {
		int nImportance;
		std::cin >> nImportance;
		qQ.push({ i,nImportance });
		qImportanceArrange.push(nImportance);
	}
	int nCnt = 1;
	while (qQ.size() >= 0) {
		int nIndex = qQ.front().first;
		int nValue = qQ.front().second;
		if (qImportanceArrange.top() == nValue) {
			qImportanceArrange.pop();
			if (nIndex == M) {
				std::cout << nCnt << "\n";
				break;
			}
			nCnt++;
		}
		else {
			qQ.push({ nIndex,nValue });
		}
		qQ.pop();
	}

}