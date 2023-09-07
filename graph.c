#include <stdio.h>
#include <stdlib.h>

typedef struct vertex {
  int id;
  int weight;
  struct vertex *next;
} vertex;

typedef struct graph {
  vertex *vertices;
  int n_vertices;
  int n_edges;
} graph;

graph *graph_create(int n_vertices) {
  graph *g = malloc(sizeof(graph));
  g->vertices = malloc(sizeof(vertex) * n_vertices);
  g->n_vertices = n_vertices;
  g->n_edges = 0;

  for (int i = 0; i < n_vertices; i++) {
    g->vertices[i].id = i;
    g->vertices[i].weight = 0;
    g->vertices[i].next = NULL;
  }

  return g;
}

void graph_add_edge(graph *g, int from, int to, int weight) {
  vertex *v1 = &g->vertices[from];
  vertex *v2 = &g->vertices[to];

  vertex *new_edge = malloc(sizeof(vertex));
  new_edge->id = to;
  new_edge->weight = weight;
  new_edge->next = NULL;

  v1->next = new_edge;

  if (g->n_edges % 2 == 0) {
    new_edge = malloc(sizeof(vertex));
    new_edge->id = from;
    new_edge->weight = weight;
    new_edge->next = NULL;

    v2->next = new_edge;
  }

  g->n_edges++;
}

void graph_print(graph *g) {
  for (int i = 0; i < g->n_vertices; i++) {
    vertex *v = &g->vertices[i];

    printf("%d: ", v->id);
    vertex *e = v->next;
    while (e != NULL) {
      printf("%d(%d) ", e->id, e->weight);
      e = e->next;
    }
    printf("\n");
  }
}

int main() {
  graph *g = graph_create(5);

  graph_add_edge(g, 0, 1, 10);
  graph_add_edge(g, 0, 2, 15);
  graph_add_edge(g, 1, 3, 20);
  graph_add_edge(g, 2, 3, 25);
  graph_add_edge(g, 3, 4, 30);

  graph_print(g);

  return 0;
}