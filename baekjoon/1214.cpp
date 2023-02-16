#include <iostream>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long D, P, Q;
	std::cin >> D >> P >> Q;

	//큰걸 Q로 잡음
	if (Q < P) {
		long long temp = Q;
		Q = P;
		P = temp;
	}

	//반복문 횟수 설정
	long long maxQ = D / Q + 1;

	//solution
	long long result = maxQ * Q;
	for (long long i = maxQ - 1; i >= 0; i--) {
		long long nP;
		if ((D - Q * i) <= 0)nP = 0;
		else if ((D - Q * i) % P == 0) {
			nP = (D - Q * i) / P;
		}
		else { 
			nP = (D - Q * i) / P + 1;
		}
		long long price = Q * i + P * nP;
		if (price - D >= 0) {
			if (result == price)break;
			result = result < price ? result : price;
			if (result == D) {
				break;
			}
		}	
	}
	std::cout << result;

	return 0;
}