// https://leetcode.com/problems/beautiful-arrangement/description/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int *g_slot;
int g_count;

inline int _is_beautiful(int num,int current) {
    return !(num%current && current%num);
}

inline void _swap(int *a,int *b) {
    if (*a == *b) return;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void _count_arrangement(int level,int n) {
    int i;
    if (level >= n) {
        for(i=0;i<n;i++) {
            printf("%d",g_slot[i]);
        }
        printf("\n");
        g_count += 1;
        return;
    } else {
       for(i=level;i<n;i++) {
            _swap(g_slot+level,g_slot+i);       
            if (_is_beautiful(g_slot[level],level+1)) {
                _count_arrangement(level+1,n);
            }
            _swap(g_slot+level,g_slot+i);
       }
    }
}

int countArrangement(int N) {
    int i;
    g_slot = (int *)malloc(N*sizeof(int));
    g_count = 0;
    
    for (i=0;i<N;i++) {
        g_slot[i] = i+1;
    }

    _count_arrangement(0,N);

    free(g_slot);
    g_slot = NULL;

    return g_count;
}

int main() {
    countArrangement(1);
}
