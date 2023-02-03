#include <iostream>
int Cube[25] = { 0, };
bool CheckCube(int* cube);
bool RotationCube(int* cube);
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for (int i = 1; i <= 24; i++) {
		std::cin >> Cube[i];
	}

	int result = 0;
	if (RotationCube(Cube))result = 1;
	std::cout << result;

	return 0;
}
bool CheckCube(int* cube) {
	if (cube[1] != cube[2] || cube[2] != cube[3] || cube[3] != cube[4])return false;
	if (cube[5] != cube[6] || cube[6] != cube[7] || cube[7] != cube[8])return false;
	if (cube[9] != cube[10] || cube[10] != cube[11] || cube[11] != cube[12])return false;
	if (cube[13] != cube[14] || cube[14] != cube[15] || cube[15] != cube[16])return false;
	if (cube[17] != cube[18] || cube[18] != cube[19] || cube[19] != cube[20])return false;
	if (cube[21] != cube[22] || cube[22] != cube[23] || cube[23] != cube[24])return false;
	return true;
}
bool RotationCube(int* Original_Cube) {
	
	int RotateCube[25] = { 0, };
	//----------------------------
	//Case 1 : Front Up & Down
	//-Up
	for (int i = 1; i <= 24; i++) {
		RotateCube[i] = Original_Cube[i];
	}
	RotateCube[2] = Original_Cube[6];
	RotateCube[4] = Original_Cube[8];
	RotateCube[6] = Original_Cube[10];
	RotateCube[8] = Original_Cube[12];
	RotateCube[10] = Original_Cube[23];
	RotateCube[12] = Original_Cube[21];
	RotateCube[21] = Original_Cube[4];
	RotateCube[23] = Original_Cube[2];
	if (CheckCube(RotateCube))return true;
	//-Down
	for (int i = 1; i <= 24; i++) {
		RotateCube[i] = Original_Cube[i];
	}
	RotateCube[2] = Original_Cube[23];
	RotateCube[4] = Original_Cube[21];
	RotateCube[6] = Original_Cube[2];
	RotateCube[8] = Original_Cube[4];
	RotateCube[10] = Original_Cube[6];
	RotateCube[12] = Original_Cube[8];
	RotateCube[21] = Original_Cube[12];
	RotateCube[23] = Original_Cube[10];
	if (CheckCube(RotateCube))return true;
	//----------------------------
	//Case 2 : Front Right & Left
	//-Right
	for (int i = 1; i <= 24; i++) {
		RotateCube[i] = Original_Cube[i];
	}
	RotateCube[13] = Original_Cube[21];
	RotateCube[14] = Original_Cube[22];
	RotateCube[5] = Original_Cube[13];
	RotateCube[6] = Original_Cube[14];
	RotateCube[17] = Original_Cube[5];
	RotateCube[18] = Original_Cube[6];
	RotateCube[21] = Original_Cube[17];
	RotateCube[22] = Original_Cube[18];
	if (CheckCube(RotateCube))return true;
	//-Left
	for (int i = 1; i <= 24; i++) {
		RotateCube[i] = Original_Cube[i];
	}
	RotateCube[13] = Original_Cube[5];
	RotateCube[14] = Original_Cube[6];
	RotateCube[5] = Original_Cube[17];
	RotateCube[6] = Original_Cube[18];
	RotateCube[17] = Original_Cube[21];
	RotateCube[18] = Original_Cube[22];
	RotateCube[21] = Original_Cube[13];
	RotateCube[22] = Original_Cube[14];
	if (CheckCube(RotateCube))return true;
	//----------------------------
	//Case 3 : Side Right & Left
	//-Right
	for (int i = 1; i <= 24; i++) {
		RotateCube[i] = Original_Cube[i];
	}
	RotateCube[3] = Original_Cube[16];
	RotateCube[4] = Original_Cube[14];
	RotateCube[17] = Original_Cube[3];
	RotateCube[19] = Original_Cube[4];
	RotateCube[10] = Original_Cube[17];
	RotateCube[9] = Original_Cube[19];
	RotateCube[16] = Original_Cube[10];
	RotateCube[14] = Original_Cube[9];
	if (CheckCube(RotateCube))return true;
	//-Left
	for (int i = 1; i <= 24; i++) {
		RotateCube[i] = Original_Cube[i];
	}
	RotateCube[3] = Original_Cube[17];
	RotateCube[4] = Original_Cube[19];
	RotateCube[17] = Original_Cube[10];
	RotateCube[19] = Original_Cube[9];
	RotateCube[10] = Original_Cube[16];
	RotateCube[9] = Original_Cube[14];
	RotateCube[16] = Original_Cube[3];
	RotateCube[14] = Original_Cube[4];
	if (CheckCube(RotateCube))return true;
	//----------------------------
	return false;
}