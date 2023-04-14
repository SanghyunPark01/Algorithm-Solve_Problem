#include <iostream>
#include <string>
int main(void) {
	std::string sProblem;
	std::cin >> sProblem;

	int nResult = 0;
	bool bIsMinus = false;
	std::string stemp;

	for (int i = 0; i <= sProblem.size(); i++) {
		if (sProblem[i] == '+' || sProblem[i] == '-' || i == sProblem.size()) {
			if (bIsMinus){
                nResult -= std::stoi(stemp);
			}
			else {
                nResult += std::stoi(stemp);
			}
            stemp.clear();
		}
		else {
			stemp += sProblem[i];
		}
        if (sProblem[i] == '-') {
            bIsMinus = true;
        }

	}

	std::cout << nResult;

	return 0;
}