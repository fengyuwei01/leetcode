// https://leetcode.com/problems/different-ways-to-add-parentheses/description/

#include <vector>
#include <string>
#include "ctype.h"

using std::vector;
using std::string;

bool _string_is_digit(const string ex,int left,int right,int *value) {
    int i;
    *value = 0;
    for (i=left;i<=right;i++) {
        if (!isdigit(ex[i])) {
            return false;
        }
        *value = (*value) * 10 + (ex[i] - '0');
    }
    return true;
}

vector<int> _diff_ways_to_compute(string ex,int left,int right) {
    vector<int> vect,vect1,vect2;
    vector<int>::iterator iter1,iter2;
    int i,value;
    if (_string_is_digit(ex,left,right,&value)) {
        // base case
        vect.push_back(value);
        return vect;
    } else {
       for (i=left;i<=right;i++) {
            if (ex[i] == '+') {
                vect1 = _diff_ways_to_compute(ex,left,i-1); 
                vect2 = _diff_ways_to_compute(ex,i+1,right);

                for (iter1 = vect1.begin();iter1 != vect1.end();iter1++) {
                    for (iter2 = vect2.begin();iter2 != vect2.end();iter2++) {
                        vect.push_back((*iter1)+(*iter2));
                    }
                }
            } else if (ex[i] == '-') {
                vect1 = _diff_ways_to_compute(ex,left,i-1); 
                vect2 = _diff_ways_to_compute(ex,i+1,right);

                for (iter1 = vect1.begin();iter1 != vect1.end();iter1++) {
                    for (iter2 = vect2.begin();iter2 != vect2.end();iter2++) {
                        vect.push_back((*iter1)-(*iter2));
                    }
                }
            } else if (ex[i] == '*') {
                vect1 = _diff_ways_to_compute(ex,left,i-1); 
                vect2 = _diff_ways_to_compute(ex,i+1,right);

                for (iter1 = vect1.begin();iter1 != vect1.end();iter1++) {
                    for (iter2 = vect2.begin();iter2 != vect2.end();iter2++) {
                        vect.push_back((*iter1)*(*iter2));
                    }
                }
            }
       }

       return vect;
    }
}

vector<int> diffWaysToCompute(string input) {
    return _diff_ways_to_compute(input,0,input.size()-1);
}
