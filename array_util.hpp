#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<vector<int> > &arr,int m,int n) {
    std::cout << std::endl;
    std::cout << "---------------------arr-------------------" << std::endl;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void printArray(vector<int> &arr,int m) {
    std::cout << std::endl;
    std::cout << "---------------------arr-------------------" << std::endl;
    for (int i=0;i<m;i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
}
