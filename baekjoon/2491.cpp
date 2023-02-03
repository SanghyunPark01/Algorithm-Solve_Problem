#include <iostream>

int nArray[100000];
int DP[100000][2]; // 0: up, 1: Down
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int nSize;
    std::cin >> nSize;
    for (int i = 0; i < nSize; i++) {
        std::cin >> nArray[i];
    }

    int nMax = 0;
    for (int i = 0; i < nSize; i++) {
        int nUpLength = 1;
        int nDownLenght = 1;
        //up
        for (int j = i + 1; j < nSize; j++) {
            if (i != 0 && DP[i - 1][0] > 1) {
                nUpLength = DP[i - 1][0] - 1;
                break;
            }
            if (nArray[j - 1] <= nArray[j])nUpLength++;
            else break;
        }
        //down
        for (int j = i + 1; j < nSize; j++) {
            if (i != 0 && DP[i - 1][1] > 1) {
                nDownLenght = DP[i - 1][1] - 1;
                break;
            }
            if (i != 0 && DP[i][1] > i)break;
            if (nArray[j - 1] >= nArray[j])nDownLenght++;
            else break;
        }

        DP[i][0] = nUpLength;
        DP[i][1] = nDownLenght;
        nMax = nUpLength > nMax ? nUpLength : nMax;
        nMax = nDownLenght > nMax ? nDownLenght : nMax;
    }

    std::cout << nMax;
    return 0;
}