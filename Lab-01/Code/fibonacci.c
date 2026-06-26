#include <stdio.h>

void fibonacci(int n, unsigned long long a, unsigned long long b) {
    if (n == 0) return;
    printf("%llu ", a);
    fibonacci(n - 1, b, a + b);
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Sequence: ");
    fibonacci(n, 0, 1);

    return 0;
}
