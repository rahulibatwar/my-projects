import time

class APIGatewayRouter:
    """Simulating an Enterprise API Gateway with Token Bucket Rate Limiting"""
    def __init__(self, bucket_capacity, leak_rate_per_sec):
        self.capacity = bucket_capacity
        self.leak_rate = leak_rate_per_sec
        self.tokens = bucket_capacity
        self.last_check_time = time.time()

    def _refresh_tokens(self):
        """Automatically add new tokens based on time elapsed (Leaky/Token Bucket logic)"""
        current_time = time.time()
        time_passed = current_time - self.last_check_time
        self.last_check_time = current_time
        
        # Adding tokens back proportionally
        new_tokens = time_passed * self.leak_rate
        self.tokens = min(self.capacity, self.tokens + new_tokens)

    def route_request(self, client_ip, endpoint):
        """Process incoming API requests and apply traffic shaping rules"""
        self._refresh_tokens()
        print(f"\n🌐 [Gateway] Incoming request from {client_ip} -> {endpoint}")
        print(f"📊 [Metrics] Available Tokens in Bucket: {self.tokens:.2f}")

        # Core Architecture Rule Check
        if self.tokens >= 1:
            self.tokens -= 1
            print(f"🟢 [200 OK] Request routed successfully to backend handler.")
            return True
        else:
            print(f"🚨 [429 Too Many Requests] Rate limit breached for {client_ip}! Request Dropped.")
            return False

def main():
    print("=" * 50)
    print("   AI Architecture: API Gateway & Traffic Shaper   ")
    print("=" * 50)

    # Initializing gateway: Max 3 requests bursting capacity, refills at 1 token per second
    gateway = APIGatewayRouter(bucket_capacity=3, leak_rate_per_sec=1)
    client_ip = "192.168.1.50"

    # Scenario 1: Fast Burst Traffic (Hacking/Spam simulation)
    print("\n⚡ --- Scenario 1: Simulating High-Speed Burst Traffic ---")
    for i in range(5):
        gateway.route_request(client_ip, f"/api/v1/userData?id={i}")
        time.sleep(0.1) # Super fast hits

    # Scenario 2: Graceful Controlled Traffic (Recovery)
    print("\n⏳ --- Scenario 2: Waiting 2 seconds for Token Bucket to Refill ---")
    time.sleep(2.0)

    print("\n🟢 --- Scenario 3: Retrying Request After Cooldown ---")
    gateway.route_request(client_ip, "/api/v1/userData?id=99")

if __name__ == "__main__":
    main()