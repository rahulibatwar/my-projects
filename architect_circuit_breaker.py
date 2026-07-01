import time

class ExternalServiceSIM:
    """Simulating an unstable external API or Server Node"""
    def __init__(self):
        self.is_broken = True # Setting service down intentionally

    def call_api(self):
        if self.is_broken:
            raise Exception("503 Service Unavailable (Internal Node Crash)")
        return "Success: Data fetched from remote service."

class CircuitBreaker:
    """Architectural Guard Engine to protect system from cascading failures"""
    def __init__(self, service, failure_threshold=3, recovery_time=4):
        self.service = service
        self.failure_threshold = failure_threshold # Max failures before tripping
        self.recovery_time = recovery_time         # Cooldown before testing recovery
        
        self.state = "CLOSED"                      # Initial safe state
        self.failure_count = 0
        self.last_failure_time = None

    def execute_request(self):
        current_time = time.time()

        # Step 1: Check if Circuit is OPEN and ready to test recovery (HALF-OPEN)
        if self.state == "OPEN":
            if current_time - self.last_failure_time >= self.recovery_time:
                self.state = "HALF-OPEN"
                print("\n🟡 [CIRCUIT: HALF-OPEN] Testing a sample request to see if service recovered...")
            else:
                print("\n🔴 [CIRCUIT: OPEN] Request BLOCKED locally. Returning fallback cached data.")
                return "Fallback Data: System operational but features limited."

        # Step 2: Attempting the actual remote call
        try:
            print(f"\n⚡ [Circuit: {self.state}] Sending request to remote service...")
            response = self.service.call_api()
            
            # If successful in HALF-OPEN state, close the circuit
            if self.state == "HALF-OPEN":
                print("🟢 [CIRCUIT: CLOSED] Service recovered fully! Resetting counters.")
                self.state = "CLOSED"
                self.failure_count = 0
            return response

        except Exception as e:
            self.failure_count += 1
            self.last_failure_time = current_time
            print(f"❌ Failure Detected! (Count: {self.failure_count}/{self.failure_threshold}) | Reason: {e}")

            # Trip the circuit if threshold crossed
            if self.failure_count >= self.failure_threshold and self.state != "OPEN":
                self.state = "OPEN"
                print("🚨 [CIRCUIT TRIPPED: OPEN] Threshold breached! Isolating broken service node.")

            return "Fallback Data: Node error handled safely."

def main():
    print("=" * 50)
    print("  AI System Architecture: Circuit Breaker Simulator ")
    print("=" * 50)

    remote_node = ExternalServiceSIM()
    breaker = CircuitBreaker(remote_node, failure_threshold=3, recovery_time=4)

    # Simulating 4 consecutive rapid requests to trip the circuit
    print("\n--- Phase 1: Heavy Failures Triggering ---")
    for i in range(4):
        breaker.execute_request()
        time.sleep(0.1)

    # Simulating request while circuit is completely OPEN
    print("\n--- Phase 2: Instant Fallback While Open ---")
    breaker.execute_request()

    # Simulating system healing after cooldown recovery time passes
    print(f"\n⏱️  Waiting {breaker.recovery_time} seconds for cooldown window...")
    time.sleep(breaker.recovery_time)

    print("\n--- Phase 3: Testing Recovery ---")
    # Heal the service node right before testing half-open state
    remote_node.is_broken = False
    breaker.execute_request()

if __name__ == "__main__":
    main()