#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode* prev = dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }

                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }

        ListNode* sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }
};

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    cout << "[ ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    ListNode* list1 = createList({4, 2, 1, 3});
    ListNode* sorted1 = sol.insertionSortList(list1);
    cout << "Example 1 Output: ";
    printList(sorted1); // Expected: [ 1 2 3 4 ]

    ListNode* list2 = createList({-1, 5, 3, 4, 0});
    ListNode* sorted2 = sol.insertionSortList(list2);
    cout << "Example 2 Output: ";
    printList(sorted2); // Expected: [ -1 0 3 4 5 ]

    return 0;
}