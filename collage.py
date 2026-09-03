# Initial Accounts Data
accounts = {
    101: {"name": "rahul", "balance": 10000},
    102: {"name": "sneha", "balance": 15000}
}

print("--- Initial Balances ---")
for accno, info in accounts.items():
    print(f"Account: {accno} | Name: {info['name']} | Balance: {info['balance']}")
try:
    # 1. Deduct 5000 from 101
    accounts[101]["balance"] -= 5000

    # 2. Create SAVEPOINT sp1 
    sp1 = {k: v["balance"] for k, v in accounts.items()}

    # 3. Add 5000 to 102
    accounts[102]["balance"] += 5000

    # 4. ROLLBACK TO SAVEPOINT sp1 
    for k in accounts:
        accounts[k]["balance"] = sp1[k]

    # 5. COMMIT (success)
    print("\nTransaction committed successfully!")

except Exception as e:
    print(f"\nTransaction failed: {e}")

# Final Result
print("\n--- Final Balances ---")
for accno, info in accounts.items():
    print(f"Account: {accno} | Name: {info['name']} | Balance: {info['balance']}")