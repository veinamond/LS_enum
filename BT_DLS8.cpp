#include <iostream>
#include <chrono>
#include <vector>
static inline double cpuTime(void) { return (double)clock() / CLOCKS_PER_SEC; }
using namespace std;
const int N = 8;
const uint32_t MaxN = 1 << N;
const uint32_t AllN = MaxN - 1;
int32_t LS[N*N];
int32_t CR[N*N];
int32_t L[N*N];
int32_t CNT[N*N];
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

void main()
{
	double t1 = cpuTime();
	Reset();
	Generate();

	double t2 = cpuTime();
	cout << "Total squares count: " << SquaresCnt << endl;
	cout << "Time spent: " << t2 - t1 << endl;
	cout << "OK";
	getchar();
}
void Generate()
{
	double t0 = cpuTime();
	StartProf();
	for (CR[9] = AllN ^ (Rows[1] | Columns[1] | MD); CR[9] != 0; CR[9] = (CR[9] & (CR[9] - 1))) {
		LS[9] = (CR[9] & (-CR[9]));
		Rows[1] |= LS[9];
		Columns[1] |= LS[9];
		MD |= LS[9];
		for (CR[14] = AllN ^ (Rows[1] | Columns[6] | AD); CR[14] != 0; CR[14] = (CR[14] & (CR[14] - 1))) {
			LS[14] = (CR[14] & (-CR[14]));
			Rows[1] |= LS[14];
			Columns[6] |= LS[14];
			AD |= LS[14];
			for (CR[49] = AllN ^ (Rows[6] | Columns[1] | AD); CR[49] != 0; CR[49] = (CR[49] & (CR[49] - 1))) {
				LS[49] = (CR[49] & (-CR[49]));
				Rows[6] |= LS[49];
				Columns[1] |= LS[49];
				AD |= LS[49];
				for (CR[54] = AllN ^ (Rows[6] | Columns[6] | MD); CR[54] != 0; CR[54] = (CR[54] & (CR[54] - 1))) {
					LS[54] = (CR[54] & (-CR[54]));
					Rows[6] |= LS[54];
					Columns[6] |= LS[54];
					MD |= LS[54];
					for (CR[18] = AllN ^ (Rows[2] | Columns[2] | MD); CR[18] != 0; CR[18] = (CR[18] & (CR[18] - 1))) {
						LS[18] = (CR[18] & (-CR[18]));
						Rows[2] |= LS[18];
						Columns[2] |= LS[18];
						MD |= LS[18];
						for (CR[21] = AllN ^ (Rows[2] | Columns[5] | AD); CR[21] != 0; CR[21] = (CR[21] & (CR[21] - 1))) {
							LS[21] = (CR[21] & (-CR[21]));
							Rows[2] |= LS[21];
							Columns[5] |= LS[21];
							AD |= LS[21];
							for (CR[42] = AllN ^ (Rows[5] | Columns[2] | AD); CR[42] != 0; CR[42] = (CR[42] & (CR[42] - 1))) {
								LS[42] = (CR[42] & (-CR[42]));
								Rows[5] |= LS[42];
								Columns[2] |= LS[42];
								AD |= LS[42];
								for (CR[45] = AllN ^ (Rows[5] | Columns[5] | MD); CR[45] != 0; CR[45] = (CR[45] & (CR[45] - 1))) {
									LS[45] = (CR[45] & (-CR[45]));
									Rows[5] |= LS[45];
									Columns[5] |= LS[45];
									MD |= LS[45];
									for (CR[27] = AllN ^ (Rows[3] | Columns[3] | MD); CR[27] != 0; CR[27] = (CR[27] & (CR[27] - 1))) {
										LS[27] = (CR[27] & (-CR[27]));
										Rows[3] |= LS[27];
										Columns[3] |= LS[27];
										MD |= LS[27];
										for (CR[28] = AllN ^ (Rows[3] | Columns[4] | AD); CR[28] != 0; CR[28] = (CR[28] & (CR[28] - 1))) {
											LS[28] = (CR[28] & (-CR[28]));
											Rows[3] |= LS[28];
											Columns[4] |= LS[28];
											AD |= LS[28];
											for (CR[35] = AllN ^ (Rows[4] | Columns[3] | AD); CR[35] != 0; CR[35] = (CR[35] & (CR[35] - 1))) {
												LS[35] = (CR[35] & (-CR[35]));
												Rows[4] |= LS[35];
												Columns[3] |= LS[35];
												AD |= LS[35];
												CR[56] = AllN ^ (Rows[7] | Columns[0] | AD);
												if (CR[56] != 0) {
													LS[56] = (CR[56] & (-CR[56]));
													Rows[7] |= LS[56];
													Columns[0] |= LS[56];
													for (CR[36] = AllN ^ (Rows[4] | Columns[4] | MD); CR[36] != 0; CR[36] = (CR[36] & (CR[36] - 1))) {
														LS[36] = (CR[36] & (-CR[36]));
														Rows[4] |= LS[36];
														Columns[4] |= LS[36];
														MD |= LS[36];
														CR[63] = AllN ^ (Rows[7] | Columns[7] | MD);
														if (CR[63] != 0) {
															LS[63] = (CR[63] & (-CR[63]));
															Rows[7] |= LS[63];
															Columns[7] |= LS[63];
															for (CR[10] = AllN ^ (Rows[1] | Columns[2]); CR[10] != 0; CR[10] = (CR[10] & (CR[10] - 1))) {
																LS[10] = (CR[10] & (-CR[10]));
																Rows[1] |= LS[10];
																Columns[2] |= LS[10];
																for (CR[11] = AllN ^ (Rows[1] | Columns[3]); CR[11] != 0; CR[11] = (CR[11] & (CR[11] - 1))) {
																	LS[11] = (CR[11] & (-CR[11]));
																	Rows[1] |= LS[11];
																	Columns[3] |= LS[11];
																	for (CR[12] = AllN ^ (Rows[1] | Columns[4]); CR[12] != 0; CR[12] = (CR[12] & (CR[12] - 1))) {
																		LS[12] = (CR[12] & (-CR[12]));
																		Rows[1] |= LS[12];
																		Columns[4] |= LS[12];
																		for (CR[13] = AllN ^ (Rows[1] | Columns[5]); CR[13] != 0; CR[13] = (CR[13] & (CR[13] - 1))) {
																			LS[13] = (CR[13] & (-CR[13]));
																			Rows[1] |= LS[13];
																			Columns[5] |= LS[13];
																			for (CR[8] = AllN ^ (Rows[1] | Columns[0]); CR[8] != 0; CR[8] = (CR[8] & (CR[8] - 1))) {
																				LS[8] = (CR[8] & (-CR[8]));
																				Rows[1] |= LS[8];
																				Columns[0] |= LS[8];
																				CR[15] = AllN ^ (Rows[1] | Columns[7]);
																				if (CR[15] != 0) {
																					LS[15] = (CR[15] & (-CR[15]));
																					Columns[7] |= LS[15];
																					for (CR[19] = AllN ^ (Rows[2] | Columns[3]); CR[19] != 0; CR[19] = (CR[19] & (CR[19] - 1))) {
																						LS[19] = (CR[19] & (-CR[19]));
																						Rows[2] |= LS[19];
																						Columns[3] |= LS[19];
																						for (CR[20] = AllN ^ (Rows[2] | Columns[4]); CR[20] != 0; CR[20] = (CR[20] & (CR[20] - 1))) {
																							LS[20] = (CR[20] & (-CR[20]));
																							Rows[2] |= LS[20];
																							Columns[4] |= LS[20];
																							for (CR[16] = AllN ^ (Rows[2] | Columns[0]); CR[16] != 0; CR[16] = (CR[16] & (CR[16] - 1))) {
																								LS[16] = (CR[16] & (-CR[16]));
																								Rows[2] |= LS[16];
																								Columns[0] |= LS[16];
																								for (CR[17] = AllN ^ (Rows[2] | Columns[1]); CR[17] != 0; CR[17] = (CR[17] & (CR[17] - 1))) {
																									LS[17] = (CR[17] & (-CR[17]));
																									Rows[2] |= LS[17];
																									Columns[1] |= LS[17];
																									for (CR[22] = AllN ^ (Rows[2] | Columns[6]); CR[22] != 0; CR[22] = (CR[22] & (CR[22] - 1))) {
																										LS[22] = (CR[22] & (-CR[22]));
																										Rows[2] |= LS[22];
																										Columns[6] |= LS[22];
																										CR[23] = AllN ^ (Rows[2] | Columns[7]);
																										if (CR[23] != 0) {
																											LS[23] = (CR[23] & (-CR[23]));
																											Columns[7] |= LS[23];
																											for (CR[43] = AllN ^ (Rows[5] | Columns[3]); CR[43] != 0; CR[43] = (CR[43] & (CR[43] - 1))) {
																												LS[43] = (CR[43] & (-CR[43]));
																												Rows[5] |= LS[43];
																												Columns[3] |= LS[43];
																												for (CR[44] = AllN ^ (Rows[5] | Columns[4]); CR[44] != 0; CR[44] = (CR[44] & (CR[44] - 1))) {
																													LS[44] = (CR[44] & (-CR[44]));
																													Rows[5] |= LS[44];
																													Columns[4] |= LS[44];
																													for (CR[40] = AllN ^ (Rows[5] | Columns[0]); CR[40] != 0; CR[40] = (CR[40] & (CR[40] - 1))) {
																														LS[40] = (CR[40] & (-CR[40]));
																														Rows[5] |= LS[40];
																														Columns[0] |= LS[40];
																														for (CR[41] = AllN ^ (Rows[5] | Columns[1]); CR[41] != 0; CR[41] = (CR[41] & (CR[41] - 1))) {
																															LS[41] = (CR[41] & (-CR[41]));
																															Rows[5] |= LS[41];
																															Columns[1] |= LS[41];
																															for (CR[46] = AllN ^ (Rows[5] | Columns[6]); CR[46] != 0; CR[46] = (CR[46] & (CR[46] - 1))) {
																																LS[46] = (CR[46] & (-CR[46]));
																																Rows[5] |= LS[46];
																																Columns[6] |= LS[46];
																																CR[47] = AllN ^ (Rows[5] | Columns[7]);
																																if (CR[47] != 0) {
																																	LS[47] = (CR[47] & (-CR[47]));
																																	Columns[7] |= LS[47];
																																	for (CR[51] = AllN ^ (Rows[6] | Columns[3]); CR[51] != 0; CR[51] = (CR[51] & (CR[51] - 1))) {
																																		LS[51] = (CR[51] & (-CR[51]));
																																		Rows[6] |= LS[51];
																																		Columns[3] |= LS[51];
																																		CR[59] = AllN ^ (Rows[7] | Columns[3]);
																																		if (CR[59] != 0) {
																																			LS[59] = (CR[59] & (-CR[59]));
																																			Rows[7] |= LS[59];
																																			for (CR[52] = AllN ^ (Rows[6] | Columns[4]); CR[52] != 0; CR[52] = (CR[52] & (CR[52] - 1))) {
																																				LS[52] = (CR[52] & (-CR[52]));
																																				Rows[6] |= LS[52];
																																				Columns[4] |= LS[52];
																																				CR[60] = AllN ^ (Rows[7] | Columns[4]);
																																				if (CR[60] != 0) {
																																					LS[60] = (CR[60] & (-CR[60]));
																																					Rows[7] |= LS[60];
																																					for (CR[48] = AllN ^ (Rows[6] | Columns[0]); CR[48] != 0; CR[48] = (CR[48] & (CR[48] - 1))) {
																																						LS[48] = (CR[48] & (-CR[48]));
																																						Rows[6] |= LS[48];
																																						Columns[0] |= LS[48];
																																						for (CR[55] = AllN ^ (Rows[6] | Columns[7]); CR[55] != 0; CR[55] = (CR[55] & (CR[55] - 1))) {
																																							LS[55] = (CR[55] & (-CR[55]));
																																							Rows[6] |= LS[55];
																																							Columns[7] |= LS[55];
																																							for (CR[50] = AllN ^ (Rows[6] | Columns[2]); CR[50] != 0; CR[50] = (CR[50] & (CR[50] - 1))) {
																																								LS[50] = (CR[50] & (-CR[50]));
																																								Rows[6] |= LS[50];
																																								Columns[2] |= LS[50];
																																								CR[53] = AllN ^ (Rows[6] | Columns[5]);
																																								if (CR[53] != 0) {
																																									LS[53] = (CR[53] & (-CR[53]));
																																									Columns[5] |= LS[53];
																																									for (CR[57] = AllN ^ (Rows[7] | Columns[1]); CR[57] != 0; CR[57] = (CR[57] & (CR[57] - 1))) {
																																										LS[57] = (CR[57] & (-CR[57]));
																																										Rows[7] |= LS[57];
																																										Columns[1] |= LS[57];
																																										for (CR[58] = AllN ^ (Rows[7] | Columns[2]); CR[58] != 0; CR[58] = (CR[58] & (CR[58] - 1))) {
																																											LS[58] = (CR[58] & (-CR[58]));
																																											Rows[7] |= LS[58];
																																											Columns[2] |= LS[58];
																																											for (CR[61] = AllN ^ (Rows[7] | Columns[5]); CR[61] != 0; CR[61] = (CR[61] & (CR[61] - 1))) {
																																												LS[61] = (CR[61] & (-CR[61]));
																																												Rows[7] |= LS[61];
																																												Columns[5] |= LS[61];
																																												CR[62] = AllN ^ (Rows[7] | Columns[6]);
																																												if (CR[62] != 0) {
																																													LS[62] = (CR[62] & (-CR[62]));
																																													Columns[6] |= LS[62];
																																													for (CR[24] = AllN ^ (Rows[3] | Columns[0]); CR[24] != 0; CR[24] = (CR[24] & (CR[24] - 1))) {
																																														LS[24] = (CR[24] & (-CR[24]));
																																														Rows[3] |= LS[24];
																																														Columns[0] |= LS[24];
																																														CR[32] = AllN ^ (Rows[4] | Columns[0]);
																																														if (CR[32] != 0) {
																																															LS[32] = (CR[32] & (-CR[32]));
																																															Rows[4] |= LS[32];
																																															for (CR[25] = AllN ^ (Rows[3] | Columns[1]); CR[25] != 0; CR[25] = (CR[25] & (CR[25] - 1))) {
																																																LS[25] = (CR[25] & (-CR[25]));
																																																Rows[3] |= LS[25];
																																																Columns[1] |= LS[25];
																																																CR[33] = AllN ^ (Rows[4] | Columns[1]);
																																																if (CR[33] != 0) {
																																																	LS[33] = (CR[33] & (-CR[33]));
																																																	Rows[4] |= LS[33];
																																																	for (CR[26] = AllN ^ (Rows[3] | Columns[2]); CR[26] != 0; CR[26] = (CR[26] & (CR[26] - 1))) {
																																																		LS[26] = (CR[26] & (-CR[26]));
																																																		Rows[3] |= LS[26];
																																																		Columns[2] |= LS[26];
																																																		CR[34] = AllN ^ (Rows[4] | Columns[2]);
																																																		if (CR[34] != 0) {
																																																			LS[34] = (CR[34] & (-CR[34]));
																																																			Rows[4] |= LS[34];
																																																			for (CR[29] = AllN ^ (Rows[3] | Columns[5]); CR[29] != 0; CR[29] = (CR[29] & (CR[29] - 1))) {
																																																				LS[29] = (CR[29] & (-CR[29]));
																																																				Rows[3] |= LS[29];
																																																				Columns[5] |= LS[29];
																																																				CR[37] = AllN ^ (Rows[4] | Columns[5]);
																																																				if (CR[37] != 0) {
																																																					LS[37] = (CR[37] & (-CR[37]));
																																																					Rows[4] |= LS[37];
																																																					for (CR[30] = AllN ^ (Rows[3] | Columns[6]); CR[30] != 0; CR[30] = (CR[30] & (CR[30] - 1))) {
																																																						LS[30] = (CR[30] & (-CR[30]));
																																																						Rows[3] |= LS[30];
																																																						Columns[6] |= LS[30];
																																																						CR[31] = AllN ^ (Rows[3] | Columns[7]);
																																																						if (CR[31] != 0) {
																																																							LS[31] = (CR[31] & (-CR[31]));
																																																							Columns[7] |= LS[31];
																																																							CR[38] = AllN ^ (Rows[4] | Columns[6]);
																																																							if (CR[38] != 0) {
																																																								LS[38] = (CR[38] & (-CR[38]));
																																																								Rows[4] |= LS[38];
																																																								CR[39] = AllN ^ (Rows[4] | Columns[7]);
																																																								if (CR[39] != 0) {
																																																									LS[39] = (CR[39] & (-CR[39]));
																																																									SquaresCnt++;
																																																									if (SquaresCnt % 10000000 == 0) {
																																																										double t1 = cpuTime();
																																																										StopProf();
																																																										cout << "Squares found: " << SquaresCnt << endl;
																																																										//cout << "Average time: " << 1.0*ProfResult() / ProcFreq / SquaresCnt * 1000 << " ms per square" << endl;
																																																										//cout << "Squares per second: " << 1.0 / (1.0 * ProfResult() / ProcFreq / SquaresCnt) << endl << endl;
																																																										cout << "Squares per second: " << (double)((double)SquaresCnt / (t1 - t0)) << endl << endl;
																																																									}
																																																								}
																																																								Rows[4] ^= LS[38];
																																																							}
																																																							Columns[7] ^= LS[31];
																																																						}
																																																						Rows[3] ^= LS[30];
																																																						Columns[6] ^= LS[30];
																																																					}
																																																					Rows[4] ^= LS[37];
																																																				}
																																																				Rows[3] ^= LS[29];
																																																				Columns[5] ^= LS[29];
																																																			}
																																																			Rows[4] ^= LS[34];
																																																		}
																																																		Rows[3] ^= LS[26];
																																																		Columns[2] ^= LS[26];
																																																	}
																																																	Rows[4] ^= LS[33];
																																																}
																																																Rows[3] ^= LS[25];
																																																Columns[1] ^= LS[25];
																																															}
																																															Rows[4] ^= LS[32];
																																														}
																																														Rows[3] ^= LS[24];
																																														Columns[0] ^= LS[24];
																																													}
																																													Columns[6] ^= LS[62];
																																												}
																																												Rows[7] ^= LS[61];
																																												Columns[5] ^= LS[61];
																																											}
																																											Rows[7] ^= LS[58];
																																											Columns[2] ^= LS[58];
																																										}
																																										Rows[7] ^= LS[57];
																																										Columns[1] ^= LS[57];
																																									}
																																									Columns[5] ^= LS[53];
																																								}
																																								Rows[6] ^= LS[50];
																																								Columns[2] ^= LS[50];
																																							}
																																							Rows[6] ^= LS[55];
																																							Columns[7] ^= LS[55];
																																						}
																																						Rows[6] ^= LS[48];
																																						Columns[0] ^= LS[48];
																																					}
																																					Rows[7] ^= LS[60];
																																				}
																																				Rows[6] ^= LS[52];
																																				Columns[4] ^= LS[52];
																																			}
																																			Rows[7] ^= LS[59];
																																		}
																																		Rows[6] ^= LS[51];
																																		Columns[3] ^= LS[51];
																																	}
																																	Columns[7] ^= LS[47];
																																}
																																Rows[5] ^= LS[46];
																																Columns[6] ^= LS[46];
																															}
																															Rows[5] ^= LS[41];
																															Columns[1] ^= LS[41];
																														}
																														Rows[5] ^= LS[40];
																														Columns[0] ^= LS[40];
																													}
																													Rows[5] ^= LS[44];
																													Columns[4] ^= LS[44];
																												}
																												Rows[5] ^= LS[43];
																												Columns[3] ^= LS[43];
																											}
																											Columns[7] ^= LS[23];
																										}
																										Rows[2] ^= LS[22];
																										Columns[6] ^= LS[22];
																									}
																									Rows[2] ^= LS[17];
																									Columns[1] ^= LS[17];
																								}
																								Rows[2] ^= LS[16];
																								Columns[0] ^= LS[16];
																							}
																							Rows[2] ^= LS[20];
																							Columns[4] ^= LS[20];
																						}
																						Rows[2] ^= LS[19];
																						Columns[3] ^= LS[19];
																					}
																					Columns[7] ^= LS[15];
																				}
																				Rows[1] ^= LS[8];
																				Columns[0] ^= LS[8];
																			}
																			Rows[1] ^= LS[13];
																			Columns[5] ^= LS[13];
																		}
																		Rows[1] ^= LS[12];
																		Columns[4] ^= LS[12];
																	}
																	Rows[1] ^= LS[11];
																	Columns[3] ^= LS[11];
																}
																Rows[1] ^= LS[10];
																Columns[2] ^= LS[10];
															}
															Rows[7] ^= LS[63];
															Columns[7] ^= LS[63];
														}
														Rows[4] ^= LS[36];
														Columns[4] ^= LS[36];
														MD ^= LS[36];
													}
													Rows[7] ^= LS[56];
													Columns[0] ^= LS[56];
												}
												Rows[4] ^= LS[35];
												Columns[3] ^= LS[35];
												AD ^= LS[35];
											}
											Rows[3] ^= LS[28];
											Columns[4] ^= LS[28];
											AD ^= LS[28];
										}
										Rows[3] ^= LS[27];
										Columns[3] ^= LS[27];
										MD ^= LS[27];
									}
									Rows[5] ^= LS[45];
									Columns[5] ^= LS[45];
									MD ^= LS[45];
								}
								Rows[5] ^= LS[42];
								Columns[2] ^= LS[42];
								AD ^= LS[42];
							}
							Rows[2] ^= LS[21];
							Columns[5] ^= LS[21];
							AD ^= LS[21];
						}
						Rows[2] ^= LS[18];
						Columns[2] ^= LS[18];
						MD ^= LS[18];
					}
					Rows[6] ^= LS[54];
					Columns[6] ^= LS[54];
					MD ^= LS[54];
				}
				Rows[6] ^= LS[49];
				Columns[1] ^= LS[49];
				AD ^= LS[49];
			}
			Rows[1] ^= LS[14];
			Columns[6] ^= LS[14];
			AD ^= LS[14];
		}
		Rows[1] ^= LS[9];
		Columns[1] ^= LS[9];
		MD ^= LS[9];
	}
}
