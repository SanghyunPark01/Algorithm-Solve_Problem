#include <iostream>
#include <vector>
std::vector<int> list[101];
bool bVisit[101] = { false, };
int nCnt = 0;
void DFS(int n);
int main(void) {
	int nComNum, nPairNum;
	std::cin >> nComNum >> nPairNum;
	for (int i = 0; i < nPairNum; i++) {
		int nTemp1, nTemp2;
		std::cin >> nTemp1 >> nTemp2;
		list[nTemp1].push_back(nTemp2);
		list[nTemp2].push_back(nTemp1);
	}

	DFS(1);
	std::cout << nCnt;

	return 0;
}
void DFS(int n) {
	bVisit[n] = true;
	for (int i = 0; i < list[n].size(); i++) {
		int nTemp = list[n][i];
		if (!bVisit[nTemp]) {
			nCnt++;
			DFS(nTemp);
		}
	}
}