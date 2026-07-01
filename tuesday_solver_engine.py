import time

class HighSpeedSearchEngine:
    """Architectural Data Structure Optimization for Target Searches"""
    
    def find_target_pair_basic(self, nums, target):
        """Basic Approach: Double Loop (Brute Force) - O(n^2) Speed"""
        print("🐢 Running Basic Search (Double Loop)...")
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []

    def find_target_pair_advanced(self, nums, target):
        """Advanced Approach: Hash Map (Memory Lookup) - O(n) Speed"""
        print("⚡ Running Advanced Architect Search (Hash Map Layer)...")
        visited_elements = {} # Value -> Index mapping cache
        
        for current_index, current_num in enumerate(nums):
            required_num = target - current_num
            
            # Instant memory check (O(1) average lookup time)
            if required_num in visited_elements:
                return [visited_elements[required_num], current_index]
            
            # Store the current number and its index in cache
            visited_elements[current_num] = current_index
        return []

def main():
    print("=" * 50)
    print("   AI Coding Challenge: Optimized Array Search   ")
    print("=" * 50)

    # Creating a large dummy dataset to see the timing difference
    # Target is to find pairs that sum up to 19,999
    huge_dataset = list(range(10000))
    target_sum = 19997
    
    engine = HighSpeedSearchEngine()

    # Test 1: Basic Approach Timing
    start_time = time.time()
    basic_result = engine.find_target_pair_basic(huge_dataset, target_sum)
    basic_time = (time.time() - start_time) * 1000
    print(f"🎯 Basic Result Indices: {basic_result} | Time Taken: {basic_time:.2f} ms\n")

    # Test 2: Advanced Architect Approach Timing
    start_time = time.time()
    advanced_result = engine.find_target_pair_advanced(huge_dataset, target_sum)
    advanced_time = (time.time() - start_time) * 1000
    print(f"🎯 Advanced Result Indices: {advanced_result} | Time Taken: {advanced_time:.2f} ms\n")
    
    print("-" * 50)
    if advanced_time > 0:
        speedup = basic_time / advanced_time
        print(f"🚀 Advanced Architecture is {speedup:.1f}x times FASTER than Basic code!")

if __name__ == "__main__":
    main()