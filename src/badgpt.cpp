#include <cstdint>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const long long mod = 1000000007;

long long multiply(long long x, long long y) {
	if (y == 0) {
		return 0;
	}

	if (y == 1) {
		return x % mod;
	}

	if (y % 2 == 0) {
		long long tmp = multiply(x, y / 2);
		return (tmp + tmp) % mod;
	} else {
		return (x + multiply(x, y - 1)) % mod;
	}
}

void multiply_2x2_matrix(long long A[2][2], long long B[2][2]) {
	long long a00 = multiply(A[0][0], B[0][0]) + multiply(A[0][1], B[1][0]) % mod;
	long long a01 = multiply(A[0][0], B[0][1]) + multiply(A[0][1], B[1][1]) % mod;
	long long a10 = multiply(A[1][0], B[0][0]) + multiply(A[1][1], B[1][0]) % mod;
	long long a11 = multiply(A[1][0], B[0][1]) + multiply(A[1][1], B[1][1]) % mod;

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

	string enunt;
	fin >> enunt;
	uint64_t result = 1;
	for (size_t i = 0; i < enunt.length();) {
		size_t j;
		if (enunt[i] == 'n' || enunt[i] == 'u') {
			result = multiply(result, combinations(stoll(&enunt[i + 1], &j)));
			i += j + 1;
		} else {
			i++;
			while (enunt[i] >= '0' && enunt[i] <= '9')
				i++;
		}
	}

	fout << result;
	return 0;
}
