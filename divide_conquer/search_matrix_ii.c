#include <stdio.h>
#include <stdlib.h>
int g_target;
int **g_matrix;

bool _search_matrix(int lx,int ly,int rx,int ry) {
    //printf("into _search_matrix [%d,%d]\n",lx,ry);
    if (lx == rx && ly == ry) {
        return g_matrix[lx][ly] == g_target;
    }
    
    if (g_target == g_matrix[lx][ry]) {
        return true;
    } else if (g_target < g_matrix[lx][ry]) {
        if (ly == ry) {
            return false;
        }
        return _search_matrix(lx,ly,rx,ry-1);
    } else {
        if (lx == rx) {
            return false;
        }
        return _search_matrix(lx+1,ly,rx,ry);
    }
}
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    g_target = target;
    g_matrix = matrix;
    
    //printf("%d,%d\n",matrixRowSize,matrixColSize);
    if ((matrixRowSize == 0 || matrixRowSize == 1) && matrixColSize == 0) {
        return false;
    }

    return _search_matrix(0,0,matrixRowSize-1,matrixColSize-1);
}

int main() {
    int m[5][5] = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    searchMatrix((int **)m,5,5,5);
}
