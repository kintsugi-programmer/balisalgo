#include <iostream>

using namespace std;

int* remainingHeroesHealth(int positions[], int healths[], char Team[], int n) {
    int* remainingHealths = new int[n];
    for (int i = 0; i < n; ++i) {
        remainingHealths[i] = healths[i];
    }

    for (int i = 0; i < n; ++i) {
        int position = positions[i];
        char team = Team[i];
        for (int j = i + 1; j < n; ++j) {
            if (positions[j] == position) {
                if (Team[j] != team) {
                    if (healths[i] < healths[j]) {
                        remainingHealths[i] -= 1;
                    } else if (healths[i] > healths[j]) {
                        remainingHealths[j] -= 1;
                    } else {
                        remainingHealths[i] -= 1;
                        remainingHealths[j] -= 1;
                    }
                }
            }
        }
    }

    int remainingCount = 0;
    for (int i = 0; i < n; ++i) {
        if (remainingHealths[i] > 0) {
            remainingCount++;
        }
    }

    int* remainingHeroes = new int[remainingCount];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (remainingHealths[i] > 0) {
            remainingHeroes[index++] = remainingHealths[i];
        }
    }

    delete[] remainingHealths;

    return remainingHeroes;
}

int main() {
    int positions[] = {1, 2, 5, 6};
    int healths[] = {10, 10, 11, 11};
    char Team[] = "RDRD";
    int n = sizeof(positions) / sizeof(positions[0]);

    int* result = remainingHeroesHealth(positions, healths, Team, n);

    cout << "Output: ";
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;

    return 0;
}
