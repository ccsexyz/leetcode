// https://leetcode.com/problems/reverse-string/

char* reverseString(char* s) {
    if(s != NULL) {
        int length = strlen(s);
        int mid = length / 2;
        for(int i = 0; i < mid; i++) {
            char temp = s[i];
            s[i] = s[length - i - 1];
            s[length - i - 1] = temp;
        }
    }
    return s;
}
