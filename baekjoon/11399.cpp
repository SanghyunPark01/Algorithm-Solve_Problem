#include <iostream>
#include <algorithm>
int main(void) {
	int nSize;
	std::cin >> nSize;
	
	int nTime[1001] = { 0, };
	for (int i = 0; i < nSize; i++) {
		std::cin >> nTime[i];

	}

	std::sort(nTime, nTime + nSize);

	int nTotal = 0;
	int nResult = 0;
	for (int i = 0; i < nSize; i++) {
		nTotal += nTime[i];
		nResult += nTotal;
	}

	std::cout << nResult;

	return 0;
}