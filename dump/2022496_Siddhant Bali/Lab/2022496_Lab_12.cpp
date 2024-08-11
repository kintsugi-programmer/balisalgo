#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// QUeue implementation for bfs 
struct que {
    int front, rear;
    unsigned capacity;
    int* array;
};

struct que* create_que(unsigned capacity) {
    struct que* que = (struct que*)malloc(sizeof(struct que));
    que->capacity = capacity;
    que->front = que->rear = -1;
    que->array = (int*)malloc(que->capacity * sizeof(int));
    return que;
}

bool is_empty(struct que* que) {
    return que->front == -1;
}

bool is_full(struct que* que) {
    return (que->rear + 1) % que->capacity == que->front;
}

void enque(struct que* que, int item) {
    if (is_full(que)) return;
    que->rear = (que->rear + 1) % que->capacity;
    que->array[que->rear] = item;
    if (que->front == -1) que->front = que->rear;
}

int deque(struct que* que) {
    if (is_empty(que)) return -1;
    int item = que->array[que->front];
    if (que->front == que->rear) que->front = que->rear = -1;
    else que->front = (que->front + 1) % que->capacity;
    return item;
}

// Adj list
struct node {
    int dest;
    struct node* nxt;
};

struct List {
    struct node* head;
};

struct gph {
    int v;
    bool directed;
    struct List** array; //list afdg
    bool** adj_mtx; //matrix adg
};

//node
struct node* create_node(int dest) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->dest = dest;
    new_node->nxt = NULL;
    return new_node;
}

// gph
struct gph* create_gph(int v, bool directed) {
    struct gph* gph = (struct gph*)malloc(sizeof(struct gph));
    gph->v = v;
    gph->directed = directed;

    // alist
    gph->array = (struct List**)malloc(v * sizeof(struct List*));
    for (int i = 0; i < v; ++i) {
        gph->array[i] = (struct List*)malloc(sizeof(struct List));
        gph->array[i]->head = NULL;
    }

    // amtx
    gph->adj_mtx = (bool**)malloc(v * sizeof(bool*));
    for (int i = 0; i < v; ++i) {
        gph->adj_mtx[i] = (bool*)malloc(v * sizeof(bool));
        for (int j = 0; j < v; ++j) {
            gph->adj_mtx[i][j] = false;
        }
    }

    return gph;
}

void add_edge_list(struct gph* gph, int src, int dest) {
    struct node* new_node = create_node(dest);
    new_node->nxt = gph->array[src]->head;
    gph->array[src]->head = new_node;

    if (!gph->directed) {
        new_node = create_node(src);
        new_node->nxt = gph->array[dest]->head;
        gph->array[dest]->head = new_node;
    }
}
void add_edge_mtx(struct gph* gph, int src, int dest) {
    gph->adj_mtx[src][dest] = true;

    if (!gph->directed)
        gph->adj_mtx[dest][src] = true;
}

void remove_edge_list(struct gph* gph, int src, int dest) {
    struct node* curr = gph->array[src]->head;
    struct node* prev = NULL;

    while (curr && curr->dest != dest) {
        prev = curr;
        curr = curr->nxt;
    }

    if (curr) {
        if (prev)
            prev->nxt = curr->nxt;
        else
            gph->array[src]->head = curr->nxt;

        free(curr);

        if (!gph->directed) {
            curr = gph->array[dest]->head;
            prev = NULL;
            while (curr && curr->dest != src) {
                prev = curr;
                curr = curr->nxt;
            }
            if (prev)
                prev->nxt = curr->nxt;
            else
                gph->array[dest]->head = curr->nxt;

            free(curr);
        }
    }
}

void remove_edge_mtx(struct gph* gph, int src, int dest) {
    gph->adj_mtx[src][dest] = false;

    if (!gph->directed)
        gph->adj_mtx[dest][src] = false;
}

void dfs_recurs(struct gph* gph, int v, bool* visit) {
    visit[v] = true;
    printf("%d ", v);

    struct node* temp = gph->array[v]->head;
    while (temp != NULL) {
        int adj = temp->dest;
        if (!visit[adj]) {
            dfs_recurs(gph, adj, visit);
        }
        temp = temp->nxt;
    }
}

void dfs(struct gph* gph, int start) {
    bool* visit = (bool*)malloc(gph->v * sizeof(bool));
    for (int i = 0; i < gph->v; ++i) {
        visit[i] = false;
    }

    dfs_recurs(gph, start, visit);
}

void bfs(struct gph* gph, int start) {
    bool* visit = (bool*)malloc(gph->v * sizeof(bool));
    for (int i = 0; i < gph->v; ++i) {
        visit[i] = false;
    }

    struct que* que = create_que(gph->v);

    visit[start] = true;
    enque(que, start);

    while (!is_empty(que)) {
        int current = deque(que);
        printf("%d ", current);

        struct node* temp = gph->array[current]->head;
        while (temp != NULL) {
            int adj = temp->dest;
            if (!visit[adj]) {
                visit[adj] = true;
                enque(que, adj);
            }
            temp = temp->nxt;
        }
    }
}

bool is_connected(struct gph* gph, int start) {
    bool* visit = (bool*)malloc(gph->v * sizeof(bool));
    for (int i = 0; i < gph->v; ++i) {
        visit[i] = false;
    }

    dfs_recurs(gph, start, visit);

    for (int i = 0; i < gph->v; ++i) {
        if (!visit[i])
            return false;
    }

    return true;
}

bool has_cycle(struct gph* gph, int v, bool* visit, bool* rec_stack) {
    if (!visit[v]) {
        visit[v] = true;
        rec_stack[v] = true;

        struct node* temp = gph->array[v]->head;
        while (temp != NULL) {
            int adj = temp->dest;
            if (!visit[adj] && has_cycle(gph, adj, visit, rec_stack))
                return true;
            else if (rec_stack[adj])
                return true;
            temp = temp->nxt;
        }
    }
    rec_stack[v] = false;
    return false;
}

void topological_sort(struct gph* gph, int start, bool* visit, int* stack, int* top) {
    visit[start] = true;

    struct node* temp = gph->array[start]->head;
    while (temp != NULL) {
        int adj = temp->dest;
        if (!visit[adj]) {
            topological_sort(gph, adj, visit, stack, top);
        }
        temp = temp->nxt;
    }

    stack[(*top)++] = start;
}

// runner
void drun(struct gph* gph) {
    printf("DFS: ");
    dfs(gph, 0);
    printf("\n");

    printf("BFS: ");
    bfs(gph, 0);
    printf("\n");

    bool is_conn = is_connected(gph, 0);
    printf("Is the graph connected? %s\n", is_conn ? "Yes" : "No");

    bool has_cycle_result = false;
    bool* visited = (bool*)malloc(gph->v * sizeof(bool));
    bool* rec_stack = (bool*)malloc(gph->v * sizeof(bool));
    for (int i = 0; i < gph->v; ++i) {
        visited[i] = false;
        rec_stack[i] = false;
    }
    for (int i = 0; i < gph->v; ++i) {
        if (!visited[i]) {
            has_cycle_result = has_cycle(gph, i, visited, rec_stack);
            if (has_cycle_result)
                break;
        }
    }
    printf("Does the graph have a cycle? %s\n", has_cycle_result ? "Yes" : "No");

    int* stack = (int*)malloc(gph->v * sizeof(int));
    int top = 0;
    for (int i = 0; i < gph->v; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < gph->v; ++i) {
        if (!visited[i]) {
            topological_sort(gph, i, visited, stack, &top);
        }
    }

    printf("Topological Sort: ");
    for (int i = gph->v - 1; i >= 0; --i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    struct gph* gph = create_gph(6, false);
    add_edge_list(gph, 0, 1);
    add_edge_list(gph, 0, 2);
    add_edge_list(gph, 1, 3);
    add_edge_list(gph, 2, 3);
    add_edge_list(gph, 3, 4);
    add_edge_list(gph, 4, 5);
    drun(gph);

    struct gph* directedGph = create_gph(6, true);
    add_edge_list(directedGph, 5, 2);
    add_edge_list(directedGph, 5, 0);
    add_edge_list(directedGph, 4, 0);
    add_edge_list(directedGph, 4, 1);
    add_edge_list(directedGph, 2, 3);
    add_edge_list(directedGph, 3, 1);
    drun(directedGph);

    return 0;
}