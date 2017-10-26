// fibonacci 数列

int fibo(int n) {
    if (n<=1) {
        return n;
    } else {
        return fibo(n-1) + fibo(n-2);
    }
}
