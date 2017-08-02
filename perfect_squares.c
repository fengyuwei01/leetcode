#include<stdio.h>
#include<stdlib.h>
#include<math.h>

bool isPerfect(int num) {
    return false;
}

int numSquares(int n) {
    int *D = (int *)malloc(n*sizeof(int)+sizeof(int));    
    int i,j;
    int tmp;

    // 初始化
    D[0] = 0;
    for (i=1; i<=n; i++) {
        D[i] = -1;
    }

    // 初始化perfect num
    for (i=1; (i*i) <= n; i++) {
        D[i*i] = 1;
    }

    // D(n) = min(D(i)+D(n-i))
    for(i=0; i<=n; i++) {
        for (j=0; j<=i/2; j++) {
            tmp = D[j] + D[i-j];
            if (D[i] == -1 || tmp < D[i]) {
                D[i] = tmp;
            }
        }
    }

    tmp = D[n];
    free(D);

    return tmp;
}


