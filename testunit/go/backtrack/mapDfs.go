/* 
 * 图的深度遍历算法
 */
package main

import (
    "fmt"
)

const N = 5
var (
    visit [N]int
    // 模拟栈操作
    stack [N]int
)

type node struct {
    adj_vertex int // 邻接表节点
    next * node // 下个节点指针
}

type adj_list struct {
   vertext int // 当前节点序号
   first_node * node // 邻接链表头指针
} 

type adj_matrix struct {
    vertex [N]int
    edge [N][N]int // 邻接矩阵
}

func dfs_visit(g *adj_matrix,u int) {
    visit[u]=1
    fmt.Println("visit:",g.vertex[u]) 

    for i:=0; i<N; i++ {
        if g.edge[u][i] == 1 && visit[i] !=1 {
            dfs_visit(g,i)
        }
    }
}

func dfs_recursion(g *adj_matrix) {
    // for i:=0;i<N;i++ {
    // 如果是无向联通图，那么遍历任意一个节点都可以遍历完所有结点。
    i := 0
       if visit[i] !=1 {
           dfs_visit(g,i)
       }
       fmt.Println("map:",visit)
   // }
}

// 非递归方式实现图dfs遍历
func dfs_stack(g *adj_matrix) {
    top := 0 // 栈顶点
    first := g.vertex[0] // 访问的第一个节点
    
    // 访问
    fmt.Println("visit:",first)
    visit[first-1]=1;
    // 这里top 赋值为0，表示已经做了++操作
    stack[top] = first
    
    for top >= 0 {
        i := 0
        for ;i<N;i++ {
            if g.edge[stack[top]-1][i]==1 && visit[i]==0 {
                // 栈顶节点的邻接节点且未被访问过
                fmt.Println("visit:",g.vertex[i])
                visit[i]=1
                top++;stack[top]=g.vertex[i]
                // 这个break一定要加
                break
            }
        }
        // 退栈
        if i == N {
            top--
        }
    }
}

func main() {
    // 邻接链表定义
    // var lists [6]adj_list 

    // 邻接矩阵定义
    matrix := adj_matrix {
        // 这么变态的go语言赋值语法
        // vertex:[N]int{1, 2, 3, 4, 5, 6},
        // edge:[N][N]int{    
        //     {0, 1, 0, 1, 0, 0},  
        //     {0, 0, 0, 0, 1, 0},  
        //     {0, 0, 0, 0, 1, 1},  
        //     {0, 1, 0, 0, 0, 0},  
        //     {0, 0, 0, 1, 0, 0},  
        //     {0, 0, 0, 0, 0, 1}}} 
        vertex:[N]int{1, 2, 3, 4, 5},
        edge:[N][N]int{    
            {0, 1, 0, 0,1},  
            {1, 0, 1, 1, 1},  
            {0, 1, 0, 1, 0},  
            {0, 1, 1, 0, 1},  
            {1, 1, 0, 1, 0}}}  

    fmt.Println("matrix:",matrix)
    // dfs_recursion(&matrix)
    dfs_stack(&matrix)
}
