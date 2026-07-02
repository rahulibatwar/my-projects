#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Database ke operation ko track karne ke liye ek Structure
struct DBOperation {
    string queryType;     // jaise INSERT, UPDATE
    string tableName;     // jis table par query chali
    string rollbackQuery; // Uss change ko ulta (reverse) karne ki command
};

int main() {
    cout << "=== ENTERPRISE DBMS TRANSACTION LOG (STL Stack) ===" << endl;
    
    // DBOperation store karne ke liye ek stack banaya
    stack<DBOperation> transactionStack;

    // 1. Transaction shuru hua aur alag-alag queries execute hui
    transactionStack.push({"INSERT", "users", "DELETE FROM users WHERE id = 101;"});
    transactionStack.push({"UPDATE", "accounts", "UPDATE accounts SET balance = 5000 WHERE id = 101;"});
    transactionStack.push({"INSERT", "orders", "DELETE FROM orders WHERE order_id = 9002;"});

    cout << "[STATUS] Transaction running. " << transactionStack.size() << " operations logged to stack.\n\n";

    // 2. Oh no! System mein constraint violation ya server error aaya!
    cout << "[CRITICAL ERROR] Database Constraint Violated! Aborting transaction...\n";
    cout << "Initiating LIFO Rollback Sequence to protect data integrity:\n\n";

    // 3. Stack se ek-ek karke reverse order mein data rollback karna
    while (!transactionStack.empty()) {
        // .top() hamesha sabse aakhri (latest) operation nikal kar dega
        DBOperation lastOp = transactionStack.top();
        
        cout << "  [ROLLBACK] Reversing " << lastOp.queryType << " on table [" << lastOp.tableName << "]\n";
        cout << "             Executing Counter-Command: " << lastOp.rollbackQuery << "\n\n";
        
        // Operation reverse hone ke baad use stack se hata (pop) dete hain
        transactionStack.pop();
    }

    cout << "---------------------------------------------------------\n";
    cout << "[SUCCESS] Database state restored safely. Transaction completely rolled back!\n";

    return 0;
}