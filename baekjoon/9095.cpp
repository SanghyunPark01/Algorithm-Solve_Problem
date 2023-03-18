#include <iostream>

int main(void) {
	int nSize;
	std::cin >> nSize;
	
	int nResultArray[12] = { 0, };
	nResultArray[0] = 0;
	nResultArray[1] = 1;
	nResultArray[2] = 2;
	nResultArray[3] = 4;

	for (int i = 4; i < 12; i++) {
		nResultArray[i] = nResultArray[i - 1] + nResultArray[i - 2] + nResultArray[i - 3];
	}

	for (int i = 0; i < nSize; i++) {
		int nTemp;
		std::cin >> nTemp;
		std::cout << nResultArray[nTemp] << "\n";
	}

	return 0;
}