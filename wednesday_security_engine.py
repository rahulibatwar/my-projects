import hashlib
import time

class EnterpriseSecurityEngine:
    """Simulating an Architectural Security Vault for Passwords and Payloads"""
    def __init__(self):
        self.password_vault = {} # Simulated Secure DB Table: Username -> HashedPassword

    def register_user(self, username, raw_password):
        """Securely hash and store the password using SHA-256 protocol"""
        print(f"\n🔐 [Security] Hashing password for user '{username}'...")
        
        # Converting plain text password into safe byte sequence and hashing it
        password_bytes = raw_password.encode('utf-8')
        hashed_object = hashlib.sha256(password_bytes)
        secure_hash = hashed_object.hexdigest()
        
        # Storing only the cryptographic signature, never the raw password!
        self.password_vault[username] = secure_hash
        print(f"💾 [DB Saved] Saved hash for {username}: {secure_hash}")

    def verify_login(self, username, typed_password):
        """Verify password by hashing the input and comparing signatures"""
        print(f"\n⚡ [Login Attempt] Verifying credentials for '{username}'...")
        
        if username not in self.password_vault:
            print("❌ Access Denied: User not found!")
            return False
            
        # Hash the input string to match with stored vault signature
        input_bytes = typed_password.encode('utf-8')
        input_hash = hashlib.sha256(input_bytes).hexdigest()
        
        if input_hash == self.password_vault[username]:
            print("🟢 Access Granted! Cryptographic token verified successfully.")
            return True
        else:
            print("🚨 SECURITY ALERT: Invalid password signature! Access Blocked.")
            return False

def main():
    print("=" * 50)
    print("   AI Security Architecture: Cryptographic Vault   ")
    print("=" * 50)

    vault = EnterpriseSecurityEngine()

    # Step 1: Registering a user securely
    vault.register_user("Rahul_Architect", "Google_Dream_2026")

    # Step 2: Test Case 1 - Logging in with the CORRECT password
    time.sleep(0.5)
    vault.verify_login("Rahul_Architect", "Google_Dream_2026")

    # Step 3: Test Case 2 - Logging in with a WRONG password (Hack attempt)
    time.sleep(0.5)
    vault.verify_login("Rahul_Architect", "Wrong_Password_123")

if __name__ == "__main__":
    main()