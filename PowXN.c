// https://leetcode.com/problems/powx-n/

double myPow(double x, int n) {
    if(n == 0) {
        return 1.0;
    } else if(n < 0) {
        return 1.0 / (myPow(x, -(n + 1)) * x);
    } else {
        double ret = myPow(x, n / 2);
        return ret * ret * ((n & 1) ? x : 1);
    }
}

int main(void)
{
    printf("ret = %lf\n", myPow(1.00000, 2147483647));
    return 0;
}
