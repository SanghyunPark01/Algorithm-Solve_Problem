#include <iostream>
#include <vector>
#include <algorithm>

typedef struct Point {
	int row;
	int col;
};
int N, M;
Point Chicken[10000];
Point House[10000];
int Distance[10000][10000]; // [house][chicken]
int iterator_house = 0;
int iterator_chicken = 0;

long long City_Chicken_Distance(std::vector<int> iter);
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	
	std::cin >> N >> M;	
	for (int i = 0; i < N; i++) { //row
		for (int j = 0; j < N; j++) { //col
			int temp;
			std::cin >> temp;
			if (temp == 1) {
				House[iterator_house].row = i;
				House[iterator_house].col = j;
				iterator_house++;
			}
			else if (temp == 2) {
				Chicken[iterator_chicken].row = i;
				Chicken[iterator_chicken].col = j;
				iterator_chicken++;
			}
		}
	}

	for (int i = 0; i < iterator_house; i++) {
		for (int j = 0; j < iterator_chicken; j++) {
			Distance[i][j] = std::abs(House[i].row - Chicken[j].row) + std::abs(House[i].col - Chicken[j].col);
		}
	}
	
	//Combination
	std::vector<int> Permutation;
	std::vector<int> visit; // visit
	for (int i = 0; i < iterator_chicken; i++) {
		Permutation.push_back(i);
		if (i < iterator_chicken - M) {
			visit.push_back(0);
		}
		else {
			visit.push_back(1);
		}
	}
	long long Minimum_ChickenDistance;
	bool flag = true;
	//C
	do {
		std::vector<int> Combination_temp;
		for (int i = 0; i < Permutation.size(); i++) {
			if (visit[i] != 0) {
				Combination_temp.push_back(Permutation[i]);
			}
		}

		long long chicken_distance_temp = City_Chicken_Distance(Combination_temp);
		if (flag) {
			Minimum_ChickenDistance = chicken_distance_temp;
			flag = false;
		}
		else {
			Minimum_ChickenDistance = Minimum_ChickenDistance < chicken_distance_temp ? Minimum_ChickenDistance : chicken_distance_temp;
		}
	} while (std::next_permutation(visit.begin(), visit.end()));

	std::cout << Minimum_ChickenDistance;

	return 0;
}
long long City_Chicken_Distance(std::vector<int> iter) {
	long long distance = 0;
	for (int i = 0; i < iterator_house; i++) {
		int temp = 1000;
		for (int j = 0; j < M; j++) {
			int DistanceTemp = Distance[i][iter[j]];
			temp = temp < DistanceTemp ? temp : DistanceTemp;
		}
		distance += temp;
	}
	return distance;
}