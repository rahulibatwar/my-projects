import time

class DatabaseLedger:
    """Simulating an Enterprise Database Engine with Commit/Rollback Security"""
    def __init__(self):
        # Actual live data inside the database
        self.live_storage = {"Rahul_Balance": 5000, "Amit_Balance": 1500}
        self.staging_buffer = {} # Temporary layer to hold data during verification
        self.is_transaction_active = False

    def start_transaction(self):
        self.is_transaction_active = True
        # Create a safe snapshot of live data into staging buffer
        self.staging_buffer = self.live_storage.copy()
        print("\n🏁 [Database] Transaction Started. Safe memory snapshot created.")

    def update_balance(self, user, amount):
        if not self.is_transaction_active:
            print("❌ Error: No active transaction! Start a transaction first.")
            return
        
        print(f"✍️  [Staging] Updating {user}'s balance to {amount}...")
        self.staging_buffer[user] = amount

    def commit(self):
        """If everything is successful, permanently save staging data to live storage"""
        if not self.is_transaction_active:
            return
        
        print("💾 [COMMIT] All checks passed! Permanently writing data to disk...")
        self.live_storage = self.staging_buffer.copy()
        self.is_transaction_active = False
        print(f"🟢 Live Storage Status: {self.live_storage}")

    def rollback(self):
        """If any error occurs, wipe out staging changes and recover original state"""
        if not self.is_transaction_active:
            return
        
        print("🚨 [ROLLBACK] Critical system crash detected mid-way!")
        print("🔄 Wiping out staging memory and recovering original state safely...")
        self.staging_buffer.clear()
        self.is_transaction_active = False
        print(f"🛡️  System Recovered! Safe Live Storage Status: {self.live_storage}")


def main():
    print("=" * 50)
    print("   AI System Architecture: ACID Transaction Engine   ")
    print("=" * 50)

    db = DatabaseLedger()
    print(f"Initial State: {db.live_storage}")

    # Case 1: Perfect Transaction (Successful Commit)
    print("\n--- Scenario 1: Processing Valid Money Transfer ---")
    db.start_transaction()
    db.update_balance("Rahul_Balance", 4000)
    db.update_balance("Amit_Balance", 2500)
    time.sleep(0.5)
    db.commit()

    # Case 2: System Crash mid-way (Automated Rollback Safeguard)
    print("\n--- Scenario 2: Processing Failure (Crash Mid-Way) ---")
    db.start_transaction()
    db.update_balance("Rahul_Balance", 99999) # Updated in staging
    
    # Simulating a sudden hardware/network crash right before updating Amit's account
    print("💥 CRITICAL ERROR: Network dropped! Connection timed out.")
    time.sleep(0.5)
    
    # Triggering the architect safety rollback protocol
    db.rollback()

if __name__ == "__main__":
    main()