#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vect;

    for(int i=0;i<10;i++) {
        vect.push_back(i);
    }

    for(vector<int>::iterator it = vect.begin();it != vect.end();it++) {
        cout << *it << endl;
    }

    cout << "ok" << endl;

    for(int i=0;i<10;i++) {
        cout << vect[i] << endl;
    }

    cout << "ok" << endl;
}
