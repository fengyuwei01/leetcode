// https://leetcode.com/problems/keyboard-row/description/
class Solution {
    public:
    int hashTable[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
    vector<string> findWords(vector<string>& words) {

        int i,j;
        int row,prev_row;
        bool is_one_row;
        string word;
        vector<string> result;

        for (i=0; i<words.size(); i++) {
            word= words[i];
            is_one_row = true;
            prev_row = -1;
            for (j=0;j<word.size();j++) {
                if (word[j] >='A' && word[j] <= 'Z') {
                    row = hashTable[word[j] - 'A'];
                } else {
                    row = hashTable[word[j] - 'a'];
                }

                if (prev_row != -1 && row != prev_row) {
                    is_one_row = false;
                    break;
                }
                prev_row = row;
            }

            if (is_one_row) {
                result.push_back(word);
            }
        }

        return result;
    }
};
