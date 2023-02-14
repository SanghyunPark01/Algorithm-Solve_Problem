#include <iostream>
#include <vector>
int main(void) {
	int s;
	std::cin >> s;
	
	std::vector<int> arr;
	for (int i = 0; i < s; i++) {
		int temp;
		std::cin >> temp;
		if (temp == 0) {
			arr.pop_back();
		}
		else {
			arr.push_back(temp);
		}
	}
	long long sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	std::cout << sum;

	return 0;
}