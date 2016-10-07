 #include <iostream>
 #include <chrono>
 static inline double cpuTime(void) { return (double)clock() / CLOCKS_PER_SEC; }
using namespace std;
const int N=9;
const uint32_t maxN=1<<N;
const uint32_t AllN= 511;
uint32_t LS[N*N];
uint32_t CR[N*N];
uint32_t L[N*N];
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
	LS[i]=0;
for (int i = 0; i < N; i++)
	LS[i]=1<<i;
for (int i = 0; i < N; i++)
	 Columns[i]=0;
for (int i = 0; i < N; i++)
	 Rows[i]=0;
MD=0;
AD=0;
for (int j=0;j<N;j++){
	LS[j] = 1<<j;
			Rows[0]|=LS[j];
	Columns[j]|= LS[j];
}
MD|=LS[0];
AD|=LS[N-1];
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
	StartProf();
CR[40] = Rows[4] | Columns[4]| MD | AD;
L[40] = (CR[40]^AllN)&(-(CR[40]^AllN));
for (LS[40] = L[40]; ((L[40]>0)&&(LS[40]< maxN)); LS[40]= LS[40] << 1) {
	 if ((CR[40] & LS[40])!=0)
		continue;

Rows[4] |= LS[40];
Columns[4] |= LS[40];
MD |= LS[40];
AD |=LS[40];
CR[10] = Rows[1] | Columns[1]| MD ;
L[10] = (CR[10]^AllN)&(-(CR[10]^AllN));
for (LS[10] = L[10]; ((L[10]>0)&&(LS[10]< maxN)); LS[10]= LS[10] << 1) {
	 if ((CR[10] & LS[10])!=0)
		continue;

Rows[1] |= LS[10];
Columns[1] |= LS[10];
MD |= LS[10];
CR[16] = Rows[1] | Columns[7]| AD;
L[16] = (CR[16]^AllN)&(-(CR[16]^AllN));
for (LS[16] = L[16]; ((L[16]>0)&&(LS[16]< maxN)); LS[16]= LS[16] << 1) {
	 if ((CR[16] & LS[16])!=0)
		continue;

Rows[1] |= LS[16];
Columns[7] |= LS[16];
AD |=LS[16];
CR[64] = Rows[7] | Columns[1]| AD;
L[64] = (CR[64]^AllN)&(-(CR[64]^AllN));
for (LS[64] = L[64]; ((L[64]>0)&&(LS[64]< maxN)); LS[64]= LS[64] << 1) {
	 if ((CR[64] & LS[64])!=0)
		continue;

Rows[7] |= LS[64];
Columns[1] |= LS[64];
AD |=LS[64];
CR[70] = Rows[7] | Columns[7]| MD ;
L[70] = (CR[70]^AllN)&(-(CR[70]^AllN));
for (LS[70] = L[70]; ((L[70]>0)&&(LS[70]< maxN)); LS[70]= LS[70] << 1) {
	 if ((CR[70] & LS[70])!=0)
		continue;

Rows[7] |= LS[70];
Columns[7] |= LS[70];
MD |= LS[70];
CR[20] = Rows[2] | Columns[2]| MD ;
L[20] = (CR[20]^AllN)&(-(CR[20]^AllN));
for (LS[20] = L[20]; ((L[20]>0)&&(LS[20]< maxN)); LS[20]= LS[20] << 1) {
	 if ((CR[20] & LS[20])!=0)
		continue;

Rows[2] |= LS[20];
Columns[2] |= LS[20];
MD |= LS[20];
CR[24] = Rows[2] | Columns[6]| AD;
L[24] = (CR[24]^AllN)&(-(CR[24]^AllN));
for (LS[24] = L[24]; ((L[24]>0)&&(LS[24]< maxN)); LS[24]= LS[24] << 1) {
	 if ((CR[24] & LS[24])!=0)
		continue;

Rows[2] |= LS[24];
Columns[6] |= LS[24];
AD |=LS[24];
CR[56] = Rows[6] | Columns[2]| AD;
L[56] = (CR[56]^AllN)&(-(CR[56]^AllN));
for (LS[56] = L[56]; ((L[56]>0)&&(LS[56]< maxN)); LS[56]= LS[56] << 1) {
	 if ((CR[56] & LS[56])!=0)
		continue;

Rows[6] |= LS[56];
Columns[2] |= LS[56];
AD |=LS[56];
CR[60] = Rows[6] | Columns[6]| MD ;
L[60] = (CR[60]^AllN)&(-(CR[60]^AllN));
for (LS[60] = L[60]; ((L[60]>0)&&(LS[60]< maxN)); LS[60]= LS[60] << 1) {
	 if ((CR[60] & LS[60])!=0)
		continue;

Rows[6] |= LS[60];
Columns[6] |= LS[60];
MD |= LS[60];
CR[30] = Rows[3] | Columns[3]| MD ;
L[30] = (CR[30]^AllN)&(-(CR[30]^AllN));
for (LS[30] = L[30]; ((L[30]>0)&&(LS[30]< maxN)); LS[30]= LS[30] << 1) {
	 if ((CR[30] & LS[30])!=0)
		continue;

Rows[3] |= LS[30];
Columns[3] |= LS[30];
MD |= LS[30];
CR[32] = Rows[3] | Columns[5]| AD;
L[32] = (CR[32]^AllN)&(-(CR[32]^AllN));
for (LS[32] = L[32]; ((L[32]>0)&&(LS[32]< maxN)); LS[32]= LS[32] << 1) {
	 if ((CR[32] & LS[32])!=0)
		continue;

Rows[3] |= LS[32];
Columns[5] |= LS[32];
AD |=LS[32];
CR[48] = Rows[5] | Columns[3]| AD;
L[48] = (CR[48]^AllN)&(-(CR[48]^AllN));
for (LS[48] = L[48]; ((L[48]>0)&&(LS[48]< maxN)); LS[48]= LS[48] << 1) {
	 if ((CR[48] & LS[48])!=0)
		continue;

Rows[5] |= LS[48];
Columns[3] |= LS[48];
AD |=LS[48];
CR[72] = Rows[8] | Columns[0]| AD;
L[72] = CR[72] ^ AllN;
if ((L[72] != 0)  ) {
LS[72] = L[72];
Rows[8] |= LS[72];
Columns[0] |= LS[72];
AD |=LS[72];
CR[50] = Rows[5] | Columns[5]| MD ;
L[50] = (CR[50]^AllN)&(-(CR[50]^AllN));
for (LS[50] = L[50]; ((L[50]>0)&&(LS[50]< maxN)); LS[50]= LS[50] << 1) {
	 if ((CR[50] & LS[50])!=0)
		continue;

Rows[5] |= LS[50];
Columns[5] |= LS[50];
MD |= LS[50];
CR[80] = Rows[8] | Columns[8]| MD ;
L[80] = CR[80] ^ AllN;
if ((L[80] != 0)  ) {
LS[80] = L[80];
Rows[8] |= LS[80];
Columns[8] |= LS[80];
MD |= LS[80];
CR[11] = Rows[1] | Columns[2];
L[11] = (CR[11]^AllN)&(-(CR[11]^AllN));
for (LS[11] = L[11]; ((L[11]>0)&&(LS[11]< maxN)); LS[11]= LS[11] << 1) {
	 if ((CR[11] & LS[11])!=0)
		continue;

Rows[1] |= LS[11];
Columns[2] |= LS[11];
CR[12] = Rows[1] | Columns[3];
L[12] = (CR[12]^AllN)&(-(CR[12]^AllN));
for (LS[12] = L[12]; ((L[12]>0)&&(LS[12]< maxN)); LS[12]= LS[12] << 1) {
	 if ((CR[12] & LS[12])!=0)
		continue;

Rows[1] |= LS[12];
Columns[3] |= LS[12];
CR[14] = Rows[1] | Columns[5];
L[14] = (CR[14]^AllN)&(-(CR[14]^AllN));
for (LS[14] = L[14]; ((L[14]>0)&&(LS[14]< maxN)); LS[14]= LS[14] << 1) {
	 if ((CR[14] & LS[14])!=0)
		continue;

Rows[1] |= LS[14];
Columns[5] |= LS[14];
CR[15] = Rows[1] | Columns[6];
L[15] = (CR[15]^AllN)&(-(CR[15]^AllN));
for (LS[15] = L[15]; ((L[15]>0)&&(LS[15]< maxN)); LS[15]= LS[15] << 1) {
	 if ((CR[15] & LS[15])!=0)
		continue;

Rows[1] |= LS[15];
Columns[6] |= LS[15];
CR[9] = Rows[1] | Columns[0];
L[9] = (CR[9]^AllN)&(-(CR[9]^AllN));
for (LS[9] = L[9]; ((L[9]>0)&&(LS[9]< maxN)); LS[9]= LS[9] << 1) {
	 if ((CR[9] & LS[9])!=0)
		continue;

Rows[1] |= LS[9];
Columns[0] |= LS[9];
CR[13] = Rows[1] | Columns[4];
L[13] = (CR[13]^AllN)&(-(CR[13]^AllN));
for (LS[13] = L[13]; ((L[13]>0)&&(LS[13]< maxN)); LS[13]= LS[13] << 1) {
	 if ((CR[13] & LS[13])!=0)
		continue;

Rows[1] |= LS[13];
Columns[4] |= LS[13];
CR[17] = Rows[1] | Columns[8];
L[17] = CR[17] ^ AllN;
if ((L[17] != 0)  ) {
LS[17] = L[17];
Rows[1] |= LS[17];
Columns[8] |= LS[17];
CR[21] = Rows[2] | Columns[3];
L[21] = (CR[21]^AllN)&(-(CR[21]^AllN));
for (LS[21] = L[21]; ((L[21]>0)&&(LS[21]< maxN)); LS[21]= LS[21] << 1) {
	 if ((CR[21] & LS[21])!=0)
		continue;

Rows[2] |= LS[21];
Columns[3] |= LS[21];
CR[23] = Rows[2] | Columns[5];
L[23] = (CR[23]^AllN)&(-(CR[23]^AllN));
for (LS[23] = L[23]; ((L[23]>0)&&(LS[23]< maxN)); LS[23]= LS[23] << 1) {
	 if ((CR[23] & LS[23])!=0)
		continue;

Rows[2] |= LS[23];
Columns[5] |= LS[23];
CR[18] = Rows[2] | Columns[0];
L[18] = (CR[18]^AllN)&(-(CR[18]^AllN));
for (LS[18] = L[18]; ((L[18]>0)&&(LS[18]< maxN)); LS[18]= LS[18] << 1) {
	 if ((CR[18] & LS[18])!=0)
		continue;

Rows[2] |= LS[18];
Columns[0] |= LS[18];
CR[19] = Rows[2] | Columns[1];
L[19] = (CR[19]^AllN)&(-(CR[19]^AllN));
for (LS[19] = L[19]; ((L[19]>0)&&(LS[19]< maxN)); LS[19]= LS[19] << 1) {
	 if ((CR[19] & LS[19])!=0)
		continue;

Rows[2] |= LS[19];
Columns[1] |= LS[19];
CR[22] = Rows[2] | Columns[4];
L[22] = (CR[22]^AllN)&(-(CR[22]^AllN));
for (LS[22] = L[22]; ((L[22]>0)&&(LS[22]< maxN)); LS[22]= LS[22] << 1) {
	 if ((CR[22] & LS[22])!=0)
		continue;

Rows[2] |= LS[22];
Columns[4] |= LS[22];
CR[25] = Rows[2] | Columns[7];
L[25] = (CR[25]^AllN)&(-(CR[25]^AllN));
for (LS[25] = L[25]; ((L[25]>0)&&(LS[25]< maxN)); LS[25]= LS[25] << 1) {
	 if ((CR[25] & LS[25])!=0)
		continue;

Rows[2] |= LS[25];
Columns[7] |= LS[25];
CR[26] = Rows[2] | Columns[8];
L[26] = CR[26] ^ AllN;
if ((L[26] != 0)  ) {
LS[26] = L[26];
Rows[2] |= LS[26];
Columns[8] |= LS[26];
CR[57] = Rows[6] | Columns[3];
L[57] = (CR[57]^AllN)&(-(CR[57]^AllN));
for (LS[57] = L[57]; ((L[57]>0)&&(LS[57]< maxN)); LS[57]= LS[57] << 1) {
	 if ((CR[57] & LS[57])!=0)
		continue;

Rows[6] |= LS[57];
Columns[3] |= LS[57];
CR[59] = Rows[6] | Columns[5];
L[59] = (CR[59]^AllN)&(-(CR[59]^AllN));
for (LS[59] = L[59]; ((L[59]>0)&&(LS[59]< maxN)); LS[59]= LS[59] << 1) {
	 if ((CR[59] & LS[59])!=0)
		continue;

Rows[6] |= LS[59];
Columns[5] |= LS[59];
CR[54] = Rows[6] | Columns[0];
L[54] = (CR[54]^AllN)&(-(CR[54]^AllN));
for (LS[54] = L[54]; ((L[54]>0)&&(LS[54]< maxN)); LS[54]= LS[54] << 1) {
	 if ((CR[54] & LS[54])!=0)
		continue;

Rows[6] |= LS[54];
Columns[0] |= LS[54];
CR[55] = Rows[6] | Columns[1];
L[55] = (CR[55]^AllN)&(-(CR[55]^AllN));
for (LS[55] = L[55]; ((L[55]>0)&&(LS[55]< maxN)); LS[55]= LS[55] << 1) {
	 if ((CR[55] & LS[55])!=0)
		continue;

Rows[6] |= LS[55];
Columns[1] |= LS[55];
CR[58] = Rows[6] | Columns[4];
L[58] = (CR[58]^AllN)&(-(CR[58]^AllN));
for (LS[58] = L[58]; ((L[58]>0)&&(LS[58]< maxN)); LS[58]= LS[58] << 1) {
	 if ((CR[58] & LS[58])!=0)
		continue;

Rows[6] |= LS[58];
Columns[4] |= LS[58];
CR[61] = Rows[6] | Columns[7];
L[61] = (CR[61]^AllN)&(-(CR[61]^AllN));
for (LS[61] = L[61]; ((L[61]>0)&&(LS[61]< maxN)); LS[61]= LS[61] << 1) {
	 if ((CR[61] & LS[61])!=0)
		continue;

Rows[6] |= LS[61];
Columns[7] |= LS[61];
CR[62] = Rows[6] | Columns[8];
L[62] = CR[62] ^ AllN;
if ((L[62] != 0)  ) {
LS[62] = L[62];
Rows[6] |= LS[62];
Columns[8] |= LS[62];
CR[66] = Rows[7] | Columns[3];
L[66] = (CR[66]^AllN)&(-(CR[66]^AllN));
for (LS[66] = L[66]; ((L[66]>0)&&(LS[66]< maxN)); LS[66]= LS[66] << 1) {
	 if ((CR[66] & LS[66])!=0)
		continue;

Rows[7] |= LS[66];
Columns[3] |= LS[66];
CR[68] = Rows[7] | Columns[5];
L[68] = (CR[68]^AllN)&(-(CR[68]^AllN));
for (LS[68] = L[68]; ((L[68]>0)&&(LS[68]< maxN)); LS[68]= LS[68] << 1) {
	 if ((CR[68] & LS[68])!=0)
		continue;

Rows[7] |= LS[68];
Columns[5] |= LS[68];
CR[63] = Rows[7] | Columns[0];
L[63] = (CR[63]^AllN)&(-(CR[63]^AllN));
for (LS[63] = L[63]; ((L[63]>0)&&(LS[63]< maxN)); LS[63]= LS[63] << 1) {
	 if ((CR[63] & LS[63])!=0)
		continue;

Rows[7] |= LS[63];
Columns[0] |= LS[63];
CR[67] = Rows[7] | Columns[4];
L[67] = (CR[67]^AllN)&(-(CR[67]^AllN));
for (LS[67] = L[67]; ((L[67]>0)&&(LS[67]< maxN)); LS[67]= LS[67] << 1) {
	 if ((CR[67] & LS[67])!=0)
		continue;

Rows[7] |= LS[67];
Columns[4] |= LS[67];
CR[71] = Rows[7] | Columns[8];
L[71] = (CR[71]^AllN)&(-(CR[71]^AllN));
for (LS[71] = L[71]; ((L[71]>0)&&(LS[71]< maxN)); LS[71]= LS[71] << 1) {
	 if ((CR[71] & LS[71])!=0)
		continue;

Rows[7] |= LS[71];
Columns[8] |= LS[71];
CR[65] = Rows[7] | Columns[2];
L[65] = (CR[65]^AllN)&(-(CR[65]^AllN));
for (LS[65] = L[65]; ((L[65]>0)&&(LS[65]< maxN)); LS[65]= LS[65] << 1) {
	 if ((CR[65] & LS[65])!=0)
		continue;

Rows[7] |= LS[65];
Columns[2] |= LS[65];
CR[69] = Rows[7] | Columns[6];
L[69] = CR[69] ^ AllN;
if ((L[69] != 0)  ) {
LS[69] = L[69];
Rows[7] |= LS[69];
Columns[6] |= LS[69];
CR[75] = Rows[8] | Columns[3];
L[75] = (CR[75]^AllN)&(-(CR[75]^AllN));
for (LS[75] = L[75]; ((L[75]>0)&&(LS[75]< maxN)); LS[75]= LS[75] << 1) {
	 if ((CR[75] & LS[75])!=0)
		continue;

Rows[8] |= LS[75];
Columns[3] |= LS[75];
CR[39] = Rows[4] | Columns[3];
L[39] = CR[39] ^ AllN;
if ((L[39] != 0)  ) {
LS[39] = L[39];
Rows[4] |= LS[39];
Columns[3] |= LS[39];
CR[77] = Rows[8] | Columns[5];
L[77] = (CR[77]^AllN)&(-(CR[77]^AllN));
for (LS[77] = L[77]; ((L[77]>0)&&(LS[77]< maxN)); LS[77]= LS[77] << 1) {
	 if ((CR[77] & LS[77])!=0)
		continue;

Rows[8] |= LS[77];
Columns[5] |= LS[77];
CR[41] = Rows[4] | Columns[5];
L[41] = CR[41] ^ AllN;
if ((L[41] != 0)  ) {
LS[41] = L[41];
Rows[4] |= LS[41];
Columns[5] |= LS[41];
CR[76] = Rows[8] | Columns[4];
L[76] = (CR[76]^AllN)&(-(CR[76]^AllN));
for (LS[76] = L[76]; ((L[76]>0)&&(LS[76]< maxN)); LS[76]= LS[76] << 1) {
	 if ((CR[76] & LS[76])!=0)
		continue;

Rows[8] |= LS[76];
Columns[4] |= LS[76];
CR[73] = Rows[8] | Columns[1];
L[73] = (CR[73]^AllN)&(-(CR[73]^AllN));
for (LS[73] = L[73]; ((L[73]>0)&&(LS[73]< maxN)); LS[73]= LS[73] << 1) {
	 if ((CR[73] & LS[73])!=0)
		continue;

Rows[8] |= LS[73];
Columns[1] |= LS[73];
CR[74] = Rows[8] | Columns[2];
L[74] = (CR[74]^AllN)&(-(CR[74]^AllN));
for (LS[74] = L[74]; ((L[74]>0)&&(LS[74]< maxN)); LS[74]= LS[74] << 1) {
	 if ((CR[74] & LS[74])!=0)
		continue;

Rows[8] |= LS[74];
Columns[2] |= LS[74];
CR[78] = Rows[8] | Columns[6];
L[78] = (CR[78]^AllN)&(-(CR[78]^AllN));
for (LS[78] = L[78]; ((L[78]>0)&&(LS[78]< maxN)); LS[78]= LS[78] << 1) {
	 if ((CR[78] & LS[78])!=0)
		continue;

Rows[8] |= LS[78];
Columns[6] |= LS[78];
CR[79] = Rows[8] | Columns[7];
L[79] = CR[79] ^ AllN;
if ((L[79] != 0)  ) {
LS[79] = L[79];
Rows[8] |= LS[79];
Columns[7] |= LS[79];
CR[31] = Rows[3] | Columns[4];
L[31] = (CR[31]^AllN)&(-(CR[31]^AllN));
for (LS[31] = L[31]; ((L[31]>0)&&(LS[31]< maxN)); LS[31]= LS[31] << 1) {
	 if ((CR[31] & LS[31])!=0)
		continue;

Rows[3] |= LS[31];
Columns[4] |= LS[31];
CR[49] = Rows[5] | Columns[4];
L[49] = CR[49] ^ AllN;
if ((L[49] != 0)  ) {
LS[49] = L[49];
Rows[5] |= LS[49];
Columns[4] |= LS[49];
CR[27] = Rows[3] | Columns[0];
L[27] = (CR[27]^AllN)&(-(CR[27]^AllN));
for (LS[27] = L[27]; ((L[27]>0)&&(LS[27]< maxN)); LS[27]= LS[27] << 1) {
	 if ((CR[27] & LS[27])!=0)
		continue;

Rows[3] |= LS[27];
Columns[0] |= LS[27];
CR[28] = Rows[3] | Columns[1];
L[28] = (CR[28]^AllN)&(-(CR[28]^AllN));
for (LS[28] = L[28]; ((L[28]>0)&&(LS[28]< maxN)); LS[28]= LS[28] << 1) {
	 if ((CR[28] & LS[28])!=0)
		continue;

Rows[3] |= LS[28];
Columns[1] |= LS[28];
CR[29] = Rows[3] | Columns[2];
L[29] = (CR[29]^AllN)&(-(CR[29]^AllN));
for (LS[29] = L[29]; ((L[29]>0)&&(LS[29]< maxN)); LS[29]= LS[29] << 1) {
	 if ((CR[29] & LS[29])!=0)
		continue;

Rows[3] |= LS[29];
Columns[2] |= LS[29];
CR[33] = Rows[3] | Columns[6];
L[33] = (CR[33]^AllN)&(-(CR[33]^AllN));
for (LS[33] = L[33]; ((L[33]>0)&&(LS[33]< maxN)); LS[33]= LS[33] << 1) {
	 if ((CR[33] & LS[33])!=0)
		continue;

Rows[3] |= LS[33];
Columns[6] |= LS[33];
CR[34] = Rows[3] | Columns[7];
L[34] = (CR[34]^AllN)&(-(CR[34]^AllN));
for (LS[34] = L[34]; ((L[34]>0)&&(LS[34]< maxN)); LS[34]= LS[34] << 1) {
	 if ((CR[34] & LS[34])!=0)
		continue;

Rows[3] |= LS[34];
Columns[7] |= LS[34];
CR[35] = Rows[3] | Columns[8];
L[35] = CR[35] ^ AllN;
if ((L[35] != 0)  ) {
LS[35] = L[35];
Rows[3] |= LS[35];
Columns[8] |= LS[35];
CR[36] = Rows[4] | Columns[0];
L[36] = (CR[36]^AllN)&(-(CR[36]^AllN));
for (LS[36] = L[36]; ((L[36]>0)&&(LS[36]< maxN)); LS[36]= LS[36] << 1) {
	 if ((CR[36] & LS[36])!=0)
		continue;

Rows[4] |= LS[36];
Columns[0] |= LS[36];
CR[45] = Rows[5] | Columns[0];
L[45] = CR[45] ^ AllN;
if ((L[45] != 0)  ) {
LS[45] = L[45];
Rows[5] |= LS[45];
Columns[0] |= LS[45];
CR[37] = Rows[4] | Columns[1];
L[37] = (CR[37]^AllN)&(-(CR[37]^AllN));
for (LS[37] = L[37]; ((L[37]>0)&&(LS[37]< maxN)); LS[37]= LS[37] << 1) {
	 if ((CR[37] & LS[37])!=0)
		continue;

Rows[4] |= LS[37];
Columns[1] |= LS[37];
CR[46] = Rows[5] | Columns[1];
L[46] = CR[46] ^ AllN;
if ((L[46] != 0)  ) {
LS[46] = L[46];
Rows[5] |= LS[46];
Columns[1] |= LS[46];
CR[38] = Rows[4] | Columns[2];
L[38] = (CR[38]^AllN)&(-(CR[38]^AllN));
for (LS[38] = L[38]; ((L[38]>0)&&(LS[38]< maxN)); LS[38]= LS[38] << 1) {
	 if ((CR[38] & LS[38])!=0)
		continue;

Rows[4] |= LS[38];
Columns[2] |= LS[38];
CR[47] = Rows[5] | Columns[2];
L[47] = CR[47] ^ AllN;
if ((L[47] != 0)  ) {
LS[47] = L[47];
Rows[5] |= LS[47];
Columns[2] |= LS[47];
CR[42] = Rows[4] | Columns[6];
L[42] = (CR[42]^AllN)&(-(CR[42]^AllN));
for (LS[42] = L[42]; ((L[42]>0)&&(LS[42]< maxN)); LS[42]= LS[42] << 1) {
	 if ((CR[42] & LS[42])!=0)
		continue;

Rows[4] |= LS[42];
Columns[6] |= LS[42];
CR[51] = Rows[5] | Columns[6];
L[51] = CR[51] ^ AllN;
if ((L[51] != 0)  ) {
LS[51] = L[51];
Rows[5] |= LS[51];
Columns[6] |= LS[51];
CR[43] = Rows[4] | Columns[7];
L[43] = (CR[43]^AllN)&(-(CR[43]^AllN));
for (LS[43] = L[43]; ((L[43]>0)&&(LS[43]< maxN)); LS[43]= LS[43] << 1) {
	 if ((CR[43] & LS[43])!=0)
		continue;

Rows[4] |= LS[43];
Columns[7] |= LS[43];
CR[44] = Rows[4] | Columns[8];
L[44] = CR[44] ^ AllN;
CR[52] = Rows[5] | Columns[7];
L[52] = CR[52] ^ AllN;
if ((L[44] != 0)  && (L[52] != 0)  ) {
LS[44] = L[44];
Rows[4] |= LS[44];
Columns[8] |= LS[44];
LS[52] = L[52];
Rows[5] |= LS[52];
Columns[7] |= LS[52];
CR[53] = Rows[5] | Columns[8];
L[53] = (CR[53]^AllN)&(-(CR[53]^AllN));
for (LS[53] = L[53]; ((L[53]>0)&&(LS[53]< maxN)); LS[53]= LS[53] << 1) {
	 if ((CR[53] & LS[53])!=0)
		continue;

Rows[5] |= LS[53];
Columns[8] |= LS[53];
SquaresCnt++;
 	 if (SquaresCnt % 1000000 == 0) {
			StopProf();
	cout << "Squares found: " << SquaresCnt << endl;
		cout << "Average time: " << 1.0*ProfResult() / ProcFreq / SquaresCnt * 1000 << " ms per square" << endl;
		cout << "Squares per second: " << 1.0 / (1.0 * ProfResult() / ProcFreq / SquaresCnt) << endl << endl;
}
Rows[5] ^= LS[53];
Columns[8] ^= LS[53];
}
Rows[4] ^= LS[44];
Columns[8] ^= LS[44];
Rows[5] ^= LS[52];
Columns[7] ^= LS[52];
}
Rows[4] ^= LS[43];
Columns[7] ^= LS[43];
}
Rows[5] ^= LS[51];
Columns[6] ^= LS[51];
}
Rows[4] ^= LS[42];
Columns[6] ^= LS[42];
}
Rows[5] ^= LS[47];
Columns[2] ^= LS[47];
}
Rows[4] ^= LS[38];
Columns[2] ^= LS[38];
}
Rows[5] ^= LS[46];
Columns[1] ^= LS[46];
}
Rows[4] ^= LS[37];
Columns[1] ^= LS[37];
}
Rows[5] ^= LS[45];
Columns[0] ^= LS[45];
}
Rows[4] ^= LS[36];
Columns[0] ^= LS[36];
}
Rows[3] ^= LS[35];
Columns[8] ^= LS[35];
}
Rows[3] ^= LS[34];
Columns[7] ^= LS[34];
}
Rows[3] ^= LS[33];
Columns[6] ^= LS[33];
}
Rows[3] ^= LS[29];
Columns[2] ^= LS[29];
}
Rows[3] ^= LS[28];
Columns[1] ^= LS[28];
}
Rows[3] ^= LS[27];
Columns[0] ^= LS[27];
}
Rows[5] ^= LS[49];
Columns[4] ^= LS[49];
}
Rows[3] ^= LS[31];
Columns[4] ^= LS[31];
}
Rows[8] ^= LS[79];
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
Columns[5] ^= LS[41];
}
Rows[8] ^= LS[77];
Columns[5] ^= LS[77];
}
Rows[4] ^= LS[39];
Columns[3] ^= LS[39];
}
Rows[8] ^= LS[75];
Columns[3] ^= LS[75];
}
Rows[7] ^= LS[69];
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
Rows[6] ^= LS[62];
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
Rows[2] ^= LS[26];
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
Rows[1] ^= LS[17];
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
MD ^= LS[80];
}
Rows[5] ^= LS[50];
Columns[5] ^= LS[50];
MD ^= LS[50];
}
Rows[8] ^= LS[72];
Columns[0] ^= LS[72];
AD ^=LS[72];
}
Rows[5] ^= LS[48];
Columns[3] ^= LS[48];
AD ^=LS[48];
}
Rows[3] ^= LS[32];
Columns[5] ^= LS[32];
AD ^=LS[32];
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
AD ^=LS[56];
}
Rows[2] ^= LS[24];
Columns[6] ^= LS[24];
AD ^=LS[24];
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
AD ^=LS[64];
}
Rows[1] ^= LS[16];
Columns[7] ^= LS[16];
AD ^=LS[16];
}
Rows[1] ^= LS[10];
Columns[1] ^= LS[10];
MD ^= LS[10];
}
Rows[4] ^= LS[40];
Columns[4] ^= LS[40];
MD ^= LS[40];
AD ^=LS[40];
}
}
