// https://leetcode.com/problems/power-of-four/

bool isPowerOfFour(int num) {
    if (num < 0)
        return false;
    while (num > 1) {
        if (num % 4 != 0) {
            return false;
        } else {
            num /= 4;
        }
    }
    return num == 1;
}

// 别人家的解法
bool isPowerOfFour(int num) {
    return num > 0 && num == (num & 1431655765) && !(num & (num - 1));
}
