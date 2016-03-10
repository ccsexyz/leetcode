// https://leetcode.com/problems/interleaving-string/

// c++

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<int> v((s1.length() + 1) * (s2.length() + 1), -1);
        function<bool(int l1, int l2, int l3)> f;
        auto get = [&](int l1, int l2) -> int & {
            return v[l1 * (s2.length() + 1) + l2];
        };
        f = [&](int l1, int l2, int l3) -> bool {
            if (l1 == s1.length() && l2 == s2.length()) {
                if (l3 == s3.length())
                    return true;
                else
                    return false;
            } else if (l1 == s1.length())
                return (s2.substr(l2, s2.length() - l2) ==
                        s3.substr(l3, s3.length() - l3));
            else if (l2 == s2.length())
                return (s1.substr(l1, s1.length() - l1) ==
                        s3.substr(l3, s3.length() - l3));
            auto r = get(l1, l2);
            if (r != -1)
                return r;
            if (s1[l1] == s3[l3]) {
                if (s2[l2] == s3[l3]) {
                    auto r1 = get(l1, l2 + 1);
                    auto r2 = get(l1 + 1, l2);
                    r1 = f(l1, l2 + 1, l3 + 1);
                    r2 = f(l1 + 1, l2, l3 + 1);
                    if (r1 || r2)
                        return true;
                    else
                        return false;
                } else {
                    return get(l1, l2) = f(l1 + 1, l2, l3 + 1);
                }
            } else if (s2[l2] == s3[l3]) {
                return get(l1, l3) = f(l1, l2 + 1, l3 + 1);
            } else {
                return get(l1, l2) = false;
            }
        };
        return f(0, 0, 0);
    }
};

// c

int s1size = -1;
int s2size = -1;
int *ans = NULL;
char *s1_copy = NULL;
char *s2_copy = NULL;

bool isInterleaveIter(char *s1, char *s2, char *s3) {
    if (ans == NULL) {
        s1size = strlen(s1) + 1;
        s2size = strlen(s2) + 1;
        int size = s1size * s2size;
        ans = malloc(sizeof(int) * (size)*2);
        for (int i = 0; i < size; i++) {
            ans[i] = -1;
        }
        s1_copy = s1;
        s2_copy = s2;
    }
    if (*s1 == *s2 && *s2 == *s3 && *s3 == 0) {
        return true;
    }
    int l1 = s1 - s1_copy;
    int l2 = s2 - s2_copy;
    if (ans[l1 * s2size + l2] != -1) {
        return ans[l1 * s2size + l2];
    }
    if (*s1 == *s3) {
        if (*s2 == *s3) {
            bool a = isInterleaveIter(s1, s2 + 1, s3 + 1);
            bool b = isInterleaveIter(s1 + 1, s2, s3 + 1);
            ans[l1 * s2size + l2 + 1] = a;
            ans[(l1 + 1) * s2size + l2] = b;
            if (a || b)
                return ans[l1 * s2size + l2] = true;
            else
                return ans[l1 * s2size + l2] = false;
        } else {
            return ans[l1 * s2size + l2] = isInterleaveIter(s1 + 1, s2, s3 + 1);
        }
    } else if (*s2 == *s3) {
        return ans[l1 * s2size + l2] = isInterleaveIter(s1, s2 + 1, s3 + 1);
    } else {
        return ans[l1 * s2size + l2] = false;
    }
}

bool isInterleave(char *s1, char *s2, char *s3) {
    s1size = -1;
    s2size = -1;
    ans = NULL;
    s1_copy = NULL;
    s2_copy = NULL;
    return isInterleaveIter(s1, s2, s3);
}
