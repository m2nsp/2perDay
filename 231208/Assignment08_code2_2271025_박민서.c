#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8
#define INF 1000L

typedef struct {
    int vertex;
    int weight;
} Node;

Node min_heap[MAX_VERTICES];
int heap_size = 0;

int weight[MAX_VERTICES][MAX_VERTICES] = {
    {0, 3, INF, INF, INF, INF, INF, 14},
    {3, 0, 8, INF, INF, INF, INF, 10},
    {INF, 8, 0, 15, 2, INF, INF, INF},
    {INF, INF, 15, 0, INF, INF, INF, INF},
    {INF, INF, 2, INF, 0, 9, 4, 5},
    {INF, INF, INF, INF, 9, 0, INF, INF},
    {INF, INF, INF, INF, 4, INF, 0, 6},
    {14, 10, INF, INF, 5, INF, 6, 0}
};

int selected[MAX_VERTICES];
int dist[MAX_VERTICES];

void build_min_heap();
Node delete_min_heap();
void decrease_key_min_heap(int i, int key);
void prim(int s, int n);
void print_prim();

void build_min_heap() {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        int index = i;
        while (2 * index + 1 < heap_size) {
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            int smallest = index;

            if (left_child < heap_size && min_heap[left_child].weight < min_heap[smallest].weight) {
                smallest = left_child;
            }

            if (right_child < heap_size && min_heap[right_child].weight < min_heap[smallest].weight) {
                smallest = right_child;
            }

            if (smallest != index) {
                Node temp = min_heap[index];
                min_heap[index] = min_heap[smallest];
                min_heap[smallest] = temp;
                index = smallest;
            }
            else {
                break;
            }
        }
    }
}

Node delete_min_heap() {
    if (heap_size == 0) {
        fprintf(stderr, "Heap is empty.\n");
        exit(EXIT_FAILURE);
    }

    Node min_node = min_heap[0];
    min_heap[0] = min_heap[heap_size - 1];
    heap_size--;

    build_min_heap();
    return min_node;
}

void decrease_key_min_heap(int i, int key) {
    if (key >= min_heap[i].weight) {
        fprintf(stderr, "Error: New key is not smaller than the current key.\n");
        exit(EXIT_FAILURE);
    }

    min_heap[i].weight = key;

    while (i > 0 && min_heap[i].weight < min_heap[(i - 1) / 2].weight) {
        Node temp = min_heap[i];
        min_heap[i] = min_heap[(i - 1) / 2];
        min_heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void prim(int s, int n) {
    for (int u = 0; u < n; u++) {
        dist[u] = INF;
        selected[u] = FALSE;
    }

    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        Node node;
        node.vertex = i;
        node.weight = dist[i];
        min_heap[heap_size++] = node;
    }

    build_min_heap();

    while (heap_size > 0) {
        Node u_node = delete_min_heap();
        int u = u_node.vertex;
        selected[u] = TRUE;

        if (dist[u] == INF) {
            return;
        }

        print_prim();

        for (int v = 0; v < n; v++) {
            if (weight[u][v] != INF && !selected[v] && weight[u][v] < dist[v]) {
                dist[v] = weight[u][v];
                decrease_key_min_heap(v, weight[u][v]);
            }
        }
    }
}

void print_prim() {
    int parent[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        parent[i] = -1;
    }

    while (heap_size > 0) {
        Node u_node = delete_min_heap();
        int u = u_node.vertex;

        if (parent[u] != -1 && u != parent[u]) {
            printf("Vertex %d -> %d edge: %d\n", parent[u], u, u_node.weight);  // Corrected the order
        }

        for (int v = 0; v < MAX_VERTICES; v++) {
            if (weight[u][v] != INF && !selected[v] && weight[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = weight[u][v];

                Node node;
                node.vertex = v;
                node.weight = dist[v];
                min_heap[heap_size++] = node;

                build_min_heap();
            }
        }
    }
}

int main() {
    prim(0, MAX_VERTICES);

    return 0;
}
