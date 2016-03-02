// https://leetcode.com/submissions/detail/55046231/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    if(numRows <= 0 || columnSizes == NULL) return NULL;
    int **ret = malloc(sizeof(int *) * numRows);
    *columnSizes = malloc(sizeof(int) * numRows);
    for(int i = 0; i < numRows; i++) {
        ret[i] = malloc(sizeof(int) * (i + 1));
        (*columnSizes)[i] = i + 1;
    }
    for(int i = 0; i < numRows; i++) {
        switch(i) {
            case 0:
            {
                ret[0][0] = 1;
                break;
            }
            case 1:
            {
                ret[1][0] = ret[1][1] = 1;
                break;
            }
            default:
            {
                ret[i][0] = ret[i][i] = 1;
                for(int j = 1; j < i; j++) {
                    ret[i][j] =  ret[i - 1][j - 1] + ret[i - 1][j];
                }
            }
        }
    }
    return ret;
}
