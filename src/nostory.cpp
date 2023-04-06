/*
 * Acest schelet citește datele de intrare și scrie răspunsul generat de voi,
 * astfel că e suficient să completați cele două funcții.
 *
 * Scheletul este doar un punct de plecare, îl puteți modifica oricum doriți:
 * puteți schimba parametrii, reordona funcțiile etc.
 */

#include <cstdint>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int a;
    int b;
} vec;

vector<int> ReadVector(istream &is, int size) {
    vector<int> vec(size);
    for (auto &num : vec) {
        is >> num;
    }
    return vec;
}

int64_t SolveTask1(int n, istream &is) {
    int64_t result = 0;
    // Read all both vectors in one
    vector<int> v_max = ReadVector(is, 2 * n);
    sort(v_max.begin(), v_max.end());
    // Get all n largest value from both vectors
    for (int i = n; i < 2 * n; i++) {
        result += v_max[i];
    }
    return result;
}

int64_t SolveTask2(int n, istream &is) {
    int64_t result = 0;
    int moves;

    is >> moves;
    // Create vector to store to store both elements from both
    // vectors values on the same element
    vector<vec> v_max(n);

    // Read vectors
    for (int i = 0; i < n; i++) {
        is >> v_max[i].a;
    }

    for (int i = 0; i < n; i++) {
        is >> v_max[i].b;
    }

    // Copy vector
    vector<vec> v_min(v_max);
    // Sort first vector by bigger value
    sort(v_max.begin(), v_max.end(),
        [](vec e1, vec e2) {return (max(e1.a, e1.b) > max(e2.a, e2.b));});
    // Sort copy vector by bigger value
    sort(v_min.begin(), v_min.end(),
        [](vec e1, vec e2) {return (min(e1.a, e1.b) < min(e2.a, e2.b));});

    int i;
    for (i = 0; i < n; i++) {
        // Check if it is advantegous to stop selecting element from v_max
        if ((i > (n - moves - 1)) && min(v_min[i].a, v_min[i].b) >=
            max(v_max[i].a, v_max[i].b))
            break;
        result += max(v_max[i].a, v_max[i].b);
    }

    for (int j = i; j < n; j++) {
        result += min(v_min[j].a, v_min[j].b);
    }
    return result;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task, n;
    fin >> task >> n;

    auto res = task == 1 ? SolveTask1(n, fin) : SolveTask2(n, fin);
    fout << res << "\n";

    return 0;
}
