#include <iostream>
#include <map>
#include <string>
int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	std::map<std::string, std::string> mList;
	std::pair<std::string, std::string> stemp;
	for (int i = 0; i < N; i++) {
		std::string sAddress, sPassword;
		std::cin >> sAddress >> sPassword;
		mList.insert(std::pair<std::string, std::string>(sAddress, sPassword));
	}
	
	for (int i = 0; i < M; i++) {
		std::string sNeed;
		std::cin >> sNeed;
		std::cout << mList[sNeed] << "\n";
	}

	return 0;
}