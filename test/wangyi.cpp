#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool iter_func(int nums[],int size,vector<int> &vect) {
    int i;
    for(i = 0;i<size;i++) {
       vect.push_back(nums[i]); 
       reverse(vect.begin(), vect.end());
    }
    return true;
}

int main() {
    int nums[] = {1,2,3,4};
    vector<int> r; 
    iter_func(nums,4,r);     
    for (int i=0;i<4;i++) {
        cout << r[i] << endl;
    }
}
