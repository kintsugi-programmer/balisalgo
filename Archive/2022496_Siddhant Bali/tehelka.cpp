#include <iostream>
#include <vector>

#include <climits>

using namespace std;

class Vertex
{
public:
    int length;
    int breadth;
    int height;
    Vertex(int length, int breadth, int height)
    {
        this->length = length;
        this->breadth = breadth;
         this->height = height;
    }

    bool compare(Vertex *V1)
    {
        return (V1->length > length && V1->breadth > breadth && V1->height > height);
    }
};

// Depth-first search to find a path from source to sink
bool dfs(vector<vector<int>> &residual, vector<int> &parent, int s, int t)
{
    int n = residual.size();
    vector<bool> visited(n, false);
    vector<int> stack;
    stack.push_back(s);
    visited[s] = true;

    while (!stack.empty())
    {
        int u = stack.back();
        stack.pop_back();

        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && residual[u][v] > 0)
            {
                parent[v] = u;
                if (v == t)
                    return true;
                stack.push_back(v);
                visited[v] = true;
            }
        }
    }
    return false;
}

// Ford-Fulkerson algorithm to find maximum flow
int fordFulkerson(vector<vector<int>> &capacity, int s, int t)
{
    int n = capacity.size();
    vector<vector<int>> residual(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            residual[i][j] = capacity[i][j];
    }

    vector<int> parent(n, -1);
    int maxFlow = 0;

    while (dfs(residual, parent, s, t))
    {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }

    return maxFlow;
}

// Function to determine if box i can nest inside box j
bool canNest(Vertex *box1, Vertex *box2)
{
    int dimensions[3] = {box1->length, box1->breadth, box1->height};

    // Loop through all permutations of box1's dimensions
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (i != j && i != k && j != k)
                {
                    // Check if the current permutation fits inside box2
                    if (dimensions[i] < box2->length && dimensions[j] < box2->height && dimensions[k] < box2->breadth)
                    {
                        return true;
                    }
                }
            }
        }
    }
    // If no permutation fits, return false
    return false;
}
// bool canNest(Vertex *i, Vertex *j) {
//     return (i->width < j->width && i->height < j->height && i->depth < j->depth);
// }
// Main function to minimize the number of visible boxes
int minimizeVisibleBoxes(vector<Vertex *> &boxes)
{
    int n = boxes.size();
    // Constructing the capacity graph
    vector<vector<int>> capacity(2 * n + 2, vector<int>(2 * n + 2, 0));
    int source = 2 * n;
    int sink = 2 * n + 1;

    // Connecting source to boxes and boxes to sink
    for (int i = 0; i < n; ++i)
    {
        capacity[source][i] = 1;
        capacity[i + n][sink] = 1;
    }

    // Connecting boxes based on nesting possibility
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && canNest(boxes[i], boxes[j]))
            {
                capacity[i][j + n] = 1;
            }
        }
    }

    // Find the maximum flow using Ford-Fulkerson algorithm
    int maxFlow = fordFulkerson(capacity, source, sink);

    // Minimum number of visible boxes = total number of boxes - maxFlow
    int minVisibleBoxes = n - maxFlow;
    return minVisibleBoxes;
}

int main()
{
    int n;
    cin >> n;

    vector<Vertex *> boxes;
    for (int i = 0; i < n; ++i)
    {
        int l, b, h;
        cin >> l >> b >> h;
        boxes.push_back(new Vertex(l, b, h));
    }

    int minVisibleBoxes = minimizeVisibleBoxes(boxes);
    cout << minVisibleBoxes << endl;

    for (Vertex *v : boxes)
    {
        delete v;
    }

    return 0;
}
