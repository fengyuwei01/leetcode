/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// https://leetcode.com/problems/keyboard-row/description/

int hashTable[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};

char** findWords(char** words, int wordsSize, int* returnSize) {
    int i;
    int row,prev_row;
    bool is_one_row;
    char *ptr;
    char **result = (char **)malloc(sizeof(char **));

    prev_row = -1;
    for (i=0; i<wordsSize; i++) {
        ptr= words[i];
        is_one_row = true;
        prev_row = -1;
        while (ptr) {
            if (*ptr >='A' && *ptr <= 'Z') { 
                row = hashTable[*ptr - 'A']; 
            } else {
                row = hastTable[*ptr - 'a'];
            }

            if (prev_row != -1 && row != prev_row) {
               is_one_row = false; 
               break;
            }
            prev_row = row;
        }

        if (is_one_row) {
            returnSize++;
        }
    }
}


