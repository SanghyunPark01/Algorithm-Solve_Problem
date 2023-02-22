#include <iostream>
#include <vector>
int main(void) {
	int n;
	std::cin >> n;
	std::string sResult = "";
	std::vector<int> vStack;
	int nNum = 1;
	
	bool bFlag = false;
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;

		while (temp >= nNum) {
			vStack.push_back(nNum);
			sResult += "+";
			nNum++;
		}
		
		if (temp == vStack.back()) {
			vStack.pop_back();
			sResult += "-";
		}
		else {
			bFlag = true;
			break;
		}
	}

	if (bFlag) {
		std::cout << "NO";
	}
	else {
		for (int i = 0; i < sResult.size(); i++) {
			std::cout << sResult[i] << "\n";
		}
	}

	return 0;
}