#include <iostream>

using namespace std;

const int N = 9;
int LS[N*N];
__int64 SquaresCnt = 0;
int Rows[N][N], Strs[N][N], d1[N], d2[N];
__int64 ProcFreq = 3.4e9;
__int64 _StartProf, _StopProf;

void StartProf()
{
	_StartProf = __rdtsc();
}

void StopProf()
{
	_StopProf = __rdtsc();
}

__int64 ProfResult()
{
	return _StopProf - _StartProf;
}

void Reset()
{
	for (int i = 0; i < N*N; i++)
		LS[i] = -1;

	for (int i = 0; i < N; i++)
		LS[i] = i;

	for (int i = 1; i < N; i++)
		for (int j = 0; j < N; j++)
			Strs[i][j] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			Rows[i][j] = 1;

		Rows[i][i] = 0;
	}

	d1[0] = 0;
	for (int i = 1; i < N; i++)
		d1[i] = 1;

	d2[N - 1] = 0;
	for (int i = 0; i < N - 1; i++)
		d2[i] = 1;
}

bool IsZeroCountElement9()
{
	return
		Strs[1][0] * Rows[0][0] +
		Strs[1][1] * Rows[0][1] +
		Strs[1][2] * Rows[0][2] +
		Strs[1][3] * Rows[0][3] +
		Strs[1][4] * Rows[0][4] +
		Strs[1][5] * Rows[0][5] +
		Strs[1][6] * Rows[0][6] +
		Strs[1][7] * Rows[0][7] +
		Strs[1][8] * Rows[0][8] == 0;
}

bool IsZeroCountElement11()
{
	return
		Strs[1][0] * Rows[2][0] +
		Strs[1][1] * Rows[2][1] +
		Strs[1][2] * Rows[2][2] +
		Strs[1][3] * Rows[2][3] +
		Strs[1][4] * Rows[2][4] +
		Strs[1][5] * Rows[2][5] +
		Strs[1][6] * Rows[2][6] +
		Strs[1][7] * Rows[2][7] +
		Strs[1][8] * Rows[2][8] == 0;
}

bool IsZeroCountElement12()
{
	return
		Strs[1][0] * Rows[3][0] +
		Strs[1][1] * Rows[3][1] +
		Strs[1][2] * Rows[3][2] +
		Strs[1][3] * Rows[3][3] +
		Strs[1][4] * Rows[3][4] +
		Strs[1][5] * Rows[3][5] +
		Strs[1][6] * Rows[3][6] +
		Strs[1][7] * Rows[3][7] +
		Strs[1][8] * Rows[3][8] == 0;
}

bool IsZeroCountElement13()
{
	return
		Strs[1][0] * Rows[4][0] +
		Strs[1][1] * Rows[4][1] +
		Strs[1][2] * Rows[4][2] +
		Strs[1][3] * Rows[4][3] +
		Strs[1][4] * Rows[4][4] +
		Strs[1][5] * Rows[4][5] +
		Strs[1][6] * Rows[4][6] +
		Strs[1][7] * Rows[4][7] +
		Strs[1][8] * Rows[4][8] == 0;
}

bool IsZeroCountElement14()
{
	return
		Strs[1][0] * Rows[5][0] +
		Strs[1][1] * Rows[5][1] +
		Strs[1][2] * Rows[5][2] +
		Strs[1][3] * Rows[5][3] +
		Strs[1][4] * Rows[5][4] +
		Strs[1][5] * Rows[5][5] +
		Strs[1][6] * Rows[5][6] +
		Strs[1][7] * Rows[5][7] +
		Strs[1][8] * Rows[5][8] == 0;
}

bool IsZeroCountElement15()
{
	return
		Strs[1][0] * Rows[6][0] +
		Strs[1][1] * Rows[6][1] +
		Strs[1][2] * Rows[6][2] +
		Strs[1][3] * Rows[6][3] +
		Strs[1][4] * Rows[6][4] +
		Strs[1][5] * Rows[6][5] +
		Strs[1][6] * Rows[6][6] +
		Strs[1][7] * Rows[6][7] +
		Strs[1][8] * Rows[6][8] == 0;
}

bool IsZeroCountElement17()
{
	return
		Strs[1][0] * Rows[8][0] +
		Strs[1][1] * Rows[8][1] +
		Strs[1][2] * Rows[8][2] +
		Strs[1][3] * Rows[8][3] +
		Strs[1][4] * Rows[8][4] +
		Strs[1][5] * Rows[8][5] +
		Strs[1][6] * Rows[8][6] +
		Strs[1][7] * Rows[8][7] +
		Strs[1][8] * Rows[8][8] == 0;
}

bool IsZeroCountElement18()
{
	return
		Strs[2][0] * Rows[0][0] +
		Strs[2][1] * Rows[0][1] +
		Strs[2][2] * Rows[0][2] +
		Strs[2][3] * Rows[0][3] +
		Strs[2][4] * Rows[0][4] +
		Strs[2][5] * Rows[0][5] +
		Strs[2][6] * Rows[0][6] +
		Strs[2][7] * Rows[0][7] +
		Strs[2][8] * Rows[0][8] == 0;
}

bool IsZeroCountElement19()
{
	return
		Strs[2][0] * Rows[1][0] +
		Strs[2][1] * Rows[1][1] +
		Strs[2][2] * Rows[1][2] +
		Strs[2][3] * Rows[1][3] +
		Strs[2][4] * Rows[1][4] +
		Strs[2][5] * Rows[1][5] +
		Strs[2][6] * Rows[1][6] +
		Strs[2][7] * Rows[1][7] +
		Strs[2][8] * Rows[1][8] == 0;
}

bool IsZeroCountElement21()
{
	return
		Strs[2][0] * Rows[3][0] +
		Strs[2][1] * Rows[3][1] +
		Strs[2][2] * Rows[3][2] +
		Strs[2][3] * Rows[3][3] +
		Strs[2][4] * Rows[3][4] +
		Strs[2][5] * Rows[3][5] +
		Strs[2][6] * Rows[3][6] +
		Strs[2][7] * Rows[3][7] +
		Strs[2][8] * Rows[3][8] == 0;
}

bool IsZeroCountElement22()
{
	return
		Strs[2][0] * Rows[4][0] +
		Strs[2][1] * Rows[4][1] +
		Strs[2][2] * Rows[4][2] +
		Strs[2][3] * Rows[4][3] +
		Strs[2][4] * Rows[4][4] +
		Strs[2][5] * Rows[4][5] +
		Strs[2][6] * Rows[4][6] +
		Strs[2][7] * Rows[4][7] +
		Strs[2][8] * Rows[4][8] == 0;
}

bool IsZeroCountElement23()
{
	return
		Strs[2][0] * Rows[5][0] +
		Strs[2][1] * Rows[5][1] +
		Strs[2][2] * Rows[5][2] +
		Strs[2][3] * Rows[5][3] +
		Strs[2][4] * Rows[5][4] +
		Strs[2][5] * Rows[5][5] +
		Strs[2][6] * Rows[5][6] +
		Strs[2][7] * Rows[5][7] +
		Strs[2][8] * Rows[5][8] == 0;
}

bool IsZeroCountElement25()
{
	return
		Strs[2][0] * Rows[7][0] +
		Strs[2][1] * Rows[7][1] +
		Strs[2][2] * Rows[7][2] +
		Strs[2][3] * Rows[7][3] +
		Strs[2][4] * Rows[7][4] +
		Strs[2][5] * Rows[7][5] +
		Strs[2][6] * Rows[7][6] +
		Strs[2][7] * Rows[7][7] +
		Strs[2][8] * Rows[7][8] == 0;
}

bool IsZeroCountElement26()
{
	return
		Strs[2][0] * Rows[8][0] +
		Strs[2][1] * Rows[8][1] +
		Strs[2][2] * Rows[8][2] +
		Strs[2][3] * Rows[8][3] +
		Strs[2][4] * Rows[8][4] +
		Strs[2][5] * Rows[8][5] +
		Strs[2][6] * Rows[8][6] +
		Strs[2][7] * Rows[8][7] +
		Strs[2][8] * Rows[8][8] == 0;
}

bool IsZeroCountElement27()
{
	return
		Strs[3][0] * Rows[0][0] +
		Strs[3][1] * Rows[0][1] +
		Strs[3][2] * Rows[0][2] +
		Strs[3][3] * Rows[0][3] +
		Strs[3][4] * Rows[0][4] +
		Strs[3][5] * Rows[0][5] +
		Strs[3][6] * Rows[0][6] +
		Strs[3][7] * Rows[0][7] +
		Strs[3][8] * Rows[0][8] == 0;
}

bool IsZeroCountElement28()
{
	return
		Strs[3][0] * Rows[1][0] +
		Strs[3][1] * Rows[1][1] +
		Strs[3][2] * Rows[1][2] +
		Strs[3][3] * Rows[1][3] +
		Strs[3][4] * Rows[1][4] +
		Strs[3][5] * Rows[1][5] +
		Strs[3][6] * Rows[1][6] +
		Strs[3][7] * Rows[1][7] +
		Strs[3][8] * Rows[1][8] == 0;
}

bool IsZeroCountElement29()
{
	return
		Strs[3][0] * Rows[2][0] +
		Strs[3][1] * Rows[2][1] +
		Strs[3][2] * Rows[2][2] +
		Strs[3][3] * Rows[2][3] +
		Strs[3][4] * Rows[2][4] +
		Strs[3][5] * Rows[2][5] +
		Strs[3][6] * Rows[2][6] +
		Strs[3][7] * Rows[2][7] +
		Strs[3][8] * Rows[2][8] == 0;
}

bool IsZeroCountElement31()
{
	return
		Strs[3][0] * Rows[4][0] +
		Strs[3][1] * Rows[4][1] +
		Strs[3][2] * Rows[4][2] +
		Strs[3][3] * Rows[4][3] +
		Strs[3][4] * Rows[4][4] +
		Strs[3][5] * Rows[4][5] +
		Strs[3][6] * Rows[4][6] +
		Strs[3][7] * Rows[4][7] +
		Strs[3][8] * Rows[4][8] == 0;
}

bool IsZeroCountElement33()
{
	return
		Strs[3][0] * Rows[6][0] +
		Strs[3][1] * Rows[6][1] +
		Strs[3][2] * Rows[6][2] +
		Strs[3][3] * Rows[6][3] +
		Strs[3][4] * Rows[6][4] +
		Strs[3][5] * Rows[6][5] +
		Strs[3][6] * Rows[6][6] +
		Strs[3][7] * Rows[6][7] +
		Strs[3][8] * Rows[6][8] == 0;
}

bool IsZeroCountElement34()
{
	return
		Strs[3][0] * Rows[7][0] +
		Strs[3][1] * Rows[7][1] +
		Strs[3][2] * Rows[7][2] +
		Strs[3][3] * Rows[7][3] +
		Strs[3][4] * Rows[7][4] +
		Strs[3][5] * Rows[7][5] +
		Strs[3][6] * Rows[7][6] +
		Strs[3][7] * Rows[7][7] +
		Strs[3][8] * Rows[7][8] == 0;
}

bool IsZeroCountElement35()
{
	return
		Strs[3][0] * Rows[8][0] +
		Strs[3][1] * Rows[8][1] +
		Strs[3][2] * Rows[8][2] +
		Strs[3][3] * Rows[8][3] +
		Strs[3][4] * Rows[8][4] +
		Strs[3][5] * Rows[8][5] +
		Strs[3][6] * Rows[8][6] +
		Strs[3][7] * Rows[8][7] +
		Strs[3][8] * Rows[8][8] == 0;
}

bool IsZeroCountElement36()
{
	return
		Strs[4][0] * Rows[0][0] +
		Strs[4][1] * Rows[0][1] +
		Strs[4][2] * Rows[0][2] +
		Strs[4][3] * Rows[0][3] +
		Strs[4][4] * Rows[0][4] +
		Strs[4][5] * Rows[0][5] +
		Strs[4][6] * Rows[0][6] +
		Strs[4][7] * Rows[0][7] +
		Strs[4][8] * Rows[0][8] == 0;
}

bool IsZeroCountElement37()
{
	return
		Strs[4][0] * Rows[1][0] +
		Strs[4][1] * Rows[1][1] +
		Strs[4][2] * Rows[1][2] +
		Strs[4][3] * Rows[1][3] +
		Strs[4][4] * Rows[1][4] +
		Strs[4][5] * Rows[1][5] +
		Strs[4][6] * Rows[1][6] +
		Strs[4][7] * Rows[1][7] +
		Strs[4][8] * Rows[1][8] == 0;
}

bool IsZeroCountElement38()
{
	return
		Strs[4][0] * Rows[2][0] +
		Strs[4][1] * Rows[2][1] +
		Strs[4][2] * Rows[2][2] +
		Strs[4][3] * Rows[2][3] +
		Strs[4][4] * Rows[2][4] +
		Strs[4][5] * Rows[2][5] +
		Strs[4][6] * Rows[2][6] +
		Strs[4][7] * Rows[2][7] +
		Strs[4][8] * Rows[2][8] == 0;
}

bool IsZeroCountElement39()
{
	return
		Strs[4][0] * Rows[3][0] +
		Strs[4][1] * Rows[3][1] +
		Strs[4][2] * Rows[3][2] +
		Strs[4][3] * Rows[3][3] +
		Strs[4][4] * Rows[3][4] +
		Strs[4][5] * Rows[3][5] +
		Strs[4][6] * Rows[3][6] +
		Strs[4][7] * Rows[3][7] +
		Strs[4][8] * Rows[3][8] == 0;
}

bool IsZeroCountElement41()
{
	return
		Strs[4][0] * Rows[5][0] +
		Strs[4][1] * Rows[5][1] +
		Strs[4][2] * Rows[5][2] +
		Strs[4][3] * Rows[5][3] +
		Strs[4][4] * Rows[5][4] +
		Strs[4][5] * Rows[5][5] +
		Strs[4][6] * Rows[5][6] +
		Strs[4][7] * Rows[5][7] +
		Strs[4][8] * Rows[5][8] == 0;
}

bool IsZeroCountElement42()
{
	return
		Strs[4][0] * Rows[6][0] +
		Strs[4][1] * Rows[6][1] +
		Strs[4][2] * Rows[6][2] +
		Strs[4][3] * Rows[6][3] +
		Strs[4][4] * Rows[6][4] +
		Strs[4][5] * Rows[6][5] +
		Strs[4][6] * Rows[6][6] +
		Strs[4][7] * Rows[6][7] +
		Strs[4][8] * Rows[6][8] == 0;
}

bool IsZeroCountElement43()
{
	return
		Strs[4][0] * Rows[7][0] +
		Strs[4][1] * Rows[7][1] +
		Strs[4][2] * Rows[7][2] +
		Strs[4][3] * Rows[7][3] +
		Strs[4][4] * Rows[7][4] +
		Strs[4][5] * Rows[7][5] +
		Strs[4][6] * Rows[7][6] +
		Strs[4][7] * Rows[7][7] +
		Strs[4][8] * Rows[7][8] == 0;
}

bool IsZeroCountElement44()
{
	return
		Strs[4][0] * Rows[8][0] +
		Strs[4][1] * Rows[8][1] +
		Strs[4][2] * Rows[8][2] +
		Strs[4][3] * Rows[8][3] +
		Strs[4][4] * Rows[8][4] +
		Strs[4][5] * Rows[8][5] +
		Strs[4][6] * Rows[8][6] +
		Strs[4][7] * Rows[8][7] +
		Strs[4][8] * Rows[8][8] == 0;
}

bool IsZeroCountElement45()
{
	return
		Strs[5][0] * Rows[0][0] +
		Strs[5][1] * Rows[0][1] +
		Strs[5][2] * Rows[0][2] +
		Strs[5][3] * Rows[0][3] +
		Strs[5][4] * Rows[0][4] +
		Strs[5][5] * Rows[0][5] +
		Strs[5][6] * Rows[0][6] +
		Strs[5][7] * Rows[0][7] +
		Strs[5][8] * Rows[0][8] == 0;
}

bool IsZeroCountElement46()
{
	return
		Strs[5][0] * Rows[1][0] +
		Strs[5][1] * Rows[1][1] +
		Strs[5][2] * Rows[1][2] +
		Strs[5][3] * Rows[1][3] +
		Strs[5][4] * Rows[1][4] +
		Strs[5][5] * Rows[1][5] +
		Strs[5][6] * Rows[1][6] +
		Strs[5][7] * Rows[1][7] +
		Strs[5][8] * Rows[1][8] == 0;
}

bool IsZeroCountElement47()
{
	return
		Strs[5][0] * Rows[2][0] +
		Strs[5][1] * Rows[2][1] +
		Strs[5][2] * Rows[2][2] +
		Strs[5][3] * Rows[2][3] +
		Strs[5][4] * Rows[2][4] +
		Strs[5][5] * Rows[2][5] +
		Strs[5][6] * Rows[2][6] +
		Strs[5][7] * Rows[2][7] +
		Strs[5][8] * Rows[2][8] == 0;
}

bool IsZeroCountElement49()
{
	return
		Strs[5][0] * Rows[4][0] +
		Strs[5][1] * Rows[4][1] +
		Strs[5][2] * Rows[4][2] +
		Strs[5][3] * Rows[4][3] +
		Strs[5][4] * Rows[4][4] +
		Strs[5][5] * Rows[4][5] +
		Strs[5][6] * Rows[4][6] +
		Strs[5][7] * Rows[4][7] +
		Strs[5][8] * Rows[4][8] == 0;
}

bool IsZeroCountElement51()
{
	return
		Strs[5][0] * Rows[6][0] +
		Strs[5][1] * Rows[6][1] +
		Strs[5][2] * Rows[6][2] +
		Strs[5][3] * Rows[6][3] +
		Strs[5][4] * Rows[6][4] +
		Strs[5][5] * Rows[6][5] +
		Strs[5][6] * Rows[6][6] +
		Strs[5][7] * Rows[6][7] +
		Strs[5][8] * Rows[6][8] == 0;
}

bool IsZeroCountElement52()
{
	return
		Strs[5][0] * Rows[7][0] +
		Strs[5][1] * Rows[7][1] +
		Strs[5][2] * Rows[7][2] +
		Strs[5][3] * Rows[7][3] +
		Strs[5][4] * Rows[7][4] +
		Strs[5][5] * Rows[7][5] +
		Strs[5][6] * Rows[7][6] +
		Strs[5][7] * Rows[7][7] +
		Strs[5][8] * Rows[7][8] == 0;
}

bool IsZeroCountElement53()
{
	return
		Strs[5][0] * Rows[8][0] +
		Strs[5][1] * Rows[8][1] +
		Strs[5][2] * Rows[8][2] +
		Strs[5][3] * Rows[8][3] +
		Strs[5][4] * Rows[8][4] +
		Strs[5][5] * Rows[8][5] +
		Strs[5][6] * Rows[8][6] +
		Strs[5][7] * Rows[8][7] +
		Strs[5][8] * Rows[8][8] == 0;
}

bool IsZeroCountElement54()
{
	return
		Strs[6][0] * Rows[0][0] +
		Strs[6][1] * Rows[0][1] +
		Strs[6][2] * Rows[0][2] +
		Strs[6][3] * Rows[0][3] +
		Strs[6][4] * Rows[0][4] +
		Strs[6][5] * Rows[0][5] +
		Strs[6][6] * Rows[0][6] +
		Strs[6][7] * Rows[0][7] +
		Strs[6][8] * Rows[0][8] == 0;
}

bool IsZeroCountElement55()
{
	return
		Strs[6][0] * Rows[1][0] +
		Strs[6][1] * Rows[1][1] +
		Strs[6][2] * Rows[1][2] +
		Strs[6][3] * Rows[1][3] +
		Strs[6][4] * Rows[1][4] +
		Strs[6][5] * Rows[1][5] +
		Strs[6][6] * Rows[1][6] +
		Strs[6][7] * Rows[1][7] +
		Strs[6][8] * Rows[1][8] == 0;
}

bool IsZeroCountElement57()
{
	return
		Strs[6][0] * Rows[3][0] +
		Strs[6][1] * Rows[3][1] +
		Strs[6][2] * Rows[3][2] +
		Strs[6][3] * Rows[3][3] +
		Strs[6][4] * Rows[3][4] +
		Strs[6][5] * Rows[3][5] +
		Strs[6][6] * Rows[3][6] +
		Strs[6][7] * Rows[3][7] +
		Strs[6][8] * Rows[3][8] == 0;
}

bool IsZeroCountElement58()
{
	return
		Strs[6][0] * Rows[4][0] +
		Strs[6][1] * Rows[4][1] +
		Strs[6][2] * Rows[4][2] +
		Strs[6][3] * Rows[4][3] +
		Strs[6][4] * Rows[4][4] +
		Strs[6][5] * Rows[4][5] +
		Strs[6][6] * Rows[4][6] +
		Strs[6][7] * Rows[4][7] +
		Strs[6][8] * Rows[4][8] == 0;
}

bool IsZeroCountElement59()
{
	return
		Strs[6][0] * Rows[5][0] +
		Strs[6][1] * Rows[5][1] +
		Strs[6][2] * Rows[5][2] +
		Strs[6][3] * Rows[5][3] +
		Strs[6][4] * Rows[5][4] +
		Strs[6][5] * Rows[5][5] +
		Strs[6][6] * Rows[5][6] +
		Strs[6][7] * Rows[5][7] +
		Strs[6][8] * Rows[5][8] == 0;
}

bool IsZeroCountElement61()
{
	return
		Strs[6][0] * Rows[7][0] +
		Strs[6][1] * Rows[7][1] +
		Strs[6][2] * Rows[7][2] +
		Strs[6][3] * Rows[7][3] +
		Strs[6][4] * Rows[7][4] +
		Strs[6][5] * Rows[7][5] +
		Strs[6][6] * Rows[7][6] +
		Strs[6][7] * Rows[7][7] +
		Strs[6][8] * Rows[7][8] == 0;
}

bool IsZeroCountElement62()
{
	return
		Strs[6][0] * Rows[8][0] +
		Strs[6][1] * Rows[8][1] +
		Strs[6][2] * Rows[8][2] +
		Strs[6][3] * Rows[8][3] +
		Strs[6][4] * Rows[8][4] +
		Strs[6][5] * Rows[8][5] +
		Strs[6][6] * Rows[8][6] +
		Strs[6][7] * Rows[8][7] +
		Strs[6][8] * Rows[8][8] == 0;
}

bool IsZeroCountElement63()
{
	return
		Strs[7][0] * Rows[0][0] +
		Strs[7][1] * Rows[0][1] +
		Strs[7][2] * Rows[0][2] +
		Strs[7][3] * Rows[0][3] +
		Strs[7][4] * Rows[0][4] +
		Strs[7][5] * Rows[0][5] +
		Strs[7][6] * Rows[0][6] +
		Strs[7][7] * Rows[0][7] +
		Strs[7][8] * Rows[0][8] == 0;
}

bool IsZeroCountElement65()
{
	return
		Strs[7][0] * Rows[2][0] +
		Strs[7][1] * Rows[2][1] +
		Strs[7][2] * Rows[2][2] +
		Strs[7][3] * Rows[2][3] +
		Strs[7][4] * Rows[2][4] +
		Strs[7][5] * Rows[2][5] +
		Strs[7][6] * Rows[2][6] +
		Strs[7][7] * Rows[2][7] +
		Strs[7][8] * Rows[2][8] == 0;
}

bool IsZeroCountElement66()
{
	return
		Strs[7][0] * Rows[3][0] +
		Strs[7][1] * Rows[3][1] +
		Strs[7][2] * Rows[3][2] +
		Strs[7][3] * Rows[3][3] +
		Strs[7][4] * Rows[3][4] +
		Strs[7][5] * Rows[3][5] +
		Strs[7][6] * Rows[3][6] +
		Strs[7][7] * Rows[3][7] +
		Strs[7][8] * Rows[3][8] == 0;
}

bool IsZeroCountElement67()
{
	return
		Strs[7][0] * Rows[4][0] +
		Strs[7][1] * Rows[4][1] +
		Strs[7][2] * Rows[4][2] +
		Strs[7][3] * Rows[4][3] +
		Strs[7][4] * Rows[4][4] +
		Strs[7][5] * Rows[4][5] +
		Strs[7][6] * Rows[4][6] +
		Strs[7][7] * Rows[4][7] +
		Strs[7][8] * Rows[4][8] == 0;
}

bool IsZeroCountElement68()
{
	return
		Strs[7][0] * Rows[5][0] +
		Strs[7][1] * Rows[5][1] +
		Strs[7][2] * Rows[5][2] +
		Strs[7][3] * Rows[5][3] +
		Strs[7][4] * Rows[5][4] +
		Strs[7][5] * Rows[5][5] +
		Strs[7][6] * Rows[5][6] +
		Strs[7][7] * Rows[5][7] +
		Strs[7][8] * Rows[5][8] == 0;
}

bool IsZeroCountElement69()
{
	return
		Strs[7][0] * Rows[6][0] +
		Strs[7][1] * Rows[6][1] +
		Strs[7][2] * Rows[6][2] +
		Strs[7][3] * Rows[6][3] +
		Strs[7][4] * Rows[6][4] +
		Strs[7][5] * Rows[6][5] +
		Strs[7][6] * Rows[6][6] +
		Strs[7][7] * Rows[6][7] +
		Strs[7][8] * Rows[6][8] == 0;
}

bool IsZeroCountElement71()
{
	return
		Strs[7][0] * Rows[8][0] +
		Strs[7][1] * Rows[8][1] +
		Strs[7][2] * Rows[8][2] +
		Strs[7][3] * Rows[8][3] +
		Strs[7][4] * Rows[8][4] +
		Strs[7][5] * Rows[8][5] +
		Strs[7][6] * Rows[8][6] +
		Strs[7][7] * Rows[8][7] +
		Strs[7][8] * Rows[8][8] == 0;
}

bool IsZeroCountElement73()
{
	return
		Strs[8][0] * Rows[1][0] +
		Strs[8][1] * Rows[1][1] +
		Strs[8][2] * Rows[1][2] +
		Strs[8][3] * Rows[1][3] +
		Strs[8][4] * Rows[1][4] +
		Strs[8][5] * Rows[1][5] +
		Strs[8][6] * Rows[1][6] +
		Strs[8][7] * Rows[1][7] +
		Strs[8][8] * Rows[1][8] == 0;
}

bool IsZeroCountElement74()
{
	return
		Strs[8][0] * Rows[2][0] +
		Strs[8][1] * Rows[2][1] +
		Strs[8][2] * Rows[2][2] +
		Strs[8][3] * Rows[2][3] +
		Strs[8][4] * Rows[2][4] +
		Strs[8][5] * Rows[2][5] +
		Strs[8][6] * Rows[2][6] +
		Strs[8][7] * Rows[2][7] +
		Strs[8][8] * Rows[2][8] == 0;
}

bool IsZeroCountElement75()
{
	return
		Strs[8][0] * Rows[3][0] +
		Strs[8][1] * Rows[3][1] +
		Strs[8][2] * Rows[3][2] +
		Strs[8][3] * Rows[3][3] +
		Strs[8][4] * Rows[3][4] +
		Strs[8][5] * Rows[3][5] +
		Strs[8][6] * Rows[3][6] +
		Strs[8][7] * Rows[3][7] +
		Strs[8][8] * Rows[3][8] == 0;
}

bool IsZeroCountElement76()
{
	return
		Strs[8][0] * Rows[4][0] +
		Strs[8][1] * Rows[4][1] +
		Strs[8][2] * Rows[4][2] +
		Strs[8][3] * Rows[4][3] +
		Strs[8][4] * Rows[4][4] +
		Strs[8][5] * Rows[4][5] +
		Strs[8][6] * Rows[4][6] +
		Strs[8][7] * Rows[4][7] +
		Strs[8][8] * Rows[4][8] == 0;
}

bool IsZeroCountElement77()
{
	return
		Strs[8][0] * Rows[5][0] +
		Strs[8][1] * Rows[5][1] +
		Strs[8][2] * Rows[5][2] +
		Strs[8][3] * Rows[5][3] +
		Strs[8][4] * Rows[5][4] +
		Strs[8][5] * Rows[5][5] +
		Strs[8][6] * Rows[5][6] +
		Strs[8][7] * Rows[5][7] +
		Strs[8][8] * Rows[5][8] == 0;
}

bool IsZeroCountElement78()
{
	return
		Strs[8][0] * Rows[6][0] +
		Strs[8][1] * Rows[6][1] +
		Strs[8][2] * Rows[6][2] +
		Strs[8][3] * Rows[6][3] +
		Strs[8][4] * Rows[6][4] +
		Strs[8][5] * Rows[6][5] +
		Strs[8][6] * Rows[6][6] +
		Strs[8][7] * Rows[6][7] +
		Strs[8][8] * Rows[6][8] == 0;
}

bool IsZeroCountElement79()
{
	return
		Strs[8][0] * Rows[7][0] +
		Strs[8][1] * Rows[7][1] +
		Strs[8][2] * Rows[7][2] +
		Strs[8][3] * Rows[7][3] +
		Strs[8][4] * Rows[7][4] +
		Strs[8][5] * Rows[7][5] +
		Strs[8][6] * Rows[7][6] +
		Strs[8][7] * Rows[7][7] +
		Strs[8][8] * Rows[7][8] == 0;
}

void Generate();

char FileName[200];	// = "1203432456";
char FileData[11];

int main(int argc, char *argv[])
{
#pragma warning(disable : 4996)

	// Определение имени файла

	Reset();
	Generate();

	// Запись результата

	cout << "Total squares count: " << SquaresCnt << endl;
	cout << "OK";
	//getchar();
}

void Generate()
{
	StartProf();

	// Loop 0 start
	for (LS[40] = 0; LS[40]< N; LS[40]++) {
	    if (!Strs[4][LS[40]] || !Rows[4][LS[40]] || !d1[LS[40]] || !d2[LS[40]])
	        continue;
	
		Strs[4][LS[40]] = 0;
		Rows[4][LS[40]] = 0;
		d1[LS[40]] = 0;
		d2[LS[40]] = 0;

		// Loop 1 start
		for (LS[10] = 0; LS[10]< N; LS[10]++) {
		    if (!Strs[1][LS[10]] || !Rows[1][LS[10]] || !d1[LS[10]])
		        continue;
		

			Strs[1][LS[10]] = 0;
			Rows[1][LS[10]] = 0;
			d1[LS[10]] = 0;

			// Loop 2 start
			for (LS[16] = 0; LS[16]< N; LS[16]++) {
			    if (!Strs[1][LS[16]] || !Rows[7][LS[16]] || !d2[LS[16]])
			        continue;
			

				Strs[1][LS[16]] = 0;
				Rows[7][LS[16]] = 0;
				d2[LS[16]] = 0;

				// Loop 3 start
				for (LS[64] = 0; LS[64]< N; LS[64]++) {
				    if (!Strs[7][LS[64]] || !Rows[1][LS[64]] || !d2[LS[64]])
				        continue;
				

					Strs[7][LS[64]] = 0;
					Rows[1][LS[64]] = 0;
					d2[LS[64]] = 0;

					// Loop 4 start
					for (LS[70] = 0; LS[70]< N; LS[70]++) {
					    if (!Strs[7][LS[70]] || !Rows[7][LS[70]] || !d1[LS[70]])
					        continue;
					

						Strs[7][LS[70]] = 0;
						Rows[7][LS[70]] = 0;
						d1[LS[70]] = 0;

						// Loop 5 start
						for (LS[20] = 0; LS[20]< N; LS[20]++) {
						    if (!Strs[2][LS[20]] || !Rows[2][LS[20]] || !d1[LS[20]])
						        continue;
						

							Strs[2][LS[20]] = 0;
							Rows[2][LS[20]] = 0;
							d1[LS[20]] = 0;

							// Loop 6 start
							for (LS[24] = 0; LS[24]< N; LS[24]++) {
							    if (!Strs[2][LS[24]] || !Rows[6][LS[24]] || !d2[LS[24]])
							        continue;
							

								Strs[2][LS[24]] = 0;
								Rows[6][LS[24]] = 0;
								d2[LS[24]] = 0;

								// Loop 7 start
								for (LS[56] = 0; LS[56]< N; LS[56]++) {
								    if (!Strs[6][LS[56]] || !Rows[2][LS[56]] || !d2[LS[56]])
								        continue;
								

									Strs[6][LS[56]] = 0;
									Rows[2][LS[56]] = 0;
									d2[LS[56]] = 0;

									// Loop 8 start
									for (LS[60] = 0; LS[60]< N; LS[60]++) {
									    if (!Strs[6][LS[60]] || !Rows[6][LS[60]] || !d1[LS[60]])
									        continue;
									
										Strs[6][LS[60]] = 0;
										Rows[6][LS[60]] = 0;
										d1[LS[60]] = 0;

							

										// Loop 9 start
										for (LS[30] = 0; LS[30]< N; LS[30]++) {
										    if (!Strs[3][LS[30]] || !Rows[3][LS[30]] || !d1[LS[30]])
										        continue;
										
											Strs[3][LS[30]] = 0;
											Rows[3][LS[30]] = 0;
											d1[LS[30]] = 0;

											// Начало расчета

											// Loop 10 start
											for (LS[32] = 0; LS[32] < N; LS[32]++) {
												if (!Strs[3][LS[32]] || !Rows[5][LS[32]] || !d2[LS[32]])
													continue;

												Strs[3][LS[32]] = 0;
												Rows[5][LS[32]] = 0;
												d2[LS[32]] = 0;

												// Loop 11 start
												for (LS[48] = 0; LS[48] < N; LS[48]++) {
													if (!Strs[5][LS[48]] || !Rows[3][LS[48]] || !d2[LS[48]])
														continue;

													Strs[5][LS[48]] = 0;
													Rows[3][LS[48]] = 0;
													d2[LS[48]] = 0;

													// Loop 12 start
													int Val72 = N*(N - 1) / 2 - LS[8] - LS[16] - LS[24] - LS[32] - LS[40] - LS[48] - LS[56] - LS[64];
													if (Strs[8][Val72] && Rows[0][Val72]) {
														LS[72] = Val72;
														Strs[8][LS[72]] = 0;
														Rows[0][LS[72]] = 0;
														d2[LS[48]] = 0;

														// Loop 13 start
														for (LS[50] = 0; LS[50] < N; LS[50]++) {
															if (!Strs[5][LS[50]] || !Rows[5][LS[50]] || !d1[LS[50]])
																continue;

															Strs[5][LS[50]] = 0;
															Rows[5][LS[50]] = 0;
															d1[LS[50]] = 0;

															// Loop 14 start
															int Val80 = N*(N - 1) / 2 - LS[0] - LS[10] - LS[20] - LS[30] - LS[40] - LS[50] - LS[60] - LS[70];
															if (Strs[8][Val80] && Rows[8][Val80]) {
																LS[80] = Val80;
																Strs[8][LS[80]] = 0;
																Rows[8][LS[80]] = 0;
																d1[LS[50]] = 0;

																// Loop 15 start
																for (LS[11] = 0; LS[11] < N; LS[11]++) {
																	if (!Strs[1][LS[11]] || !Rows[2][LS[11]])
																		continue;

																	Strs[1][LS[11]] = 0;
																	Rows[2][LS[11]] = 0;

																	// Loop 16 start
																	for (LS[12] = 0; LS[12] < N; LS[12]++) {
																		if (!Strs[1][LS[12]] || !Rows[3][LS[12]])
																			continue;

																		Strs[1][LS[12]] = 0;
																		Rows[3][LS[12]] = 0;

																		// Loop 17 start
																		for (LS[14] = 0; LS[14] < N; LS[14]++) {
																			if (!Strs[1][LS[14]] || !Rows[5][LS[14]])
																				continue;

																			Strs[1][LS[14]] = 0;
																			Rows[5][LS[14]] = 0;

																			// Loop 18 start
																			for (LS[15] = 0; LS[15] < N; LS[15]++) {
																				if (!Strs[1][LS[15]] || !Rows[6][LS[15]])
																					continue;

																				Strs[1][LS[15]] = 0;
																				Rows[6][LS[15]] = 0;

																				// Loop 19 start
																				for (LS[9] = 0; LS[9] < N; LS[9]++) {
																					if (!Strs[1][LS[9]] || !Rows[0][LS[9]])
																						continue;

																					Strs[1][LS[9]] = 0;
																					Rows[0][LS[9]] = 0;

																					// Loop 20 start
																					for (LS[13] = 0; LS[13] < N; LS[13]++) {
																						if (!Strs[1][LS[13]] || !Rows[4][LS[13]])
																							continue;

																						Strs[1][LS[13]] = 0;
																						Rows[4][LS[13]] = 0;

																						// Loop 21 start
																						int Val17 = N*(N - 1) / 2 - LS[9] - LS[10] - LS[11] - LS[12] - LS[13] - LS[14] - LS[15] - LS[16];
																						if (Rows[8][Val17]) {
																							LS[17] = Val17;
																							Strs[1][LS[17]] = 0;
																							Rows[8][LS[17]] = 0;

																							// Loop 22 start
																							for (LS[21] = 0; LS[21] < N; LS[21]++) {
																								if (!Strs[2][LS[21]] || !Rows[3][LS[21]])
																									continue;

																								Strs[2][LS[21]] = 0;
																								Rows[3][LS[21]] = 0;

																								// Loop 23 start
																								for (LS[23] = 0; LS[23] < N; LS[23]++) {
																									if (!Strs[2][LS[23]] || !Rows[5][LS[23]])
																										continue;

																									Strs[2][LS[23]] = 0;
																									Rows[5][LS[23]] = 0;

																									// Loop 24 start
																									for (LS[18] = 0; LS[18] < N; LS[18]++) {
																										if (!Strs[2][LS[18]] || !Rows[0][LS[18]])
																											continue;

																										Strs[2][LS[18]] = 0;
																										Rows[0][LS[18]] = 0;

																										// Loop 25 start
																										for (LS[19] = 0; LS[19] < N; LS[19]++) {
																											if (!Strs[2][LS[19]] || !Rows[1][LS[19]])
																												continue;

																											Strs[2][LS[19]] = 0;
																											Rows[1][LS[19]] = 0;

																											// Loop 26 start
																											for (LS[22] = 0; LS[22] < N; LS[22]++) {
																												if (!Strs[2][LS[22]] || !Rows[4][LS[22]])
																													continue;

																												Strs[2][LS[22]] = 0;
																												Rows[4][LS[22]] = 0;

																												// Loop 27 start
																												for (LS[25] = 0; LS[25] < N; LS[25]++) {
																													if (!Strs[2][LS[25]] || !Rows[7][LS[25]])
																														continue;

																													Strs[2][LS[25]] = 0;
																													Rows[7][LS[25]] = 0;

																													// Loop 28 start
																													int Val26 = N*(N - 1) / 2 - LS[18] - LS[19] - LS[20] - LS[21] - LS[22] - LS[23] - LS[24] - LS[25];
																													if (Rows[8][Val26]) {
																														LS[26] = Val26;
																														Strs[2][LS[26]] = 0;
																														Rows[8][LS[26]] = 0;

																														// Loop 29 start
																														for (LS[57] = 0; LS[57] < N; LS[57]++) {
																															if (!Strs[6][LS[57]] || !Rows[3][LS[57]])
																																continue;

																															Strs[6][LS[57]] = 0;
																															Rows[3][LS[57]] = 0;

																															// Loop 30 start
																															for (LS[59] = 0; LS[59] < N; LS[59]++) {
																																if (!Strs[6][LS[59]] || !Rows[5][LS[59]])
																																	continue;

																																Strs[6][LS[59]] = 0;
																																Rows[5][LS[59]] = 0;

																																// Loop 31 start
																																for (LS[54] = 0; LS[54] < N; LS[54]++) {
																																	if (!Strs[6][LS[54]] || !Rows[0][LS[54]])
																																		continue;

																																	Strs[6][LS[54]] = 0;
																																	Rows[0][LS[54]] = 0;

																																	// Loop 32 start
																																	for (LS[55] = 0; LS[55] < N; LS[55]++) {
																																		if (!Strs[6][LS[55]] || !Rows[1][LS[55]])
																																			continue;

																																		Strs[6][LS[55]] = 0;
																																		Rows[1][LS[55]] = 0;

																																		// Loop 33 start
																																		for (LS[58] = 0; LS[58] < N; LS[58]++) {
																																			if (!Strs[6][LS[58]] || !Rows[4][LS[58]])
																																				continue;

																																			Strs[6][LS[58]] = 0;
																																			Rows[4][LS[58]] = 0;

																																			// Loop 34 start
																																			for (LS[61] = 0; LS[61] < N; LS[61]++) {
																																				if (!Strs[6][LS[61]] || !Rows[7][LS[61]])
																																					continue;

																																				Strs[6][LS[61]] = 0;
																																				Rows[7][LS[61]] = 0;

																																				// Loop 35 start
																																				int Val62 = N*(N - 1) / 2 - LS[54] - LS[55] - LS[56] - LS[57] - LS[58] - LS[59] - LS[60] - LS[61];
																																				if (Rows[8][Val62]) {
																																					LS[62] = Val62;
																																					Strs[6][LS[62]] = 0;
																																					Rows[8][LS[62]] = 0;

																																					// Loop 36 start
																																					for (LS[66] = 0; LS[66] < N; LS[66]++) {
																																						if (!Strs[7][LS[66]] || !Rows[3][LS[66]])
																																							continue;

																																						Strs[7][LS[66]] = 0;
																																						Rows[3][LS[66]] = 0;

																																						// Loop 37 start
																																						for (LS[68] = 0; LS[68] < N; LS[68]++) {
																																							if (!Strs[7][LS[68]] || !Rows[5][LS[68]])
																																								continue;

																																							Strs[7][LS[68]] = 0;
																																							Rows[5][LS[68]] = 0;

																																							// Loop 38 start
																																							for (LS[63] = 0; LS[63] < N; LS[63]++) {
																																								if (!Strs[7][LS[63]] || !Rows[0][LS[63]])
																																									continue;

																																								Strs[7][LS[63]] = 0;
																																								Rows[0][LS[63]] = 0;

																																								// Loop 39 start
																																								for (LS[67] = 0; LS[67] < N; LS[67]++) {
																																									if (!Strs[7][LS[67]] || !Rows[4][LS[67]])
																																										continue;

																																									Strs[7][LS[67]] = 0;
																																									Rows[4][LS[67]] = 0;

																																									// Loop 40 start
																																									for (LS[71] = 0; LS[71] < N; LS[71]++) {
																																										if (!Strs[7][LS[71]] || !Rows[8][LS[71]])
																																											continue;

																																										Strs[7][LS[71]] = 0;
																																										Rows[8][LS[71]] = 0;

																																										// Loop 41 start
																																										for (LS[65] = 0; LS[65] < N; LS[65]++) {
																																											if (!Strs[7][LS[65]] || !Rows[2][LS[65]])
																																												continue;

																																											Strs[7][LS[65]] = 0;
																																											Rows[2][LS[65]] = 0;

																																											// Loop 42 start
																																											int Val69 = N*(N - 1) / 2 - LS[63] - LS[64] - LS[65] - LS[66] - LS[67] - LS[68] - LS[70] - LS[71];
																																											if (Rows[6][Val69]) {
																																												LS[69] = Val69;
																																												Strs[7][LS[69]] = 0;
																																												Rows[6][LS[69]] = 0;

																																												// Loop 43 start
																																												for (LS[75] = 0; LS[75] < N; LS[75]++) {
																																													if (!Strs[8][LS[75]] || !Rows[3][LS[75]])
																																														continue;

																																													Strs[8][LS[75]] = 0;
																																													Rows[3][LS[75]] = 0;

																																													// Loop 44 start
																																													int Val39 = N*(N - 1) / 2 - LS[3] - LS[12] - LS[21] - LS[30] - LS[48] - LS[57] - LS[66] - LS[75];
																																													if (Strs[4][Val39]) {
																																														LS[39] = Val39;
																																														Strs[4][LS[39]] = 0;
																																														Rows[3][LS[39]] = 0;

																																														// Loop 45 start
																																														for (LS[77] = 0; LS[77] < N; LS[77]++) {
																																															if (!Strs[8][LS[77]] || !Rows[5][LS[77]])
																																																continue;

																																															Strs[8][LS[77]] = 0;
																																															Rows[5][LS[77]] = 0;

																																															// Loop 46 start
																																															int Val41 = N*(N - 1) / 2 - LS[5] - LS[14] - LS[23] - LS[32] - LS[50] - LS[59] - LS[68] - LS[77];
																																															if (Strs[4][Val41]) {
																																																LS[41] = Val41;
																																																Strs[4][LS[41]] = 0;
																																																Rows[5][LS[41]] = 0;

																																																// Loop 47 start
																																																for (LS[76] = 0; LS[76] < N; LS[76]++) {
																																																	if (!Strs[8][LS[76]] || !Rows[4][LS[76]])
																																																		continue;

																																																	Strs[8][LS[76]] = 0;
																																																	Rows[4][LS[76]] = 0;

																																																	// Loop 48 start
																																																	for (LS[73] = 0; LS[73] < N; LS[73]++) {
																																																		if (!Strs[8][LS[73]] || !Rows[1][LS[73]])
																																																			continue;

																																																		Strs[8][LS[73]] = 0;
																																																		Rows[1][LS[73]] = 0;

																																																		// Loop 49 start
																																																		for (LS[74] = 0; LS[74] < N; LS[74]++) {
																																																			if (!Strs[8][LS[74]] || !Rows[2][LS[74]])
																																																				continue;

																																																			Strs[8][LS[74]] = 0;
																																																			Rows[2][LS[74]] = 0;

																																																			// Loop 50 start
																																																			for (LS[78] = 0; LS[78] < N; LS[78]++) {
																																																				if (!Strs[8][LS[78]] || !Rows[6][LS[78]])
																																																					continue;

																																																				Strs[8][LS[78]] = 0;
																																																				Rows[6][LS[78]] = 0;

																																																				// Loop 51 start
																																																				int Val79 = N*(N - 1) / 2 - LS[72] - LS[73] - LS[74] - LS[75] - LS[76] - LS[77] - LS[78] - LS[80];
																																																				if (Rows[7][Val79]) {
																																																					LS[79] = Val79;
																																																					Strs[8][LS[79]] = 0;
																																																					Rows[7][LS[79]] = 0;

																																																					if (IsZeroCountElement34() || IsZeroCountElement43() || IsZeroCountElement52()) {
																																																						goto loop51end;
																																																					}

																																																					// Loop 52 start
																																																					for (LS[31] = 0; LS[31] < N; LS[31]++) {
																																																						if (!Strs[3][LS[31]] || !Rows[4][LS[31]])
																																																							continue;

																																																						Strs[3][LS[31]] = 0;
																																																						Rows[4][LS[31]] = 0;

																																																						if (IsZeroCountElement27() || IsZeroCountElement28() || IsZeroCountElement29() || IsZeroCountElement33() || IsZeroCountElement34() || IsZeroCountElement35() || IsZeroCountElement49()) {
																																																							goto loop52end;
																																																						}

																																																						// Loop 53 start
																																																						int Val49 = N*(N - 1) / 2 - LS[4] - LS[13] - LS[22] - LS[31] - LS[40] - LS[58] - LS[67] - LS[76];
																																																						if (Strs[5][Val49]) {
																																																							LS[49] = Val49;
																																																							Strs[5][LS[49]] = 0;
																																																							Rows[4][LS[49]] = 0;

																																																							if (IsZeroCountElement45() || IsZeroCountElement46() || IsZeroCountElement47() || IsZeroCountElement51() || IsZeroCountElement52() || IsZeroCountElement53()) {
																																																								goto loop53end;
																																																							}

																																																							// Loop 54 start
																																																							for (LS[27] = 0; LS[27] < N; LS[27]++) {
																																																								if (!Strs[3][LS[27]] || !Rows[0][LS[27]])
																																																									continue;

																																																								Strs[3][LS[27]] = 0;
																																																								Rows[0][LS[27]] = 0;

																																																								if (IsZeroCountElement28() || IsZeroCountElement29() || IsZeroCountElement33() || IsZeroCountElement34() || IsZeroCountElement35() || IsZeroCountElement36() || IsZeroCountElement45()) {
																																																									goto loop54end;
																																																								}

																																																								// Loop 55 start
																																																								for (LS[28] = 0; LS[28] < N; LS[28]++) {
																																																									if (!Strs[3][LS[28]] || !Rows[1][LS[28]])
																																																										continue;

																																																									Strs[3][LS[28]] = 0;
																																																									Rows[1][LS[28]] = 0;

																																																									if (IsZeroCountElement29() || IsZeroCountElement33() || IsZeroCountElement34() || IsZeroCountElement35() || IsZeroCountElement37() || IsZeroCountElement46()) {
																																																										goto loop55end;
																																																									}

																																																									// Loop 56 start
																																																									for (LS[29] = 0; LS[29] < N; LS[29]++) {
																																																										if (!Strs[3][LS[29]] || !Rows[2][LS[29]])
																																																											continue;

																																																										Strs[3][LS[29]] = 0;
																																																										Rows[2][LS[29]] = 0;

																																																										if (IsZeroCountElement33() || IsZeroCountElement34() || IsZeroCountElement35() || IsZeroCountElement38() || IsZeroCountElement47()) {
																																																											goto loop56end;
																																																										}

																																																										// Loop 57 start
																																																										for (LS[33] = 0; LS[33] < N; LS[33]++) {
																																																											if (!Strs[3][LS[33]] || !Rows[6][LS[33]])
																																																												continue;

																																																											Strs[3][LS[33]] = 0;
																																																											Rows[6][LS[33]] = 0;

																																																											if (IsZeroCountElement34() || IsZeroCountElement35() || IsZeroCountElement42() || IsZeroCountElement51()) {
																																																												goto loop57end;
																																																											}

																																																											// Loop 58 start
																																																											for (LS[34] = 0; LS[34] < N; LS[34]++) {
																																																												if (!Strs[3][LS[34]] || !Rows[7][LS[34]])
																																																													continue;

																																																												Strs[3][LS[34]] = 0;
																																																												Rows[7][LS[34]] = 0;

																																																												if (IsZeroCountElement35() || IsZeroCountElement43() || IsZeroCountElement52()) {
																																																													goto loop58end;
																																																												}

																																																												// Loop 59 start
																																																												int Val35 = N*(N - 1) / 2 - LS[27] - LS[28] - LS[29] - LS[30] - LS[31] - LS[32] - LS[33] - LS[34];
																																																												if (Rows[8][Val35]) {
																																																													LS[35] = Val35;
																																																													Strs[3][LS[35]] = 0;
																																																													Rows[8][LS[35]] = 0;

																																																													if (IsZeroCountElement44() || IsZeroCountElement53()) {
																																																														goto loop59end;
																																																													}

																																																													// Loop 60 start
																																																													for (LS[36] = 0; LS[36] < N; LS[36]++) {
																																																														if (!Strs[4][LS[36]] || !Rows[0][LS[36]])
																																																															continue;

																																																														Strs[4][LS[36]] = 0;
																																																														Rows[0][LS[36]] = 0;

																																																														// Loop 61 start
																																																														int Val45 = N*(N - 1) / 2 - LS[0] - LS[9] - LS[18] - LS[27] - LS[36] - LS[54] - LS[63] - LS[72];
																																																														if (Strs[5][Val45]) {
																																																															LS[45] = Val45;
																																																															Strs[5][LS[45]] = 0;
																																																															Rows[0][LS[45]] = 0;

																																																															// Loop 62 start
																																																															for (LS[37] = 0; LS[37] < N; LS[37]++) {
																																																																if (!Strs[4][LS[37]] || !Rows[1][LS[37]])
																																																																	continue;

																																																																Strs[4][LS[37]] = 0;
																																																																Rows[1][LS[37]] = 0;

																																																																// Loop 63 start
																																																																int Val46 = N*(N - 1) / 2 - LS[1] - LS[10] - LS[19] - LS[28] - LS[37] - LS[55] - LS[64] - LS[73];
																																																																if (Strs[5][Val46]) {
																																																																	LS[46] = Val46;
																																																																	Strs[5][LS[46]] = 0;
																																																																	Rows[1][LS[46]] = 0;

																																																																	// Loop 64 start
																																																																	for (LS[38] = 0; LS[38] < N; LS[38]++) {
																																																																		if (!Strs[4][LS[38]] || !Rows[2][LS[38]])
																																																																			continue;

																																																																		Strs[4][LS[38]] = 0;
																																																																		Rows[2][LS[38]] = 0;

																																																																		// Loop 65 start
																																																																		int Val47 = N*(N - 1) / 2 - LS[2] - LS[11] - LS[20] - LS[29] - LS[38] - LS[56] - LS[65] - LS[74];
																																																																		if (Strs[5][Val47]) {
																																																																			LS[47] = Val47;
																																																																			Strs[5][LS[47]] = 0;
																																																																			Rows[2][LS[47]] = 0;

																																																																			// Loop 66 start
																																																																			for (LS[42] = 0; LS[42] < N; LS[42]++) {
																																																																				if (!Strs[4][LS[42]] || !Rows[6][LS[42]])
																																																																					continue;

																																																																				Strs[4][LS[42]] = 0;
																																																																				Rows[6][LS[42]] = 0;

																																																																				// Loop 67 start
																																																																				int Val51 = N*(N - 1) / 2 - LS[6] - LS[15] - LS[24] - LS[33] - LS[42] - LS[60] - LS[69] - LS[78];
																																																																				if (Strs[5][Val51]) {
																																																																					LS[51] = Val51;
																																																																					Strs[5][LS[51]] = 0;
																																																																					Rows[6][LS[51]] = 0;

																																																																					// Loop 68 start
																																																																					for (LS[43] = 0; LS[43] < N; LS[43]++) {
																																																																						if (!Strs[4][LS[43]] || !Rows[7][LS[43]])
																																																																							continue;

																																																																						Strs[4][LS[43]] = 0;
																																																																						Rows[7][LS[43]] = 0;

																																																																						// Loop 69 start
																																																																						int Val44 = N*(N - 1) / 2 - LS[36] - LS[37] - LS[38] - LS[39] - LS[40] - LS[41] - LS[42] - LS[43];
																																																																						if (Rows[8][Val44]) {
																																																																							LS[44] = Val44;
																																																																							Strs[4][LS[44]] = 0;
																																																																							Rows[8][LS[44]] = 0;

																																																																							// Loop 70 start
																																																																							int Val52 = N*(N - 1) / 2 - LS[7] - LS[16] - LS[25] - LS[34] - LS[43] - LS[61] - LS[70] - LS[79];
																																																																							if (Strs[5][Val52]) {
																																																																								LS[52] = Val52;
																																																																								Strs[5][LS[52]] = 0;
																																																																								Rows[7][LS[52]] = 0;

																																																																								// Loop 71 start
																																																																								int Val53 = N*(N - 1) / 2 - LS[45] - LS[46] - LS[47] - LS[48] - LS[49] - LS[50] - LS[51] - LS[52];
																																																																								if (Rows[8][Val53]) {
																																																																									LS[53] = Val53;
																																																																									Strs[5][LS[53]] = 0;
																																																																									Rows[8][LS[53]] = 0;

																																																																									SquaresCnt++;

																																																																									if (SquaresCnt % 10000000 == 0) {
																																																																										StopProf();

																																																																										cout << "Squares found: " << SquaresCnt << endl;
																																																																										cout << "Average time: " << 1.0*ProfResult() / ProcFreq / SquaresCnt * 1000 << " ms per square" << endl;
																																																																										cout << "Squares per second: " << 1.0 / (1.0 * ProfResult() / ProcFreq / SquaresCnt) / 1000 << "k" << endl << endl;
																																																																									}

																																																																								loop71end:
																																																																									// Loop 71 end
																																																																									Strs[5][LS[53]] = 1;
																																																																									Rows[8][LS[53]] = 1;
																																																																								}
																																																																								LS[53] = -1;

																																																																							loop70end:
																																																																								// Loop 70 end
																																																																								Strs[5][LS[52]] = 1;
																																																																								Rows[7][LS[52]] = 1;
																																																																							}
																																																																							LS[52] = -1;

																																																																						loop69end:
																																																																							// Loop 69 end
																																																																							Strs[4][LS[44]] = 1;
																																																																							Rows[8][LS[44]] = 1;
																																																																						}
																																																																						LS[44] = -1;

																																																																					loop68end:
																																																																						// Loop 68 end
																																																																						Strs[4][LS[43]] = 1;
																																																																						Rows[7][LS[43]] = 1;
																																																																					}
																																																																					LS[43] = -1;

																																																																				loop67end:
																																																																					// Loop 67 end
																																																																					Strs[5][LS[51]] = 1;
																																																																					Rows[6][LS[51]] = 1;
																																																																				}
																																																																				LS[51] = -1;

																																																																			loop66end:
																																																																				// Loop 66 end
																																																																				Strs[4][LS[42]] = 1;
																																																																				Rows[6][LS[42]] = 1;
																																																																			}
																																																																			LS[42] = -1;

																																																																		loop65end:
																																																																			// Loop 65 end
																																																																			Strs[5][LS[47]] = 1;
																																																																			Rows[2][LS[47]] = 1;
																																																																		}
																																																																		LS[47] = -1;

																																																																	loop64end:
																																																																		// Loop 64 end
																																																																		Strs[4][LS[38]] = 1;
																																																																		Rows[2][LS[38]] = 1;
																																																																	}
																																																																	LS[38] = -1;

																																																																loop63end:
																																																																	// Loop 63 end
																																																																	Strs[5][LS[46]] = 1;
																																																																	Rows[1][LS[46]] = 1;
																																																																}
																																																																LS[46] = -1;

																																																															loop62end:
																																																																// Loop 62 end
																																																																Strs[4][LS[37]] = 1;
																																																																Rows[1][LS[37]] = 1;
																																																															}
																																																															LS[37] = -1;

																																																														loop61end:
																																																															// Loop 61 end
																																																															Strs[5][LS[45]] = 1;
																																																															Rows[0][LS[45]] = 1;
																																																														}
																																																														LS[45] = -1;

																																																													loop60end:
																																																														// Loop 60 end
																																																														Strs[4][LS[36]] = 1;
																																																														Rows[0][LS[36]] = 1;
																																																													}
																																																													LS[36] = -1;

																																																												loop59end:
																																																													// Loop 59 end
																																																													Strs[3][LS[35]] = 1;
																																																													Rows[8][LS[35]] = 1;
																																																												}
																																																												LS[35] = -1;

																																																											loop58end:
																																																												// Loop 58 end
																																																												Strs[3][LS[34]] = 1;
																																																												Rows[7][LS[34]] = 1;
																																																											}
																																																											LS[34] = -1;

																																																										loop57end:
																																																											// Loop 57 end
																																																											Strs[3][LS[33]] = 1;
																																																											Rows[6][LS[33]] = 1;
																																																										}
																																																										LS[33] = -1;

																																																									loop56end:
																																																										// Loop 56 end
																																																										Strs[3][LS[29]] = 1;
																																																										Rows[2][LS[29]] = 1;
																																																									}
																																																									LS[29] = -1;

																																																								loop55end:
																																																									// Loop 55 end
																																																									Strs[3][LS[28]] = 1;
																																																									Rows[1][LS[28]] = 1;
																																																								}
																																																								LS[28] = -1;

																																																							loop54end:
																																																								// Loop 54 end
																																																								Strs[3][LS[27]] = 1;
																																																								Rows[0][LS[27]] = 1;
																																																							}
																																																							LS[27] = -1;

																																																						loop53end:
																																																							// Loop 53 end
																																																							Strs[5][LS[49]] = 1;
																																																							Rows[4][LS[49]] = 1;
																																																						}
																																																						LS[49] = -1;

																																																					loop52end:
																																																						// Loop 52 end
																																																						Strs[3][LS[31]] = 1;
																																																						Rows[4][LS[31]] = 1;
																																																					}
																																																					LS[31] = -1;

																																																				loop51end:
																																																					// Loop 51 end
																																																					Strs[8][LS[79]] = 1;
																																																					Rows[7][LS[79]] = 1;
																																																				}
																																																				LS[79] = -1;

																																																			loop50end:
																																																				// Loop 50 end
																																																				Strs[8][LS[78]] = 1;
																																																				Rows[6][LS[78]] = 1;
																																																			}
																																																			LS[78] = -1;

																																																		loop49end:
																																																			// Loop 49 end
																																																			Strs[8][LS[74]] = 1;
																																																			Rows[2][LS[74]] = 1;
																																																		}
																																																		LS[74] = -1;

																																																	loop48end:
																																																		// Loop 48 end
																																																		Strs[8][LS[73]] = 1;
																																																		Rows[1][LS[73]] = 1;
																																																	}
																																																	LS[73] = -1;

																																																loop47end:
																																																	// Loop 47 end
																																																	Strs[8][LS[76]] = 1;
																																																	Rows[4][LS[76]] = 1;
																																																}
																																																LS[76] = -1;

																																															loop46end:
																																																// Loop 46 end
																																																Strs[4][LS[41]] = 1;
																																																Rows[5][LS[41]] = 1;
																																															}
																																															LS[41] = -1;

																																														loop45end:
																																															// Loop 45 end
																																															Strs[8][LS[77]] = 1;
																																															Rows[5][LS[77]] = 1;
																																														}
																																														LS[77] = -1;

																																													loop44end:
																																														// Loop 44 end
																																														Strs[4][LS[39]] = 1;
																																														Rows[3][LS[39]] = 1;
																																													}
																																													LS[39] = -1;

																																												loop43end:
																																													// Loop 43 end
																																													Strs[8][LS[75]] = 1;
																																													Rows[3][LS[75]] = 1;
																																												}
																																												LS[75] = -1;

																																											loop42end:
																																												// Loop 42 end
																																												Strs[7][LS[69]] = 1;
																																												Rows[6][LS[69]] = 1;
																																											}
																																											LS[69] = -1;

																																										loop41end:
																																											// Loop 41 end
																																											Strs[7][LS[65]] = 1;
																																											Rows[2][LS[65]] = 1;
																																										}
																																										LS[65] = -1;

																																									loop40end:
																																										// Loop 40 end
																																										Strs[7][LS[71]] = 1;
																																										Rows[8][LS[71]] = 1;
																																									}
																																									LS[71] = -1;

																																								loop39end:
																																									// Loop 39 end
																																									Strs[7][LS[67]] = 1;
																																									Rows[4][LS[67]] = 1;
																																								}
																																								LS[67] = -1;

																																							loop38end:
																																								// Loop 38 end
																																								Strs[7][LS[63]] = 1;
																																								Rows[0][LS[63]] = 1;
																																							}
																																							LS[63] = -1;

																																						loop37end:
																																							// Loop 37 end
																																							Strs[7][LS[68]] = 1;
																																							Rows[5][LS[68]] = 1;
																																						}
																																						LS[68] = -1;

																																					loop36end:
																																						// Loop 36 end
																																						Strs[7][LS[66]] = 1;
																																						Rows[3][LS[66]] = 1;
																																					}
																																					LS[66] = -1;

																																				loop35end:
																																					// Loop 35 end
																																					Strs[6][LS[62]] = 1;
																																					Rows[8][LS[62]] = 1;
																																				}
																																				LS[62] = -1;

																																			loop34end:
																																				// Loop 34 end
																																				Strs[6][LS[61]] = 1;
																																				Rows[7][LS[61]] = 1;
																																			}
																																			LS[61] = -1;

																																		loop33end:
																																			// Loop 33 end
																																			Strs[6][LS[58]] = 1;
																																			Rows[4][LS[58]] = 1;
																																		}
																																		LS[58] = -1;

																																	loop32end:
																																		// Loop 32 end
																																		Strs[6][LS[55]] = 1;
																																		Rows[1][LS[55]] = 1;
																																	}
																																	LS[55] = -1;

																																loop31end:
																																	// Loop 31 end
																																	Strs[6][LS[54]] = 1;
																																	Rows[0][LS[54]] = 1;
																																}
																																LS[54] = -1;

																															loop30end:
																																// Loop 30 end
																																Strs[6][LS[59]] = 1;
																																Rows[5][LS[59]] = 1;
																															}
																															LS[59] = -1;

																														loop29end:
																															// Loop 29 end
																															Strs[6][LS[57]] = 1;
																															Rows[3][LS[57]] = 1;
																														}
																														LS[57] = -1;

																													loop28end:
																														// Loop 28 end
																														Strs[2][LS[26]] = 1;
																														Rows[8][LS[26]] = 1;
																													}
																													LS[26] = -1;

																												loop27end:
																													// Loop 27 end
																													Strs[2][LS[25]] = 1;
																													Rows[7][LS[25]] = 1;
																												}
																												LS[25] = -1;

																											loop26end:
																												// Loop 26 end
																												Strs[2][LS[22]] = 1;
																												Rows[4][LS[22]] = 1;
																											}
																											LS[22] = -1;

																										loop25end:
																											// Loop 25 end
																											Strs[2][LS[19]] = 1;
																											Rows[1][LS[19]] = 1;
																										}
																										LS[19] = -1;

																									loop24end:
																										// Loop 24 end
																										Strs[2][LS[18]] = 1;
																										Rows[0][LS[18]] = 1;
																									}
																									LS[18] = -1;

																								loop23end:
																									// Loop 23 end
																									Strs[2][LS[23]] = 1;
																									Rows[5][LS[23]] = 1;
																								}
																								LS[23] = -1;

																							loop22end:
																								// Loop 22 end
																								Strs[2][LS[21]] = 1;
																								Rows[3][LS[21]] = 1;
																							}
																							LS[21] = -1;

																						loop21end:
																							// Loop 21 end
																							Strs[1][LS[17]] = 1;
																							Rows[8][LS[17]] = 1;
																						}
																						LS[17] = -1;

																					loop20end:
																						// Loop 20 end
																						Strs[1][LS[13]] = 1;
																						Rows[4][LS[13]] = 1;
																					}
																					LS[13] = -1;

																				loop19end:
																					// Loop 19 end
																					Strs[1][LS[9]] = 1;
																					Rows[0][LS[9]] = 1;
																				}
																				LS[9] = -1;

																			loop18end:
																				// Loop 18 end
																				Strs[1][LS[15]] = 1;
																				Rows[6][LS[15]] = 1;
																			}
																			LS[15] = -1;

																		loop17end:
																			// Loop 17 end
																			Strs[1][LS[14]] = 1;
																			Rows[5][LS[14]] = 1;
																		}
																		LS[14] = -1;

																	loop16end:
																		// Loop 16 end
																		Strs[1][LS[12]] = 1;
																		Rows[3][LS[12]] = 1;
																	}
																	LS[12] = -1;

																loop15end:
																	// Loop 15 end
																	Strs[1][LS[11]] = 1;
																	Rows[2][LS[11]] = 1;
																}
																LS[11] = -1;

															loop14end:
																// Loop 14 end
																Strs[8][LS[80]] = 1;
																Rows[8][LS[80]] = 1;
																d1[LS[80]] = 1;
															}
															LS[80] = -1;

														loop13end:
															// Loop 13 end
															Strs[5][LS[50]] = 1;
															Rows[5][LS[50]] = 1;
															d1[LS[50]] = 1;
														}
														LS[50] = -1;

													loop12end:
														// Loop 12 end
														Strs[8][LS[72]] = 1;
														Rows[0][LS[72]] = 1;
														d2[LS[72]] = 1;
													}
													LS[72] = -1;

												loop11end:
													// Loop 11 end
													Strs[5][LS[48]] = 1;
													Rows[3][LS[48]] = 1;
													d2[LS[48]] = 1;
												}
												LS[48] = -1;

											loop10end:
												// Loop 10 end
												Strs[3][LS[32]] = 1;
												Rows[5][LS[32]] = 1;
												d2[LS[32]] = 1;
											}
											LS[32] = -1;

										loop9end:
											// Loop 9 end
											Strs[3][LS[30]] = 1;
											Rows[3][LS[30]] = 1;
											d1[LS[30]] = 1;
										}
										LS[30] = -1;

									loop8end:
										// Loop 8 end
										Strs[6][LS[60]] = 1;
										Rows[6][LS[60]] = 1;
										d1[LS[60]] = 1;
									}
									LS[60] = -1;

								loop7end:
									// Loop 7 end
									Strs[6][LS[56]] = 1;
									Rows[2][LS[56]] = 1;
									d2[LS[56]] = 1;
								}
								LS[56] = -1;

							loop6end:
								// Loop 6 end
								Strs[2][LS[24]] = 1;
								Rows[6][LS[24]] = 1;
								d2[LS[24]] = 1;
							}
							LS[24] = -1;

						loop5end:
							// Loop 5 end
							Strs[2][LS[20]] = 1;
							Rows[2][LS[20]] = 1;
							d1[LS[20]] = 1;
						}
						LS[20] = -1;

					loop4end:
						// Loop 4 end
						Strs[7][LS[70]] = 1;
						Rows[7][LS[70]] = 1;
						d1[LS[70]] = 1;
					}
					LS[70] = -1;

				loop3end:
					// Loop 3 end
					Strs[7][LS[64]] = 1;
					Rows[1][LS[64]] = 1;
					d2[LS[64]] = 1;
				}
				LS[64] = -1;

			loop2end:
				// Loop 2 end
				Strs[1][LS[16]] = 1;
				Rows[7][LS[16]] = 1;
				d2[LS[16]] = 1;
			}
			LS[16] = -1;

		loop1end:
			// Loop 1 end
			Strs[1][LS[10]] = 1;
			Rows[1][LS[10]] = 1;
			d1[LS[10]] = 1;
		}
		LS[10] = -1;

	loop0end:
		// Loop 0 end
		Strs[4][LS[40]] = 1;
		Rows[4][LS[40]] = 1;
		d1[LS[40]] = 1;
		d2[LS[40]] = 1;
	}
	LS[40] = -1;

}
