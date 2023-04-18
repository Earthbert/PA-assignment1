#include <string.h>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const long long mod = 1000000007;

void multiply_2x2_matrix(long long A[2][2], long long B[2][2]) {
	long long a00 = ((A[0][0] * B[0][0]) % mod + (A[0][1] * B[1][0]) % mod) % mod;
	long long a01 = ((A[0][0] * B[0][1]) % mod + (A[0][1] * B[1][1]) % mod) % mod;
	long long a10 = ((A[1][0] * B[0][0]) % mod + (A[1][1] * B[1][0]) % mod) % mod;
	long long a11 = ((A[1][0] * B[0][1]) % mod + (A[1][1] * B[1][1]) % mod) % mod;

	A[0][0] = a00;
	A[0][1] = a01;
	A[1][0] = a10;
	A[1][1] = a11;
}

void power(long long A[2][2], long long n) {
	if (n == 0 || n == 1)
		return;
	long long B[2][2] = { {0, 1}, {1, 1} };

	power(A, n / 2);
	multiply_2x2_matrix(A, A);

	if (n % 2 != 0)
		multiply_2x2_matrix(A, B);
}

long long combinations(long long n) {
	long long A[2][2] = { {0, 1}, {1, 1} };
	if (n == 0)
		return 1;

	power(A, n);
	return A[1][1] % mod;
}

int main() {
	ifstream fin("badgpt.in");
	ofstream fout("badgpt.out");

	char c;
	uint64_t num;
	uint64_t result = 1;
	while (fin >> c >> num) {
		if (c == 'n' || c == 'u') {
			result = (result * combinations(num)) % mod;
		}
	}

	fout << result;
	return 0;
}
