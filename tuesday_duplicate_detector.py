import time

class FraudDetectionEngine:
    """Architectural Data Optimization for Duplicate Log Detection"""

    def check_duplicate_basic(self, logs):
        """Basic Approach: Nested Loops - O(n^2) Time Complexity"""
        print("🐢 Scanning logs using Basic Brute-Force...")
        for i in range(len(logs)):
            for j in range(i + 1, len(logs)):
                if logs[i] == logs[j]:
                    return True # Duplicate found
        return False

    def check_duplicate_advanced(self, logs):
        """Advanced Approach: Hash Set Lookup Layer - O(n) Time Complexity"""
        print("⚡ Scanning logs using Advanced Hash Set Layer...")
        seen_logs = set() # High-speed memory storage for unique tracking
        
        for log in logs:
            # Instant memory check
            if log in seen_logs:
                return True
            seen_logs.add(log)
        return False

def main():
    print("=" * 50)
    print("   AI Coding Challenge: Duplicate Fraud Detector   ")
    print("=" * 50)

    # Creating a large dummy log list (1 to 8000 unique ids, and one duplicate at the very end)
    print("📦 Generating 8000 Network Transaction Logs...")
    large_logs = list(range(8000))
    large_logs.append(4500) # Injecting a duplicate fraud ID deliberately

    engine = FraudDetectionEngine()

    # Test 1: Basic Scan Timing
    start_time = time.time()
    basic_res = engine.check_duplicate_basic(large_logs)
    basic_time = (time.time() - start_time) * 1000
    print(f"🎯 Fraud Detected: {basic_res} | Scan Time: {basic_time:.2f} ms\n")

    # Test 2: Advanced Architect Scan Timing
    start_time = time.time()
    advanced_res = engine.check_duplicate_advanced(large_logs)
    advanced_time = (time.time() - start_time) * 1000
    print(f"🎯 Fraud Detected: {advanced_res} | Scan Time: {advanced_time:.2f} ms\n")

    print("-" * 50)
    if advanced_time > 0:
        speedup = basic_time / advanced_time
        print(f"🚀 Advanced Hash Architecture is {speedup:.1f}x times FASTER!")

if __name__ == "__main__":
    main()