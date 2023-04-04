#include <cstdint>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");

    int n, k;
    uint64_t sum = 0;
    uint64_t max = 0;
    fin >> n >> k;
    vector<uint64_t> cars(n);
    for (int i = 0; i < n; i++) {
        fin >> cars[i];
        sum += cars[i];
        if (cars[i] > max)
            max = cars[i];
    }

    uint64_t result = -1;

    uint64_t low = max;
    uint64_t high = sum;
    uint64_t mid;

    while (low < high) {
        mid = low + ((high - low) / 2);
        int unused_ferrys = k;
        uint64_t current_ferry_load = 0;
        for (int i = 0; i < n; i++) {
            if (unused_ferrys <= 0) {
                low = mid + 1;
                break;
            }
            if ((current_ferry_load + cars[i]) > mid) {
                current_ferry_load = cars[i];
                unused_ferrys--;
            } else {
                current_ferry_load += cars[i];
            }
            if (i == (n - 1)) {
                result = mid;
                high = mid;
                break;
            }
        }
    }

    fout << result;

    return 0;
}
