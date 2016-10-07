#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

const int N = 9;
const uint32_t maxN = 1 << N;
const uint32_t AllN = 511;
uint32_t LS[N*N];
uint32_t L[N*N];
uint32_t CR[N*N];
//uint32_t L[N*N];
uint64_t SquaresCnt = 0;
uint32_t Columns[N], Rows[N], MD, AD;


__int64 ProcFreq = 3.5e9;
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
		LS[i] = 0;
	for (int i = 0; i < N; i++)
		LS[i] = 1 << i;
	for (int i = 0; i < N; i++)
		Columns[i] = 0;
	for (int i = 0; i < N; i++)
		Rows[i] = 0;
	MD = 0;
	AD = 0;
	for (int j = 0; j<N; j++) {
		LS[j] = 1 << j;
		Rows[0] |= LS[j];
		Columns[j] |= LS[j];
	}
	MD |= LS[0];
	AD |= LS[N - 1];
}

void Generate();

int main(int argc, char *argv[])
{

	Reset();

	Generate();

	cout << "Total squares count: " << SquaresCnt << endl;
	cout << "OK";
	//getchar();*/
}


void Generate()
{

	StartProf();
	for (CR[40] = AllN ^ (Rows[4] | Columns[4] | MD | AD); CR[40] != 0; CR[40] = (CR[40] & (CR[40] - 1))) {
		LS[40] = (CR[40] & (-CR[40]));

		Rows[4] |= LS[40];
		Columns[4] |= LS[40];
		MD |= LS[40];
		AD |= LS[40];
		for (CR[10] = AllN ^ (Rows[1] | Columns[1] | MD); CR[10] != 0; CR[10] = (CR[10] & (CR[10] - 1))) {
			LS[10] = (CR[10] & (-CR[10]));
			Rows[1] |= LS[10];
			Columns[1] |= LS[10];
			MD |= LS[10];
			for (CR[16] = AllN ^ (Rows[1] | Columns[7] | AD); CR[16] != 0; CR[16] = (CR[16] & (CR[16] - 1))) {
				LS[16] = (CR[16] & (-CR[16]));
				Rows[1] |= LS[16];
				Columns[7] |= LS[16];
				AD |= LS[16];
				for (CR[64] = AllN ^ (Rows[7] | Columns[1] | AD); CR[64] != 0; CR[64] = (CR[64] & (CR[64] - 1))) {
					LS[64] = (CR[64] & (-CR[64]));
					Rows[7] |= LS[64];
					Columns[1] |= LS[64];
					AD |= LS[64];
					for (CR[70] = AllN ^ (Rows[7] | Columns[7] | MD); CR[70] != 0; CR[70] = (CR[70] & (CR[70] - 1))) {
						LS[70] = (CR[70] & (-CR[70]));
						Rows[7] |= LS[70];
						Columns[7] |= LS[70];
						MD |= LS[70];
						for (CR[20] = AllN ^ (Rows[2] | Columns[2] | MD); CR[20] != 0; CR[20] = (CR[20] & (CR[20] - 1))) {
							LS[20] = (CR[20] & (-CR[20]));
							Rows[2] |= LS[20];
							Columns[2] |= LS[20];
							MD |= LS[20];
							for (CR[24] = AllN ^ (Rows[2] | Columns[6] | AD); CR[24] != 0; CR[24] = (CR[24] & (CR[24] - 1))) {
								LS[24] = (CR[24] & (-CR[24]));
								Rows[2] |= LS[24];
								Columns[6] |= LS[24];
								AD |= LS[24];
								for (CR[56] = AllN ^ (Rows[6] | Columns[2] | AD); CR[56] != 0; CR[56] = (CR[56] & (CR[56] - 1))) {
									LS[56] = (CR[56] & (-CR[56]));
									Rows[6] |= LS[56];
									Columns[2] |= LS[56];
									AD |= LS[56];
									for (CR[60] = AllN ^ (Rows[6] | Columns[6] | MD); CR[60] != 0; CR[60] = (CR[60] & (CR[60] - 1))) {
										LS[60] = (CR[60] & (-CR[60]));
										Rows[6] |= LS[60];
										Columns[6] |= LS[60];
										MD |= LS[60];
										for (CR[30] = AllN ^ (Rows[3] | Columns[3] | MD); CR[30] != 0; CR[30] = (CR[30] & (CR[30] - 1))) {
											LS[30] = (CR[30] & (-CR[30]));
											Rows[3] |= LS[30];
											Columns[3] |= LS[30];
											MD |= LS[30];
											for (CR[32] = AllN ^ (Rows[3] | Columns[5] | AD); CR[32] != 0; CR[32] = (CR[32] & (CR[32] - 1))) {
												LS[32] = (CR[32] & (-CR[32]));
												Rows[3] |= LS[32];
												Columns[5] |= LS[32];
												AD |= LS[32];
												for (CR[48] = AllN ^ (Rows[5] | Columns[3] | AD); CR[48] != 0; CR[48] = (CR[48] & (CR[48] - 1))) {
													LS[48] = (CR[48] & (-CR[48]));
													Rows[5] |= LS[48];
													Columns[3] |= LS[48];
													AD |= LS[48];
													CR[72] = AllN ^ (Rows[8] | Columns[0] | AD);
													if (CR[72] != 0) {
														LS[72] = (CR[72] & (-CR[72]));
														Rows[8] |= LS[72];
														Columns[0] |= LS[72];
														for (CR[50] = AllN ^ (Rows[5] | Columns[5] | MD); CR[50] != 0; CR[50] = (CR[50] & (CR[50] - 1))) {
															LS[50] = (CR[50] & (-CR[50]));
															Rows[5] |= LS[50];
															Columns[5] |= LS[50];
															MD |= LS[50];
															CR[80] = AllN ^ (Rows[8] | Columns[8] | MD);
															if (CR[80] != 0) {
																LS[80] = (CR[80] & (-CR[80]));
																Rows[8] |= LS[80];
																Columns[8] |= LS[80];
																for (CR[11] = AllN ^ (Rows[1] | Columns[2]); CR[11] != 0; CR[11] = (CR[11] & (CR[11] - 1))) {
																	LS[11] = (CR[11] & (-CR[11]));
																	Rows[1] |= LS[11];
																	Columns[2] |= LS[11];
																	for (CR[12] = AllN ^ (Rows[1] | Columns[3]); CR[12] != 0; CR[12] = (CR[12] & (CR[12] - 1))) {
																		LS[12] = (CR[12] & (-CR[12]));
																		Rows[1] |= LS[12];
																		Columns[3] |= LS[12];
																		for (CR[14] = AllN ^ (Rows[1] | Columns[5]); CR[14] != 0; CR[14] = (CR[14] & (CR[14] - 1))) {
																			LS[14] = (CR[14] & (-CR[14]));
																			Rows[1] |= LS[14];
																			Columns[5] |= LS[14];
																			for (CR[15] = AllN ^ (Rows[1] | Columns[6]); CR[15] != 0; CR[15] = (CR[15] & (CR[15] - 1))) {
																				LS[15] = (CR[15] & (-CR[15]));
																				Rows[1] |= LS[15];
																				Columns[6] |= LS[15];
																				for (CR[9] = AllN ^ (Rows[1] | Columns[0]); CR[9] != 0; CR[9] = (CR[9] & (CR[9] - 1))) {
																					LS[9] = (CR[9] & (-CR[9]));
																					Rows[1] |= LS[9];
																					Columns[0] |= LS[9];
																					for (CR[13] = AllN ^ (Rows[1] | Columns[4]); CR[13] != 0; CR[13] = (CR[13] & (CR[13] - 1))) {
																						LS[13] = (CR[13] & (-CR[13]));
																						Rows[1] |= LS[13];
																						Columns[4] |= LS[13];
																						CR[17] = AllN ^ (Rows[1] | Columns[8]);
																						if (CR[17] != 0) {
																							LS[17] = (CR[17] & (-CR[17]));
																							Columns[8] |= LS[17];
																							for (CR[21] = AllN ^ (Rows[2] | Columns[3]); CR[21] != 0; CR[21] = (CR[21] & (CR[21] - 1))) {
																								LS[21] = (CR[21] & (-CR[21]));
																								Rows[2] |= LS[21];
																								Columns[3] |= LS[21];
																								for (CR[23] = AllN ^ (Rows[2] | Columns[5]); CR[23] != 0; CR[23] = (CR[23] & (CR[23] - 1))) {
																									LS[23] = (CR[23] & (-CR[23]));
																									Rows[2] |= LS[23];
																									Columns[5] |= LS[23];
																									for (CR[18] = AllN ^ (Rows[2] | Columns[0]); CR[18] != 0; CR[18] = (CR[18] & (CR[18] - 1))) {
																										LS[18] = (CR[18] & (-CR[18]));
																										Rows[2] |= LS[18];
																										Columns[0] |= LS[18];
																										for (CR[19] = AllN ^ (Rows[2] | Columns[1]); CR[19] != 0; CR[19] = (CR[19] & (CR[19] - 1))) {
																											LS[19] = (CR[19] & (-CR[19]));
																											Rows[2] |= LS[19];
																											Columns[1] |= LS[19];
																											for (CR[22] = AllN ^ (Rows[2] | Columns[4]); CR[22] != 0; CR[22] = (CR[22] & (CR[22] - 1))) {
																												LS[22] = (CR[22] & (-CR[22]));
																												Rows[2] |= LS[22];
																												Columns[4] |= LS[22];
																												for (CR[25] = AllN ^ (Rows[2] | Columns[7]); CR[25] != 0; CR[25] = (CR[25] & (CR[25] - 1))) {
																													LS[25] = (CR[25] & (-CR[25]));
																													Rows[2] |= LS[25];
																													Columns[7] |= LS[25];
																													CR[26] = AllN ^ (Rows[2] | Columns[8]);
																													if (CR[26] != 0) {
																														LS[26] = (CR[26] & (-CR[26]));
																														Columns[8] |= LS[26];
																														for (CR[57] = AllN ^ (Rows[6] | Columns[3]); CR[57] != 0; CR[57] = (CR[57] & (CR[57] - 1))) {
																															LS[57] = (CR[57] & (-CR[57]));
																															Rows[6] |= LS[57];
																															Columns[3] |= LS[57];
																															for (CR[59] = AllN ^ (Rows[6] | Columns[5]); CR[59] != 0; CR[59] = (CR[59] & (CR[59] - 1))) {
																																LS[59] = (CR[59] & (-CR[59]));
																																Rows[6] |= LS[59];
																																Columns[5] |= LS[59];
																																for (CR[54] = AllN ^ (Rows[6] | Columns[0]); CR[54] != 0; CR[54] = (CR[54] & (CR[54] - 1))) {
																																	LS[54] = (CR[54] & (-CR[54]));
																																	Rows[6] |= LS[54];
																																	Columns[0] |= LS[54];
																																	for (CR[55] = AllN ^ (Rows[6] | Columns[1]); CR[55] != 0; CR[55] = (CR[55] & (CR[55] - 1))) {
																																		LS[55] = (CR[55] & (-CR[55]));
																																		Rows[6] |= LS[55];
																																		Columns[1] |= LS[55];
																																		for (CR[58] = AllN ^ (Rows[6] | Columns[4]); CR[58] != 0; CR[58] = (CR[58] & (CR[58] - 1))) {
																																			LS[58] = (CR[58] & (-CR[58]));
																																			Rows[6] |= LS[58];
																																			Columns[4] |= LS[58];
																																			for (CR[61] = AllN ^ (Rows[6] | Columns[7]); CR[61] != 0; CR[61] = (CR[61] & (CR[61] - 1))) {
																																				LS[61] = (CR[61] & (-CR[61]));
																																				Rows[6] |= LS[61];
																																				Columns[7] |= LS[61];
																																				CR[62] = AllN ^ (Rows[6] | Columns[8]);
																																				if (CR[62] != 0) {
																																					LS[62] = (CR[62] & (-CR[62]));
																																					Columns[8] |= LS[62];
																																					for (CR[66] = AllN ^ (Rows[7] | Columns[3]); CR[66] != 0; CR[66] = (CR[66] & (CR[66] - 1))) {
																																						LS[66] = (CR[66] & (-CR[66]));
																																						Rows[7] |= LS[66];
																																						Columns[3] |= LS[66];
																																						for (CR[68] = AllN ^ (Rows[7] | Columns[5]); CR[68] != 0; CR[68] = (CR[68] & (CR[68] - 1))) {
																																							LS[68] = (CR[68] & (-CR[68]));
																																							Rows[7] |= LS[68];
																																							Columns[5] |= LS[68];
																																							for (CR[63] = AllN ^ (Rows[7] | Columns[0]); CR[63] != 0; CR[63] = (CR[63] & (CR[63] - 1))) {
																																								LS[63] = (CR[63] & (-CR[63]));
																																								Rows[7] |= LS[63];
																																								Columns[0] |= LS[63];
																																								for (CR[67] = AllN ^ (Rows[7] | Columns[4]); CR[67] != 0; CR[67] = (CR[67] & (CR[67] - 1))) {
																																									LS[67] = (CR[67] & (-CR[67]));
																																									Rows[7] |= LS[67];
																																									Columns[4] |= LS[67];
																																									for (CR[71] = AllN ^ (Rows[7] | Columns[8]); CR[71] != 0; CR[71] = (CR[71] & (CR[71] - 1))) {
																																										LS[71] = (CR[71] & (-CR[71]));
																																										Rows[7] |= LS[71];
																																										Columns[8] |= LS[71];
																																										for (CR[65] = AllN ^ (Rows[7] | Columns[2]); CR[65] != 0; CR[65] = (CR[65] & (CR[65] - 1))) {
																																											LS[65] = (CR[65] & (-CR[65]));
																																											Rows[7] |= LS[65];
																																											Columns[2] |= LS[65];
																																											CR[69] = AllN ^ (Rows[7] | Columns[6]);
																																											if (CR[69] != 0) {
																																												LS[69] = (CR[69] & (-CR[69]));
																																												Columns[6] |= LS[69];
																																												for (CR[75] = AllN ^ (Rows[8] | Columns[3]); CR[75] != 0; CR[75] = (CR[75] & (CR[75] - 1))) {
																																													LS[75] = (CR[75] & (-CR[75]));
																																													Rows[8] |= LS[75];
																																													Columns[3] |= LS[75];
																																													CR[39] = AllN ^ (Rows[4] | Columns[3]);
																																													if (CR[39] != 0) {
																																														LS[39] = (CR[39] & (-CR[39]));
																																														Rows[4] |= LS[39];
																																														for (CR[77] = AllN ^ (Rows[8] | Columns[5]); CR[77] != 0; CR[77] = (CR[77] & (CR[77] - 1))) {
																																															LS[77] = (CR[77] & (-CR[77]));
																																															Rows[8] |= LS[77];
																																															Columns[5] |= LS[77];
																																															CR[41] = AllN ^ (Rows[4] | Columns[5]);
																																															if (CR[41] != 0) {
																																																LS[41] = (CR[41] & (-CR[41]));
																																																Rows[4] |= LS[41];
																																																for (CR[76] = AllN ^ (Rows[8] | Columns[4]); CR[76] != 0; CR[76] = (CR[76] & (CR[76] - 1))) {
																																																	LS[76] = (CR[76] & (-CR[76]));
																																																	Rows[8] |= LS[76];
																																																	Columns[4] |= LS[76];
																																																	for (CR[73] = AllN ^ (Rows[8] | Columns[1]); CR[73] != 0; CR[73] = (CR[73] & (CR[73] - 1))) {
																																																		LS[73] = (CR[73] & (-CR[73]));
																																																		Rows[8] |= LS[73];
																																																		Columns[1] |= LS[73];
																																																		for (CR[74] = AllN ^ (Rows[8] | Columns[2]); CR[74] != 0; CR[74] = (CR[74] & (CR[74] - 1))) {
																																																			LS[74] = (CR[74] & (-CR[74]));
																																																			Rows[8] |= LS[74];
																																																			Columns[2] |= LS[74];
																																																			for (CR[78] = AllN ^ (Rows[8] | Columns[6]); CR[78] != 0; CR[78] = (CR[78] & (CR[78] - 1))) {
																																																				LS[78] = (CR[78] & (-CR[78]));
																																																				Rows[8] |= LS[78];
																																																				Columns[6] |= LS[78];
																																																				CR[79] = AllN ^ (Rows[8] | Columns[7]);
																																																				if (CR[79] != 0) {
																																																					LS[79] = (CR[79] & (-CR[79]));
																																																					Columns[7] |= LS[79];
																																																					L[34] = Rows[3] | Columns[7];
																																																					L[43] = Rows[4] | Columns[7];
																																																					L[52] = Rows[5] | Columns[7];
																																																					if ((L[34] == AllN) || (L[43] == AllN) || (L[52] == AllN)) goto loop79end;
																																																					for (CR[31] = AllN ^ (Rows[3] | Columns[4]); CR[31] != 0; CR[31] = (CR[31] & (CR[31] - 1))) {
																																																						LS[31] = (CR[31] & (-CR[31]));
																																																						Rows[3] |= LS[31];
																																																						Columns[4] |= LS[31];
																																																						L[27] = Rows[3] | Columns[0];
																																																						L[28] = Rows[3] | Columns[1];
																																																						L[29] = Rows[3] | Columns[2];
																																																						L[33] = Rows[3] | Columns[6];
																																																						L[34] = Rows[3] | Columns[7];
																																																						L[35] = Rows[3] | Columns[8];
																																																						L[49] = Rows[5] | Columns[4];
																																																						if ((L[27] == AllN) || (L[28] == AllN) || (L[29] == AllN) || (L[33] == AllN) || (L[34] == AllN) || (L[35] == AllN) || (L[49] == AllN)) goto loop31end;
																																																						CR[49] = AllN ^ (Rows[5] | Columns[4]);
																																																						if (CR[49] != 0) {
																																																							LS[49] = (CR[49] & (-CR[49]));
																																																							Rows[5] |= LS[49];
																																																							L[45] = Rows[5] | Columns[0];
																																																							L[46] = Rows[5] | Columns[1];
																																																							L[47] = Rows[5] | Columns[2];
																																																							L[51] = Rows[5] | Columns[6];
																																																							L[52] = Rows[5] | Columns[7];
																																																							L[53] = Rows[5] | Columns[8];
																																																							if ((L[45] == AllN) || (L[46] == AllN) || (L[47] == AllN) || (L[51] == AllN) || (L[52] == AllN) || (L[53] == AllN)) goto loop49end;
																																																							for (CR[27] = AllN ^ (Rows[3] | Columns[0]); CR[27] != 0; CR[27] = (CR[27] & (CR[27] - 1))) {
																																																								LS[27] = (CR[27] & (-CR[27]));
																																																								Rows[3] |= LS[27];
																																																								Columns[0] |= LS[27];
																																																								L[28] = Rows[3] | Columns[1];
																																																								L[29] = Rows[3] | Columns[2];
																																																								L[33] = Rows[3] | Columns[6];
																																																								L[34] = Rows[3] | Columns[7];
																																																								L[35] = Rows[3] | Columns[8];
																																																								L[36] = Rows[4] | Columns[0];
																																																								L[45] = Rows[5] | Columns[0];
																																																								if ((L[28] == AllN) || (L[29] == AllN) || (L[33] == AllN) || (L[34] == AllN) || (L[35] == AllN) || (L[36] == AllN) || (L[45] == AllN)) goto loop27end;
																																																								for (CR[28] = AllN ^ (Rows[3] | Columns[1]); CR[28] != 0; CR[28] = (CR[28] & (CR[28] - 1))) {
																																																									LS[28] = (CR[28] & (-CR[28]));
																																																									Rows[3] |= LS[28];
																																																									Columns[1] |= LS[28];
																																																									L[29] = Rows[3] | Columns[2];
																																																									L[33] = Rows[3] | Columns[6];
																																																									L[34] = Rows[3] | Columns[7];
																																																									L[35] = Rows[3] | Columns[8];
																																																									L[37] = Rows[4] | Columns[1];
																																																									L[46] = Rows[5] | Columns[1];
																																																									if ((L[29] == AllN) || (L[33] == AllN) || (L[34] == AllN) || (L[35] == AllN) || (L[37] == AllN) || (L[46] == AllN)) goto loop28end;
																																																									for (CR[29] = AllN ^ (Rows[3] | Columns[2]); CR[29] != 0; CR[29] = (CR[29] & (CR[29] - 1))) {
																																																										LS[29] = (CR[29] & (-CR[29]));
																																																										Rows[3] |= LS[29];
																																																										Columns[2] |= LS[29];
																																																										L[33] = Rows[3] | Columns[6];
																																																										L[34] = Rows[3] | Columns[7];
																																																										L[35] = Rows[3] | Columns[8];
																																																										L[38] = Rows[4] | Columns[2];
																																																										L[47] = Rows[5] | Columns[2];
																																																										if ((L[33] == AllN) || (L[34] == AllN) || (L[35] == AllN) || (L[38] == AllN) || (L[47] == AllN)) goto loop29end;
																																																										for (CR[33] = AllN ^ (Rows[3] | Columns[6]); CR[33] != 0; CR[33] = (CR[33] & (CR[33] - 1))) {
																																																											LS[33] = (CR[33] & (-CR[33]));
																																																											Rows[3] |= LS[33];
																																																											Columns[6] |= LS[33];
																																																											L[34] = Rows[3] | Columns[7];
																																																											L[35] = Rows[3] | Columns[8];
																																																											L[42] = Rows[4] | Columns[6];
																																																											L[51] = Rows[5] | Columns[6];
																																																											if ((L[34] == AllN) || (L[35] == AllN) || (L[42] == AllN) || (L[51] == AllN)) goto loop33end;
																																																											for (CR[34] = AllN ^ (Rows[3] | Columns[7]); CR[34] != 0; CR[34] = (CR[34] & (CR[34] - 1))) {
																																																												LS[34] = (CR[34] & (-CR[34]));
																																																												Rows[3] |= LS[34];
																																																												Columns[7] |= LS[34];
																																																												L[35] = Rows[3] | Columns[8];
																																																												L[43] = Rows[4] | Columns[7];
																																																												L[52] = Rows[5] | Columns[7];
																																																												if ((L[35] == AllN) || (L[43] == AllN) || (L[52] == AllN)) goto loop34end;
																																																												CR[35] = AllN ^ (Rows[3] | Columns[8]);
																																																												if (CR[35] != 0) {
																																																													LS[35] = (CR[35] & (-CR[35]));
																																																													Columns[8] |= LS[35];
																																																													L[44] = Rows[4] | Columns[8];
																																																													L[53] = Rows[5] | Columns[8];
																																																													if ((L[44] == AllN) || (L[53] == AllN)) goto loop35end;
																																																													for (CR[36] = AllN ^ (Rows[4] | Columns[0]); CR[36] != 0; CR[36] = (CR[36] & (CR[36] - 1))) {
																																																														LS[36] = (CR[36] & (-CR[36]));
																																																														Rows[4] |= LS[36];
																																																														Columns[0] |= LS[36];
																																																														CR[45] = AllN ^ (Rows[5] | Columns[0]);
																																																														if (CR[45] != 0) {
																																																															LS[45] = (CR[45] & (-CR[45]));
																																																															Rows[5] |= LS[45];
																																																															for (CR[37] = AllN ^ (Rows[4] | Columns[1]); CR[37] != 0; CR[37] = (CR[37] & (CR[37] - 1))) {
																																																																LS[37] = (CR[37] & (-CR[37]));
																																																																Rows[4] |= LS[37];
																																																																Columns[1] |= LS[37];
																																																																CR[46] = AllN ^ (Rows[5] | Columns[1]);
																																																																if (CR[46] != 0) {
																																																																	LS[46] = (CR[46] & (-CR[46]));
																																																																	Rows[5] |= LS[46];
																																																																	for (CR[38] = AllN ^ (Rows[4] | Columns[2]); CR[38] != 0; CR[38] = (CR[38] & (CR[38] - 1))) {
																																																																		LS[38] = (CR[38] & (-CR[38]));
																																																																		Rows[4] |= LS[38];
																																																																		Columns[2] |= LS[38];
																																																																		CR[47] = AllN ^ (Rows[5] | Columns[2]);
																																																																		if (CR[47] != 0) {
																																																																			LS[47] = (CR[47] & (-CR[47]));
																																																																			Rows[5] |= LS[47];
																																																																			for (CR[42] = AllN ^ (Rows[4] | Columns[6]); CR[42] != 0; CR[42] = (CR[42] & (CR[42] - 1))) {
																																																																				LS[42] = (CR[42] & (-CR[42]));
																																																																				Rows[4] |= LS[42];
																																																																				Columns[6] |= LS[42];
																																																																				CR[51] = AllN ^ (Rows[5] | Columns[6]);
																																																																				if (CR[51] != 0) {
																																																																					LS[51] = (CR[51] & (-CR[51]));
																																																																					Rows[5] |= LS[51];
																																																																					for (CR[43] = AllN ^ (Rows[4] | Columns[7]); CR[43] != 0; CR[43] = (CR[43] & (CR[43] - 1))) {
																																																																						LS[43] = (CR[43] & (-CR[43]));
																																																																						Rows[4] |= LS[43];
																																																																						Columns[7] |= LS[43];
																																																																						CR[44] = AllN ^ (Rows[4] | Columns[8]);
																																																																						if (CR[44] != 0) {
																																																																							LS[44] = (CR[44] & (-CR[44]));
																																																																							Columns[8] |= LS[44];
																																																																							CR[52] = AllN ^ (Rows[5] | Columns[7]);
																																																																							if (CR[52] != 0) {
																																																																								LS[52] = (CR[52] & (-CR[52]));
																																																																								Rows[5] |= LS[52];
																																																																								CR[53] = AllN ^ (Rows[5] | Columns[8]);
																																																																								if (CR[53] != 0) {
																																																																									//		LS[53] = (CR[53] & (-CR[53]));
																																																																									//	Columns[8] |= LS[53];
																																																																									SquaresCnt++;
																																																																									if (SquaresCnt % 10000000 == 0) {
																																																																										StopProf();
																																																																										cout << "Squares found: " << SquaresCnt << endl;
																																																																										cout << "Average time: " << 1.0*ProfResult() / ProcFreq / SquaresCnt * 1000 << " ms per square" << endl;
																																																																										cout << "Squares per second: " << 1.0 / (1.0 * ProfResult() / ProcFreq / SquaresCnt) << endl << endl;
																																																																									}
																																																																									//Columns[8] ^= LS[53];

																																																																								}
																																																																								Rows[5] ^= LS[52];
																																																																							}
																																																																							Columns[8] ^= LS[44];
																																																																						}
																																																																						Rows[4] ^= LS[43];
																																																																						Columns[7] ^= LS[43];
																																																																					}
																																																																					Rows[5] ^= LS[51];
																																																																				}
																																																																				Rows[4] ^= LS[42];
																																																																				Columns[6] ^= LS[42];
																																																																			}
																																																																			Rows[5] ^= LS[47];
																																																																		}
																																																																		Rows[4] ^= LS[38];
																																																																		Columns[2] ^= LS[38];
																																																																	}
																																																																	Rows[5] ^= LS[46];
																																																																}
																																																																Rows[4] ^= LS[37];
																																																																Columns[1] ^= LS[37];
																																																															}
																																																															Rows[5] ^= LS[45];
																																																														}
																																																														Rows[4] ^= LS[36];
																																																														Columns[0] ^= LS[36];
																																																													}
																																																												loop35end:
																																																													Columns[8] ^= LS[35];
																																																												}
																																																											loop34end:
																																																												Rows[3] ^= LS[34];
																																																												Columns[7] ^= LS[34];
																																																											}
																																																										loop33end:
																																																											Rows[3] ^= LS[33];
																																																											Columns[6] ^= LS[33];
																																																										}
																																																									loop29end:
																																																										Rows[3] ^= LS[29];
																																																										Columns[2] ^= LS[29];
																																																									}
																																																								loop28end:
																																																									Rows[3] ^= LS[28];
																																																									Columns[1] ^= LS[28];
																																																								}
																																																							loop27end:
																																																								Rows[3] ^= LS[27];
																																																								Columns[0] ^= LS[27];
																																																							}
																																																						loop49end:
																																																							Rows[5] ^= LS[49];
																																																						}
																																																					loop31end:
																																																						Rows[3] ^= LS[31];
																																																						Columns[4] ^= LS[31];
																																																					}
																																																				loop79end:
																																																					Columns[7] ^= LS[79];
																																																				}
																																																				Rows[8] ^= LS[78];
																																																				Columns[6] ^= LS[78];
																																																			}
																																																			Rows[8] ^= LS[74];
																																																			Columns[2] ^= LS[74];
																																																		}
																																																		Rows[8] ^= LS[73];
																																																		Columns[1] ^= LS[73];
																																																	}
																																																	Rows[8] ^= LS[76];
																																																	Columns[4] ^= LS[76];
																																																}
																																																Rows[4] ^= LS[41];
																																															}
																																															Rows[8] ^= LS[77];
																																															Columns[5] ^= LS[77];
																																														}
																																														Rows[4] ^= LS[39];
																																													}
																																													Rows[8] ^= LS[75];
																																													Columns[3] ^= LS[75];
																																												}
																																												Columns[6] ^= LS[69];
																																											}
																																											Rows[7] ^= LS[65];
																																											Columns[2] ^= LS[65];
																																										}
																																										Rows[7] ^= LS[71];
																																										Columns[8] ^= LS[71];
																																									}
																																									Rows[7] ^= LS[67];
																																									Columns[4] ^= LS[67];
																																								}
																																								Rows[7] ^= LS[63];
																																								Columns[0] ^= LS[63];
																																							}
																																							Rows[7] ^= LS[68];
																																							Columns[5] ^= LS[68];
																																						}
																																						Rows[7] ^= LS[66];
																																						Columns[3] ^= LS[66];
																																					}
																																					Columns[8] ^= LS[62];
																																				}
																																				Rows[6] ^= LS[61];
																																				Columns[7] ^= LS[61];
																																			}
																																			Rows[6] ^= LS[58];
																																			Columns[4] ^= LS[58];
																																		}
																																		Rows[6] ^= LS[55];
																																		Columns[1] ^= LS[55];
																																	}
																																	Rows[6] ^= LS[54];
																																	Columns[0] ^= LS[54];
																																}
																																Rows[6] ^= LS[59];
																																Columns[5] ^= LS[59];
																															}
																															Rows[6] ^= LS[57];
																															Columns[3] ^= LS[57];
																														}
																														Columns[8] ^= LS[26];
																													}
																													Rows[2] ^= LS[25];
																													Columns[7] ^= LS[25];
																												}
																												Rows[2] ^= LS[22];
																												Columns[4] ^= LS[22];
																											}
																											Rows[2] ^= LS[19];
																											Columns[1] ^= LS[19];
																										}
																										Rows[2] ^= LS[18];
																										Columns[0] ^= LS[18];
																									}
																									Rows[2] ^= LS[23];
																									Columns[5] ^= LS[23];
																								}
																								Rows[2] ^= LS[21];
																								Columns[3] ^= LS[21];
																							}
																							Columns[8] ^= LS[17];
																						}
																						Rows[1] ^= LS[13];
																						Columns[4] ^= LS[13];
																					}
																					Rows[1] ^= LS[9];
																					Columns[0] ^= LS[9];
																				}
																				Rows[1] ^= LS[15];
																				Columns[6] ^= LS[15];
																			}
																			Rows[1] ^= LS[14];
																			Columns[5] ^= LS[14];
																		}
																		Rows[1] ^= LS[12];
																		Columns[3] ^= LS[12];
																	}
																	Rows[1] ^= LS[11];
																	Columns[2] ^= LS[11];
																}
																Rows[8] ^= LS[80];
																Columns[8] ^= LS[80];
															}
															Rows[5] ^= LS[50];
															Columns[5] ^= LS[50];
															MD ^= LS[50];
														}
														Rows[8] ^= LS[72];
														Columns[0] ^= LS[72];
													}
													Rows[5] ^= LS[48];
													Columns[3] ^= LS[48];
													AD ^= LS[48];
												}
												Rows[3] ^= LS[32];
												Columns[5] ^= LS[32];
												AD ^= LS[32];
											}
											Rows[3] ^= LS[30];
											Columns[3] ^= LS[30];
											MD ^= LS[30];
										}
										Rows[6] ^= LS[60];
										Columns[6] ^= LS[60];
										MD ^= LS[60];
									}
									Rows[6] ^= LS[56];
									Columns[2] ^= LS[56];
									AD ^= LS[56];
								}
								Rows[2] ^= LS[24];
								Columns[6] ^= LS[24];
								AD ^= LS[24];
							}
							Rows[2] ^= LS[20];
							Columns[2] ^= LS[20];
							MD ^= LS[20];
						}
						Rows[7] ^= LS[70];
						Columns[7] ^= LS[70];
						MD ^= LS[70];
					}
					Rows[7] ^= LS[64];
					Columns[1] ^= LS[64];
					AD ^= LS[64];
				}
				Rows[1] ^= LS[16];
				Columns[7] ^= LS[16];
				AD ^= LS[16];
			}
			Rows[1] ^= LS[10];
			Columns[1] ^= LS[10];
			MD ^= LS[10];
		}
		Rows[4] ^= LS[40];
		Columns[4] ^= LS[40];
		MD ^= LS[40];
		AD ^= LS[40];
	}
}

