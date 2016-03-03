// https://leetcode.com/problems/add-digits/

class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int temp = 0;
            while(num) {
                temp += num % 10;
                num = num / 10;
            }
            num = temp;
        }
        return num;
    }
};

int addDigits(int num) {
    return 1 + (num - 1) % 9;
}
