#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// लोकल टेस्टिंग के लिए NestedInteger का Mock Implementation
class NestedInteger {
private:
    bool is_int;
    int val;
    vector<NestedInteger> list;

public:
    NestedInteger(int value) : is_int(true), val(value) {}
    NestedInteger(vector<NestedInteger> nestedList) : is_int(false), val(0), list(nestedList) {}

    bool isInteger() const {
        return is_int;
    }

    int getInteger() const {
        return val;
    }

    const vector<NestedInteger>& getList() const {
        return list;
    }
};

class NestedIterator {
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        hasNext();
        int val = st.top().getInteger();
        st.pop();
        return val;
    }
    
    bool hasNext() {
        while (!st.empty()) {
            if (st.top().isInteger()) {
                return true;
            }
            vector<NestedInteger> currList = st.top().getList();
            st.pop();
            for (int i = currList.size() - 1; i >= 0; i--) {
                st.push(currList[i]);
            }
        }
        return false;
    }
};

int main() {
    // Example 1: [[1,1], 2, [1,1]][cite: 28]
    vector<NestedInteger> list1 = {
        NestedInteger({NestedInteger(1), NestedInteger(1)}),
        NestedInteger(2),
        NestedInteger({NestedInteger(1), NestedInteger(1)})
    };

    NestedIterator it1(list1);
    cout << "Example 1 Output: [ ";
    while (it1.hasNext()) {
        cout << it1.next() << " ";
    }
    cout << "] (Expected: [ 1 1 2 1 1 ])\n"; //[cite: 28]

    // Example 2: [1, [4, [6]]][cite: 28]
    vector<NestedInteger> list2 = {
        NestedInteger(1),
        NestedInteger({
            NestedInteger(4),
            NestedInteger({NestedInteger(6)})
        })
    };

    NestedIterator it2(list2);
    cout << "Example 2 Output: [ ";
    while (it2.hasNext()) {
        cout << it2.next() << " ";
    }
    cout << "] (Expected: [ 1 4 6 ])\n"; //[cite: 28]

    return 0;
}