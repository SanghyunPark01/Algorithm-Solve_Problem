#include <iostream>
long long nKArray[10000];
int main(void) {
	long long K, N;
	std::cin >> K >> N;
	long long nMax = 0;
	for (long long i = 0; i < K; i++) {
		long long nTemp;
		std::cin >> nTemp;
		nKArray[i] = nTemp;
		nMax = nMax > nTemp ? nMax : nTemp;
	}
	long long nStart = 0;
	long long nEnd = nMax;
	long long nMid;
	long long result = 0;
	while (nStart <= nEnd) {
		nMid = (nStart + nEnd) / 2;
		if (nMid < 1)nMid = 1;
		long long nN = 0;
		for (long long i = 0; i < K; i++) {
			nN += (nKArray[i] / nMid);
		}
		/*if (nN == N) {
			break;
		}*/
		if (nN >= N) {
			nStart = nMid + 1;
			result = result > nMid ? result : nMid;
		}
		else if(nN < N){
			nEnd = nMid - 1;
		}
		
	}
	std::cout << result << "\n";

	return 0;
}