#include <iostream>

int nSchedule[1500001][2];
int DP[1500001] = { 0, };
int main(void) {
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		//0: Ti, 1: Pi
		std::cin >> nSchedule[i][0] >> nSchedule[i][1];
	}
	for (int i = 1; i <= N; i++) {
		DP[i] = DP[i] > DP[i - 1] ? DP[i] : DP[i - 1];
		DP[nSchedule[i][0] + i - 1] = DP[nSchedule[i][0] + i - 1] > nSchedule[i][1] + DP[i - 1] ? DP[nSchedule[i][0] + i - 1] : nSchedule[i][1] + DP[i - 1];
	}

	std::cout << DP[N];

	return 0;
}