import time

class UserAuthService:
    """Simulating an independent User Authentication Microservice"""
    def __init__(self):
        # Master user database simulation
        self.allowed_users = {
            "rahul_ibatwar": {"role": "System Architect Target", "clearance": "Level 3"},
            "test_user": {"role": "Guest", "clearance": "Level 1"}
        }

    def authenticate_user(self, username):
        print(f"[Auth Service] Verifying credentials for: @{username}...")
        time.sleep(1) # Simulating network latency/delay
        
        if username in self.allowed_users:
            return True, self.allowed_users[username]
        return False, None

class ArchitectureEngineGate:
    """Simulating the Core Google-Standard Gateway Router"""
    def __init__(self, auth_service):
        self.auth = auth_service

    def access_advanced_hub(self, username):
        print("\n" + "="*50)
        print("🚀 ENTERING SYSTEM ARCHITECTURE GATEWAY ROUTER")
        print("="*50)
        
        # Calling the independent Auth Microservice
        is_valid, user_data = self.auth.authenticate_user(username)
        
        if is_valid:
            print(f"✅ [Gateway] Access GRANTED to @{username}")
            print(f"🔒 [Security Check] Role Detected: {user_data['role']} | Clearance: {user_data['clearance']}")
            
            # Architect Node Routing Logic
            if user_data['clearance'] == "Level 3":
                print("\n🔥 ROUTING DATA TO: Vizag Hyperscale AI Core Node...")
                print("🧠 Booting Advanced System Architecture Modules... 100% Success!")
            else:
                print("\n⚠️ ROUTING DATA TO: Sandbox Node (Limited Access). Upgrade clearance needed.")
        else:
            print(f"❌ [Gateway] Access DENIED. Security Alert raised for invalid user.")
        print("="*50 + "\n")

def main():
    # Initializing independent services (Microservice Architecture approach)
    auth_microservice = UserAuthService()
    gateway_router = ArchitectureEngineGate(auth_microservice)
    
    # Test Run 1: Your custom profile node routing
    gateway_router.access_advanced_hub("rahul_ibatwar")
    
    # Test Run 2: Guest profiling routing
    gateway_router.access_advanced_hub("test_user")

if __name__ == "__main__":
    main()