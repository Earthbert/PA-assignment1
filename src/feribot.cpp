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

    // Binary Search in possible max weight of the ferrys
    while (low < high) {
        mid = low + ((high - low) / 2);
        int unused_ferrys = k;
        uint64_t current_ferry_load = 0;
        for (int i = 0; i < n; i++) {
            if ((current_ferry_load + cars[i]) > mid) {
                // We cannot fit anymore cars with current constrain
                // on current ferry
                unused_ferrys--;
                if (unused_ferrys == 0) {
                    // This weight is too small
                    low = mid + 1;
                    break;
                }
                current_ferry_load = cars[i];
            } else {
                // We can fit car in current ferry
                current_ferry_load += cars[i];
            }

            if (i == (n - 1)) {
                // Found a possible solution
                // Search for a better one
                result = mid;
                high = mid;
            }
        }
    }

    fout << result;

    return 0;
}
