// https://leetcode.com/problems/valid-anagram/

bool isAnagram(char* s, char* t) {
    int keys[26] = {0};
    while(*s) {
        keys[*s++ - 'a']++;
    }
    while(*t) {
        keys[*t++ - 'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if(keys[i] != 0) {
            return false;
        }
    }
    return true;
}
