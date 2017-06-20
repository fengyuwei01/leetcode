#include<vector>
#include<iostream>

// https://leetcode.com/problems/flatten-nested-list-iterator/#/description

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedInteger {
    private:
        vector<NestedInteger> list; // 存储 
        int value;
        bool isInt;
    public:
        // 构造函数
        NestedInteger(int v);
        NestedInteger(vector<int> &values);
        // 不能修改成员变量
        bool isInteger() const;
        int getInteger() const;

        const vector<NestedInteger> &getList() const;
};

NestedInteger::NestedInteger(int v) {
    isInt = true;
    value = v;
}
NestedInteger::NestedInteger(vector<int> &values) {
    isInt = false;
    for (int i=0;i<values.size();i++) {
        list.push_back(NestedInteger(values[i]));
    }
}

bool NestedInteger::isInteger() const{
    return isInt;
}

int NestedInteger::getInteger() const{
    return value;
}

const vector<NestedInteger> &NestedInteger::getList() const{
    return list;
}


class NestedIterator {
    private:
        vector<int> iteratorList;
        vector<int>::iterator iterator;

        void dfs_recursion(NestedInteger &nested) {
            if (nested.isInteger()){
                iteratorList.push_back(nested.getInteger());
            } else {
                vector<NestedInteger> nestedList = nested.getList();
                for (int i=0;i<nestedList.size();i++) {
                    dfs_recursion(nestedList[i]);
                }
            }
        }
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            // 先用递归的方式访问
            for (int i=0;i<nestedList.size();i++) {
                dfs_recursion(nestedList[i]);
            }
            iterator = iteratorList.begin();
        }

        int next() {
            return *(iterator++);
        }

        bool hasNext() {
            return iterator != iteratorList.end();
        }
};

int main() {
    cout << "hello world" << endl;
    
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
