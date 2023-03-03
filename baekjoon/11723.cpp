#include <iostream>
#include <string>

bool bCheckNum[21] = { false, };
void SolveProblem(void);
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M;
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		SolveProblem();
	}

	return 0;
}
void SolveProblem(void) {
	std::string sMsg;
	int nNum;
	std::cin >> sMsg;
	if (sMsg == "add") {
		std::cin >> nNum;
		bCheckNum[nNum] = true;
	}
	else if (sMsg == "remove") {
		std::cin >> nNum;
		bCheckNum[nNum] = false;
	}
	else if (sMsg == "check") {
		std::cin >> nNum;
		if (bCheckNum[nNum])std::cout << "1" << "\n";
		else std::cout << "0" << "\n";
	}
	else if (sMsg == "toggle") {
		std::cin >> nNum;
		if (bCheckNum[nNum])bCheckNum[nNum] = false;
		else bCheckNum[nNum] = true;
	}
	else if (sMsg == "all") {
		for (int i = 1; i <= 20; i++) {
			bCheckNum[i] = true;
		}
	}
	else if (sMsg == "empty") {
		for (int i = 1; i <= 20; i++) {
			bCheckNum[i] = false;
		}
	}
}