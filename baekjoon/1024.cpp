#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, L;
    std::cin >> N >> L;

    int nAddLength = 1;
    int nSumTemp = 0;
    int nStartNum;
    bool flag = false;
    while (1) {
        if (L > 100)break;
        if (nAddLength < L - 1) {
            nSumTemp += nAddLength;
            nAddLength++;
            continue;
        }
        nSumTemp += nAddLength;
        int nRemain = (N - nSumTemp) % (nAddLength + 1);
        nStartNum = (N - nSumTemp) / (nAddLength + 1);
        if (nRemain == 0 && nStartNum >= 0) {
            nStartNum = (N - nSumTemp) / (nAddLength + 1);
            flag = true;
            break;
        }
        nAddLength++;
        if (nAddLength > 99 || nAddLength > N)break;
        
    }
    if (flag) {
        for (int i = 0; i <= nAddLength; i++) {
            std::cout << nStartNum + i << " ";
        }
    }
    else {
        std::cout << "-1";
    }
    return 0;
}