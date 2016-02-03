// https://leetcode.com/problems/sqrtx/

int mySqrt(int x) {
    if(x <= 0) {
        return 0;
    } else if(x == 1) {
        return 1;
    }
    int a = 0, b = x / 2, c = x, sum;
    while(sum = b * b, sum != x) {
        printf("b = %d\n", b);
        if(sum > x || sum < 0) {
            c = b;
            b = (a + c) / 2;
        } else {
            a = b;
            b = (a + c) / 2;
        }
        if(a == b || b == c)
            break;
        printf("b = %d\n", b);
        getchar();
    }
    return b;
}

void print_integer(int n) { printf("%d\n", n); }

int main(void)
{
    print_integer(mySqrt(4));
    return 0;
}
