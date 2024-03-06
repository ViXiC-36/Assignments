#ifndef _NETWORK_CPP_
#define _NETWORK_CPP_
// (Un)Directional (Un)Weighted Graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXVERTEX 100
#define MAXEDGE 20000

// 顶点结构体
typedef struct Vertex
{
    int id;               // 顶点编号（唯一）
    int w;                // 顶点权值
    int degree;           // 顶点的度
    int in_deg, out_deg;  // 入度和出度
    int edges[MAXVERTEX]; // 边的编号
} Vertex;

// 边结构体
typedef struct Edge
{
    int id; // 边的编号（唯一）
    int h;  // 边头顶点编号
    int t;  // 边尾顶点编号
    int w;  // 权值
} Edge;

// 图结构体
typedef struct Graph
{
    Vertex v[MAXVERTEX]; // 顶点数组
    Edge e[MAXEDGE];     // 边数组
    int nv;              // 顶点数
    int ne;              // 边数
    bool dirctional;     // t:有向图，f:无向图
    bool weighted;       // t:带权图，f:等权图
} Graph;

#include "showgt.h"

// 生成一个随机图，包括n个顶点，每个顶点和其它顶点连边的概率为p
int randgengraph(int n, float p, bool directional, bool weighted, const char *filename, int seed)
{
    srand(seed);
    char *content = (char *)malloc(5000000);
    if (!content)
    {
        printf("分配存储空间失败！\n");
        exit(0);
    }
    FILE *fp = fopen(filename, "wb");
    if (!fp)
    {
        printf("生成图文件%s时失败！\n", filename);
        exit(0);
    }
    long offset = 0; // content当前的写入位置
    int ne = 0;      // 生成边数
    for (int i = 0; i < n; i++)
        offset += sprintf(content + offset, "%3d %5d\n", i, rand() % 100); // 写入顶点的编号和顶点随机权值
    int pn = (int)(10000 * p);
    if (directional)
    { // 有向图
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && rand() % 10000 < pn)
                {
                    offset += sprintf(content + offset, "%3d %3d %4d\n", i, j, weighted ? rand() % 100 : 1);
                    ne++;
                }
    }
    else
    { // 无向图
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (i != j && rand() % 10000 < pn)
                {
                    offset += sprintf(content + offset, "%3d %3d %4d\n", i, j, weighted ? rand() % 100 : 1);
                    ne++;
                }
    }
    char ch[40];
    int sz = sprintf(ch, "%d %7d %5s %5s\n", n, ne, weighted ? "true" : "flase", directional ? "true" : "flase");
    fwrite(&ch, sz, 1, fp);         // 写入图的顶点数和边数
    fwrite(content, offset, 1, fp); // 写入图的顶点和边的信息
    fclose(fp);
    free(content);
    return 1;
}

// 从文件中读入图，在内存中生成图的表示
void initGraphFromFile(Graph *g, const char *gfile)
{
    FILE *fp = fopen(gfile, "r");
    if (!fp)
    {
        printf("读取图数据文件出错！\n");
        exit(0);
    }
    char bv[10];
    // 读取图的基本信息
    fscanf(fp, "%u%u%s", &(g->nv), &(g->ne), bv);
    // printf("%d %d %s", g->ne, g->nv, bv);
    g->weighted = strcmp(bv, "true") == 0 ? true : false;
    fscanf(fp, "%s", bv);
    g->dirctional = strcmp(bv, "true") == 0 ? true : false;
    // 读取顶点信息
    for (int i = 0; i < g->nv; i++)
    {
        fscanf(fp, "%d%d", &(g->v[i].id), &(g->v[i].w));
        g->v[i].degree = 0;
        // printf("顶点%d-权%d\n", g->v[i].id, g->v[i].w);
    }
    // 读取边信息
    for (unsigned long i = 0; i < g->ne; i++)
    {
        fscanf(fp, "%u%u%d", &(g->e[i].h), &(g->e[i].t), &(g->e[i].w));
        // printf("边:%u-%u=>%d\n", g->e[i].h, g->e[i].t, g->e[i].w);
        g->e[i].id = i;
        unsigned h, t;
        h = g->e[i].h;
        t = g->e[i].t;
        g->v[h].edges[g->v[h].degree++] = i;
        if (g->dirctional == false)
            g->v[t].edges[g->v[t].degree++] = i;
    }
    fclose(fp);
}

// 生成一个空图
Graph *initGraph(bool directional, bool weighted)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->nv = g->ne = 0;
    g->dirctional = directional;
    g->weighted = weighted;
    return g;
}

// 打印邻接表的信息
void printgraph(Graph *g)
{
    printf("图的基本信息:顶点数(%u)-边数(%lu)-%s-%s\n", g->nv, g->ne, g->weighted ? "加权图" : "等权图", g->dirctional ? "有向图" : "无向图");
    for (int i = 0; i < g->nv;)
    {
        if (g->v[i].id == -1)
            continue;
        printf("ID(%u)-度(%d)-权(%d)-边表 t(eid|w):%u", g->v[i].id, g->v[i].degree, g->v[i].w, g->v[i].id);
        for (int j = 0; j < g->v[i].degree;)
        {

            int e = g->v[i].edges[j]; // according to the connected edge, find the connected vex
            if (g->e[j].id == -1)
                continue;
            // unsigned long e = g->v[i].edges[j]; // wrong
            // // for (int k = 0; k < g->v[i].degree; k++)
            // //     if (g->v[i].edges[j] == g->e[k].id)
            // //         e = g->e[k].id;
            if (g->v[i].id == g->e[e].h)
                printf("->%u(%d)", g->e[e].t, g->e[e].w);
            else
                printf("->%u(%d)", g->e[e].h, g->e[e].w);
            j++;
        }
        printf("\n");
        i++;
    }
}

// 查找给定编号的顶点，返回其顶点数组下标
int getVexIdx(Graph *g, int id)
{
    for (int i = 0; i < g->nv; i++)
        if (g->v[i].id == id)
            return i;
    printf("input wrong vertex id in getVexIdx()!\n");
    exit(0);
}

// 查找给定编号的顶点，返回其权值
int getVexW(Graph *g, int id)
{
    for (int i = 0; i < g->nv; i++)
        if (g->v[i].id == id)
            return g->v[i].w;
    printf("input wrong vertex id in getVexW()!\n");
    exit(0);
}

// 查找给定编号的顶点，返回其度
int getVexDegree(Graph *g, int id)
{
    for (int i = 0; i < g->nv; i++)
        if (g->v[i].id == id)
            return g->v[i].degree;
    printf("input wrong vertex id in getVexDegree()!\n");
    exit(0);
}

// 查找给定编号的顶点,返回其所有边
int *getEdgesByNode(Graph *g, int id, int *ne)
{
    for (int i = 0; i < g->nv; i++)
        if (g->v[i].id == id)
        {
            *ne = g->v[i].degree;
            return g->v[i].edges;
        }
    printf("input wrong vertex id in getEdgesByNode()!\n");
    exit(0);
}

// 查找给定编号的边，返回其边数组下标
int getEdgeIdx(Graph *g, int id)
{
    for (int i = 0; i < g->ne; i++)
        if (g->e[i].id == id)
            return i;
    printf("input wrong edge id in getEdgeIdx()!\n");
    exit(0);
}

// 查找给定编号的边，返回其权值
int getEdgeW(Graph *g, int id)
{
    for (int i = 0; i < g->ne; i++)
        if (g->e[i].id == id)
            return g->e[i].w;
    printf("input wrong edge id in getEdgeW()!\n");
    exit(0);
}

// 查找给定编号的边，返回其两个顶点
void getVexByEdge(Graph *g, int id, int *h, int *t)
{
    for (int i = 0; i < g->ne; i++)
        if (g->e[i].id == id)
        {
            *h = g->e[i].h;
            *t = g->e[i].t;
            return;
        }
    printf("input wrong edge id in getVexByEdge()!\n");
    exit(0);
}

// 通过权值查找顶点编号
int locateVex(Graph *g, int w)
{
    for (int i = 0; i < g->nv; i++)
        if (g->v[i].w == w)
            return g->v[i].id;
    return -1;
}

// 通过权值查找边编号
int locateEdge(Graph *g, int w)
{
    for (int i = 0; i < g->ne; i++)
        if (g->e[i].w == w)
            return g->e[i].id;
    return -1;
}

// 设置顶点权值
void setVexW(Graph *g, int id, int w)
{
    for (int i = 0; i < g->nv; i++)
        if (g->v[i].id == id)
        {
            g->v[i].w = w;
            return;
        }
    printf("input wrong vertex id in setVexW()!\n");
    exit(0);
}

// 设置边权值
void setEdgeW(Graph *g, int id, int w)
{
    for (int i = 0; i < g->ne; i++)
        if (g->e[i].id == id)
        {
            g->e[i].w = w;
            return;
        }
    printf("input wrong edge id in setEdgeW()!\n");
    exit(0);
}

// 删除边
void deleteEdge(Graph *g, int id)
{
    for (int i = 0; i < g->ne; i++) // delete the vertex info abt the edges first
        if (g->e[i].id == id)       // found
        {
            int h = g->e[i].h; // info in head vex to be eliminated
            for (int j = 0; j < g->v[h].degree;)
            {
                if (g->v[h].edges[j] == -1)
                    continue;
                if (g->v[h].edges[j] == id)
                {
                    // g->v[h].edges[j] == -1;
                    // for (int k = j; k < g->v[h].degree - 1; k++)
                    //     g->v[h].edges[k] = g->v[h].edges[k + 1];
                    g->v[h].edges[j] = -1;
                    g->v[h].degree--;
                }
                j++;
            }

            int t = g->e[i].t; // info in tail vex eliminated
            for (int j = 0; j < g->v[t].degree;)
            {
                if (g->v[t].edges[j] == -1)
                    continue;
                if (g->v[t].edges[j] == id)
                {
                    // g->v[t].edges[j] == -1;
                    // for (int k = j; k < g->v[t].degree - 1; k++)
                    //     g->v[t].edges[k] = g->v[t].edges[k + 1];
                    g->v[t].edges[j] = -1;
                    g->v[t].degree--;
                }
                j++;
            }

            // for (int j = i; j < g->ne; j++) // info of the edge in the graph eliminated
            //     g->e[j] = g->e[j + 1];
            g->e[i].id = -1;
            g->ne--;
            return;
        }
    printf("Failed to delete the edge! ID of the edge not found!\n");
    exit(0);
}

// 删除顶点，同时与其关联的边全部删除，记得调用 deleteEdge() 哟~
void deleteVex(Graph *g, int id)
{
    for (int i = 0; i < g->nv; i++)
        if (id == g->v[i].id) // found the vex
        {
            for (; g->v[i].degree > 0;)
            {
                if (g->v[i].id == -1)
                    continue;
                deleteEdge(g, g->v[i].edges[g->v[i].degree - 1]); // dlt the edges connected to the vex
                g->v[i].degree--;
            }
            // if (g->v[i].degree != 0)
            //     printf("Something went wrong! The edges connected to the vex to be deleted are not cleared up yet!\n");
            // for (int j = i; j < g->nv; j++)
            //     g->v[j] = g->v[j + 1];
            g->v[i].id = -1;
            g->nv--;
            return;
        }
    printf("Failed to delete the vex! ID of teh vex not found!\n");
    exit(0);
}

// 增加顶点
void addVex(Graph *g, int w)
{
    if (g->nv == MAXVERTEX)
    {
        printf("Failed to add a vertex! Otherwise the number of vertexes overflows.\n");
        return;
    }
    g->v[g->nv].degree = 0;
    g->v[g->nv].id = (g->nv) ? g->v[g->nv - 1].id + 1 : 0;
    g->v[g->nv].w = w;
    g->nv++;
}

// 增加边
void addEdge(Graph *g, int w, int h, int t) // 没有问题
{
    if (g->ne == MAXEDGE)
    {
        printf("Failed to add an edge! Otherwise the number of the edges overflows.\n");
        return;
    }
    // update the info of the edge
    g->e[g->ne].id = (g->ne) ? g->e[g->ne - 1].id + 1 : 0; // 取前一点id+1，如果空就从零开始
    g->e[g->ne].w = w;                                     //
    g->e[g->ne].h = h;
    g->e[g->ne].t = t;
    // update the info of the connected vexes
    g->v[h].edges[g->v[h].degree] = g->e[g->ne].id; // 把这条边连到头点上
    g->v[h].degree++;
    g->v[t].edges[g->v[t].degree] = g->e[g->ne].id; //  把这条边连到尾点上
    g->v[t].degree++;

    g->ne++;
}

// Connect all the vexes whose id are even;
void ConnectEvenVx(Graph *g)
{ // Traverse to ensure there is no repetitive edges
    int skip = 0;
    for (int h = 0; h < g->nv; h += 2)
        for (int t = h; t < g->nv; t += 2, skip = 0)
        {
            if (h == t)
                skip++;
            for (int i = 0; i < g->ne; i++) // Ignore the existent edges
            {
                if (g->dirctional) // directional graph, two edges with different directions allowed
                {
                    if ((g->e[i].h == h) && (g->e[i].t == t)) // such edge already exists
                        skip++;
                }
                else // un-directional graph, one edge allowed
                {
                    if ((g->e[i].h == h) && (g->e[i].t == t))
                        skip++;
                    if ((g->e[i].h == t) && (g->e[i].t == h))
                        skip++;
                }
            }
            if (!skip)
                addEdge(g, (g->weighted) ? rand() % 100 : 1, h, t);
        }
}

int main()
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (!g)
    {
        printf("error\n");
        exit(0);
    }
    // randgengraph(10, 0.2, 0, 0, "graph.txt", 5);
    // initGraphFromFile(g, "graph.txt");
    g = initGraph(0, 0); //
    for (int i = 0; i < 5; i++)
        addVex(g, i); // 给五个点
    printgraph(g);
    printf("\n");

    ConnectEvenVx(g); // 链接所有偶数点
    printgraph(g);
    printf("\n");

    for (int i = 0; i < 2; i++)          // 链接0-1， 2-3
        addEdge(g, i, i * 2 + 1, i * 2); // graph, weight, idhead, idtail
    printgraph(g);
    printf("\n");
    // saveGraph(g, "deux.html");

    int *h = (int *)malloc(sizeof(int));
    int *t = (int *)malloc(sizeof(int));
    addVex(g, 30);        // graph, weight
    addEdge(g, 50, 1, 3); // graph, weight, head vex id, tail vex id
    printgraph(g);
    printf("\n");

    getVexByEdge(g, 3, h, t); // graph, id, head vex id storage, tail vex id storage
    printf("%d %d\n", *h, *t);

    deleteEdge(g, 3); // graph, id
    printgraph(g);
    printf("\n");

    deleteVex(g, 2); // graph, id
    printgraph(g);
    printf("\n");

    // ConnectEvenVx(g);
}
#endif