#include <stdio.h>

int g_target;
int **g_matrix;

bool _search_matrix(int lx,int ly,int rx,int ry) {
    if (lx == rx) {
        // 退化成二分查找   
        int mid;
        while (ly < ry) {
            mid = (ly + ry) / 2;
            if (g_matrix[lx][mid] == g_target) {
                return true;
            }
            if (g_matrix[lx][mid] < g_target) {
                ly = mid + 1;
            } else {
                ry = mid - 1;
            }
        }
        return false;
    } else if (ly == ry) {
        // 退化成二分查找   
        int mid;
        while (lx < rx) {
            int mid = (lx + rx) / 2;
            if (g_matrix[mid][ly] == g_target) {
                return true;
            }
            if (g_matrix[mid][ly] < g_target) {
                lx = mid + 1;
            } else {
                rx = mid - 1;
            }
        }
        return false;
    } else {
        int mx = (rx + lx) / 2;
        int my = (ly + ry) / 2;
        if (g_target == g_matrix[mx][my]) {
            return true;
        } else if (g_matrix[mx][my] > g_target) {
            return _search_matrix(lx,ly,mx,my);
        } else {
            return _search_matrix(mx+1,ly,rx,my) || _search_matrix(lx,my+1,mx,ry) || _search_matrix(mx+1,my+1,rx,ry);
        }
    }
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    g_target = target;
    g_matrix = matrix;

    return _search_matrix(0,0,matrixRowSize-1,matrixColSize-1);
}
