#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

// Define maximum number of boxes
#define MAX_BOXES 100

// Define minimum and maximum side lengths for a box
#define MIN_SIDE_LENGTH 10
#define MAX_SIDE_LENGTH 20

// Define structure for a box
struct Box {
    int height;
    int width;
    int depth;
};

// Function to check if box A can be nested inside box B
bool canBeNested(struct Box A, struct Box B) {
    return (A.height < B.height && A.width < B.width && A.depth < B.depth);
}

// Function to validate the dimensions of a box
bool isValidDimensions(struct Box box) {
    return (box.height > MIN_SIDE_LENGTH && box.height < MAX_SIDE_LENGTH &&
            box.width > MIN_SIDE_LENGTH && box.width < MAX_SIDE_LENGTH &&
            box.depth > MIN_SIDE_LENGTH && box.depth < MAX_SIDE_LENGTH);
}

// Function to find maximum flow using Ford-Fulkerson algorithm
int fordFulkerson(int capacity[MAX_BOXES][MAX_BOXES], int source, int sink, int n) {
    int maxFlow = 0;
    int parent[MAX_BOXES];
    while (1) {
        memset(parent, -1, sizeof(parent));
        parent[source] = source;
        
        // Implement BFS to find augmenting path
        int queue[MAX_BOXES];
        int front = 0, rear = 0;
        queue[rear++] = source;
        while (front < rear && parent[sink] == -1) {
            int u = queue[front++];
            for (int v = 0; v < n; v++) {
                if (parent[v] == -1 && capacity[u][v] > 0) {
                    parent[v] = u;
                    queue[rear++] = v;
                }
            }
        }
        if (parent[sink] == -1)
            break; // No more augmenting paths
        
        // Find bottleneck capacity
        int bottleneck = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            if (capacity[u][v] < bottleneck)
                bottleneck = capacity[u][v];
        }
        
        // Update capacities and flow
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= bottleneck;
            capacity[v][u] += bottleneck;
        }
        maxFlow += bottleneck;
    }
    return maxFlow;
}

// Main function
int main() {
    // Read input: number of boxes and their dimensions
    int n;
    printf("Enter the number of boxes: ");
    scanf("%d", &n);
    
    struct Box boxes[MAX_BOXES];
    printf("Enter the dimensions of each box (height, width, depth):\n");
    for (int i = 0; i < n; i++) {
        printf("Box %d: ", i + 1);
        scanf("%d %d %d", &boxes[i].height, &boxes[i].width, &boxes[i].depth);
        
        // Validate dimensions
        if (!isValidDimensions(boxes[i])) {
            printf("Invalid dimensions. Side lengths must be strictly between 10 and 20 cm.\n");
            return 1;
        }
    }

    // Construct the flow network
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

    // Find the maximum flow using Ford-Fulkerson algorithm
    int maxFlow = fordFulkerson(capacity, source, sink, 2 * n + 2);

    // The minimum number of visible boxes is the total number of boxes minus the maximum flow
    int minVisibleBoxes = n - maxFlow;
    printf("Minimum number of visible boxes: %d\n", minVisibleBoxes);

    return 0;
}
