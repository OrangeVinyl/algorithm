#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

int visited[MAX_VERTICES];

typedef struct GraphNode
{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType
{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType *g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES)
    {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}
void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node;
    if (u >= g->n || v >= g->n)
    {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void dfs_list(GraphType *g, int v)
{
    GraphNode *w;
    visited[v] = TRUE;
    printf("%d -> ", v);
    for (w = g->adj_list[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs_list(g, w->vertex); 
}

void print_adj_list(GraphType *g) {
    for (int i=0; i < g -> n; i++) {
        GraphNode *p = g ->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while(p!=NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);
    for (int i = 0; i < 7; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    insert_edge(g, 2, 4);
    insert_edge(g, 4, 2);
    insert_edge(g, 3, 5);
    insert_edge(g, 5, 3);
    insert_edge(g, 3, 6);
    insert_edge(g, 6, 3);
    insert_edge(g, 4, 6);
    insert_edge(g, 6, 4);
    insert_edge(g, 5, 6);
    insert_edge(g, 6, 5);
    print_adj_list(g);
    printf("==========================");
    printf("\n<인접 리스트를 사용한 DFS>\n");
    dfs_list(g, 0);
    return 0;
}