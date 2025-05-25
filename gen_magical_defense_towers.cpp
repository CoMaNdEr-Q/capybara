#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // Number of towers from command line (or default to 1000)
    int N = argc > 1 ? atoi(argv[1]) : 1000;

    println(N);

    // To ensure unique positions
    set<int> used_positions;

    for (int i = 0; i < N; ++i) {
        int pos;
        // Ensure positions are unique for realism
        do {
            pos = rnd.next(1, (int)1e9);
        } while (!used_positions.insert(pos).second);

        int power = rnd.next(1, (int)1e6);
        int range = rnd.next(1, (int)1e6);

        println(pos, power, range);
    }

    return 0;
}