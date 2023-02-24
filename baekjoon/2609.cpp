#include <iostream>

int main(void) {
	int n1, n2;
	std::cin >> n1 >> n2;
	int nMin = n1 < n2 ? n1 : n2;
	int nMax = n1 > n2 ? n1 : n2;
	while (nMin != 0) {
		int temp = nMin;
		nMin = nMax % nMin;
		nMax = temp;
	}
	//�ִ� ����� GCD
	int GCD = nMax;
	//�ִ� ����� GCM
	int LCM = (n1 * n2) / nMax;
	std::cout << GCD << "\n" << LCM;
	return 0;
}