#include <iostream>
#include <vector>
std::string sCheckVPS(std::string ss);
int main(void) {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; i++) {
		std::string ss;
		std::cin >> ss;
		std::cout << sCheckVPS(ss) << "\n";
	}

	return 0;
}
std::string sCheckVPS(std::string ss) {
	std::vector<char> arr;
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] == ')' && arr.size() >= 1 && arr[arr.size() - 1] == '(') {
			arr.pop_back();
		}
		else {
			arr.push_back(ss[i]);
		}
	}

	if (arr.size() != 0)return "NO";
	else return "YES";
}