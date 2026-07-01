import hashlib
import os
import time

class EnterpriseSecurityEngine:
    """Simulating an Architectural Security Vault with Password Salting & Hashing"""
    def __init__(self):
        # Database structure: Username -> {"salt": user_salt, "hash": user_hash}
        self.password_vault = {} 

    def register_user(self, username, raw_password):
        """Generate a unique salt, append to password, and save the hash"""
        print(f"\n🔐 [Security] Registering user '{username}'...")
        
        # 1. Generate a unique 16-byte random salt for THIS user
        # os.urandom secure tokens generate karta hai jo unpredictable hote hain
        salt = os.urandom(16) 
        
        # 2. Combine raw password with the salt (Salting Phase)
        # Hum password string ko bytes me convert karke salt bytes ke sath jod rahe hain
        salted_password = raw_password.encode('utf-8') + salt
        
        # 3. Hash the combined payload using SHA-256
        secure_hash = hashlib.sha256(salted_password).hexdigest()
        
        # 4. Save BOTH salt and hash in the database
        # Salt ko safe rakhna zaroori hai kyunki login ke waqt iski firse zaroorat padegi
        self.password_vault[username] = {
            "salt": salt,
            "hash": secure_hash
        }
        
        # Hexadecimal presentation for console logging
        print(f"🧂 Salt Generated (Hex): {salt.hex()}")
        print(f"💾 [DB Saved] Saved salted hash for {username}: {secure_hash}")

    def verify_login(self, username, typed_password):
        """Retrieve user's unique salt, apply it to input, and verify"""
        print(f"\n⚡ [Login Attempt] Verifying credentials for '{username}'...")
        
        if username not in self.password_vault:
            print("❌ Access Denied: User not found!")
            return False
            
        # 1. Fetch the stored salt and hash for this specific user
        stored_salt = self.password_vault[username]["salt"]
        stored_hash = self.password_vault[username]["hash"]
        
        # 2. Apply the SAME salt to the currently typed password
        salted_input = typed_password.encode('utf-8') + stored_salt
        
        # 3. Hash this temporary combination
        input_hash = hashlib.sha256(salted_input).hexdigest()
        
        # 4. Compare the newly generated hash with the database hash
        if input_hash == stored_hash:
            print("🟢 Access Granted! Password and cryptographic salt match perfectly.")
            return True
        else:
            print("🚨 SECURITY ALERT: Hashes do not match! Access Blocked.")
            return False

def main():
    print("=" * 60)
    print("   AI Security Architecture: SHA-256 + Salting Engine   ")
    print("=" * 60)

    vault = EnterpriseSecurityEngine()

    # Scenario: Do alag users ne UNIK (Same) password choose kiya
    # Bina salt ke dono ka hash same hota, par ab dekhiye kya hota hai:
    vault.register_user("Rahul_Architect", "Google_Dream_2026")
    time.sleep(0.1)
    vault.register_user("Amit_Coder", "Google_Dream_2026")

    print("\n" + "-"*60 + "\n🔑 Testing Login System\n" + "-"*60)

    # Test Case 1: Rahul logs in with correct password
    vault.verify_login("Rahul_Architect", "Google_Dream_2026")

    # Test Case 2: Hacker tries to use Rahul's password for Amit (or vice versa)
    # Dono ka password same hai phir bhi Amit ke salt se Rahul ka input match nahi karega
    vault.verify_login("Amit_Coder", "Google_Dream_2026")

if __name__ == "__main__":
    main()