int capacity[MAX_BOXES][MAX_BOXES] = {0};
int source = 0, sink = 2 * n + 1;
for (int i = 1; i <= n; i++) {
    capacity[source][i] = 1; // Connect source to each box
    capacity[i][i + n] = 1; // Connect each box to its own sink
    for (int j = 1; j <= n; j++) {
        if (i != j && canBeNested(boxes[i - 1], boxes[j - 1])) {
            capacity[i + n][j] = 1; // Connect box i's sink to box j
        }
    }
}