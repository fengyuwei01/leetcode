// 图算法总结
#include "stdlib.h"
#include "stdio.h"

typedef struct vertex *vertex_t;
// 图节点
struct vertex {
    int no; // 当前节点序号
    int color; // 颜色
    int d; // 开始处理时间
    int f; // 结束处理时间
    vertex_t pi; // 前驱子

    // vertex_t next; // 下个节点
};

typedef struct adjoin_node *adjoin_node_t;
struct adjoin_node {
    vertex_t v;
    adjoin_node_t next;
};

typedef struct graph {
    vertex_t V; // 图节点集合
    int size;
    adjoin_node_t *Adj; // 邻接链表
} *graph_t;

graph_t create_graph(int **edge,int size) {
    int i,j;
    vertex_t v;
    adjoin_node_t adj_node;

    graph_t g = malloc(sizeof(*g));
    g->size = size;
    g->V = malloc(g->size * sizeof(struct vertex));
    g->Adj = malloc(g->size * sizeof(adjoin_node_t));

    v = g->V;
    for (i=0;i<size;i++) {
        v->no = i;
        v->color = 0;
        v->d = 0;
        v->f = 0;
        v->pi = NULL;
        v++;
    }

    for (i=0;i<size;i++) {
        adj_node = g->Adj[i];
        for (j=0;j<size;j++) {
            if (edge[i][j] == 1) {
                adj_node = malloc(sizeof(*adj_node));
                adj_node->v = &g->V[j];
                adj_node->next = NULL;
                // 指向下个节点
                adj_node = adj_node->next;
            }
        }
    }

    return g;
}

void free_graph(graph_t g) {
    if (g == NULL) {
        return;
    }

    int i;
    adjoin_node_t node;
    for (i=0;i<g->size;i++) {
        node = g->Adj[i];
        while (node) {
            adjoin_node_t tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(g->Adj);
    g->Adj = NULL;

    free(g->V); 
    g->V = NULL;
    
    free(g);
    g = NULL;
}

int g_time = 0;
void _graph_dfs_travel(vertex_t u,adjoin_node_t *adj_list,void (*visit)(vertex_t v)) {
    adjoin_node_t adj_node = adj_list[u->no];

    u->color = 1; 
    g_time = g_time + 1;
    u->d = g_time;

    while (adj_node != NULL) {
        if (adj_node->v->color == 0) {
            adj_node->v->pi = u;
            _graph_dfs_travel(adj_node->v,adj_list,visit);
        }
        adj_node = adj_node->next;
    }

    u->color = 2;
    g_time = g_time + 1;
    u->f = g_time;
    visit(u);
}

void graph_dfs_travel(const graph_t g,void (*visit)(vertex_t v)) {
    int i;
    int size = g->size;
    vertex_t v = g->V;
    for (i=0;i<size;i++) {
       v->color = 0; 
       v->pi = NULL;
    }

    i = 0;
    for (;i<size;i++) {
        if (g->V[i].color == 0) {
            _graph_dfs_travel(&g->V[i],g->Adj,visit);
        }
    }
}

void p(vertex_t v) {
    if (v != NULL) {
        printf("val:%d,stime:%d,etime:%d\n",v->no,v->d,v->f);
    }
}

int main() {
    printf("hello world\n");
    int size = 5;
    int edge[5][5] = {  
        {0,1, 0, 0, 1},  
        {1, 0, 1, 1,1},  
        {0, 1, 0, 1,0},  
        {0, 1, 1, 0,1},  
        {1, 1, 0, 1,0}  
    };  

    graph_t g = create_graph((int **)edge,size);
    graph_dfs_travel(g,p);
    free_graph(g); 
}

