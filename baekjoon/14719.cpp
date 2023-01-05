#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int nH, nW;
	std::cin >> nH >> nW;

	std::vector<int> v_nBlock;
	for (int i = 0; i < nW; i++) {
		int nTemp;
		std::cin >> nTemp;
		if (nTemp > nH)nTemp = nH;
		v_nBlock.push_back(nTemp);
	}
	/*for (int i = 0; i < v_nBlock.size(); i++) {
		std::cout << v_nBlock[i] << std::endl;

	}*/
	
	int nRainSum = 0;
	for (int i = 1; i < nW - 1; i++) {
		int nMaxLeft = 0;
		int nMaxRight = 0;
		int nLocalRain = 0;

		//nMaxLeft = *std::max_element()
		for (int j = 0; j < i; j++) {
			nMaxLeft = std::max(nMaxLeft, v_nBlock[j]);
		}
		for (int j = i+1; j < nW; j++) {
			nMaxRight = std::max(nMaxRight, v_nBlock[j]);
		}
		if (nMaxLeft > 0 && nMaxRight > 0) {
			nLocalRain = std::min(nMaxLeft, nMaxRight) - v_nBlock[i];
			if (nLocalRain < 0)nLocalRain = 0;
		}
		else {
			nLocalRain = 0;
		}

		nRainSum += nLocalRain;
	}
	std::cout << nRainSum;

	return 0;
}