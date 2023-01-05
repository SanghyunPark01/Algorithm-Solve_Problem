#include <iostream>
#include <vector>
#include <string>
#include <math.h>

int main(void)
{
	std::string sInputNum;
	std::cin >> sInputNum;;
	
	int nLength = sInputNum.length();
	
	std::vector<int> vDevideNum;
	int nInputNum = std::stoi(sInputNum);
	int nINTemp = nInputNum;
	for (int i = 1; i < nLength; i++) {
		int nNumTemp = nINTemp % 10;
		if (nNumTemp != 0) {
			vDevideNum.push_back(nNumTemp);
		}
		nINTemp /= 10;
	}
	if (nINTemp != 0) {
		vDevideNum.push_back(nINTemp);
	}

	bool bFind = false;
	long long int nResult = nInputNum;

	int nN = 0;
	int nPlus = 0;
	while (!bFind) {
		bFind = true;
		int nTen = (int)pow(10, nN);	

		nResult = (long long int)nInputNum * nTen + nPlus;
		for (int i = 0; i < vDevideNum.size(); i++) {
			if (nResult % vDevideNum[i] != 0) bFind = false;
		}

		nPlus++;
		if (nPlus == nTen) {
			nPlus = 0;
			nN++;
		}
	}

	std::cout << nResult;

	return 0;
}