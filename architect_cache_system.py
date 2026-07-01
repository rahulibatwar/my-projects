import time

class DatabaseSIM:
    """Simulating the main heavy Database containing user records"""
    def __init__(self):
        self.db_records = {
            "vizag_node_status": "Active - 98% Efficiency",
            "hyderabad_core_load": "Normal - 45% Traffic",
            "bangalore_edge_latency": "5ms - Optimal"
        }

    def fetch_from_db(self, query_key):
        # Simulating slow database disk read delay
        print(f"🗄️ [Main Database] Querying disk space for '{query_key}'...")
        time.sleep(2.5) 
        return self.db_records.get(query_key, "Record Not Found")

class SmartCacheEngine:
    """Architectural High-Speed In-Memory Cache System"""
    def __init__(self, database):
        self.db = database
        self.cache_store = {}  # In-memory RAM storage simulation

    def process_request(self, query_key):
        print(f"\n⚡ [Cache Engine] Incoming request for: '{query_key}'")
        start_time = time.time()

        # Step 1: Check in high-speed Cache
        if query_key in self.cache_store:
            print(f"🎯 [CACHE HIT] Found instantly in memory layer!")
            result = self.cache_store[query_key]
            time_taken = (time.time() - start_time) * 1000
            print(f"⏱️ Execution Speed: {time_taken:.2f} ms")
            return result

        # Step 2: Cache Miss -> Fetch from slow database
        print(f"❌ [CACHE MISS] Data not in memory layer. Routing to database...")
        result = self.db.fetch_from_db(query_key)
        
        # Step 3: Populate Cache for future requests
        if result != "Record Not Found":
            self.cache_store[query_key] = result
            print(f"📥 [Cache Update] Stored '{query_key}' into memory for future requests.")

        time_taken = (time.time() - start_time) * 1000
        print(f"⏱️ Execution Speed: {time_taken:.2f} ms")
        return result

def main():
    print("=" * 50)
    print("   AI System Architecture: High-Speed Cache Engine   ")
    print("=" * 50)

    db = DatabaseSIM()
    cache_system = SmartCacheEngine(db)

    # Request 1: First time accessing Vizag status (Cache Miss -> Slow)
    print("\n--- FIRST REQUEST TIMING ---")
    cache_system.process_request("vizag_node_status")

    # Request 2: Second time accessing same data (Cache Hit -> Ultra Fast!)
    print("\n--- SECOND REQUEST TIMING (SAME DATA) ---")
    cache_system.process_request("vizag_node_status")

    # Request 3: Accessing Hyderabad status (Cache Miss -> Slow)
    print("\n--- THIRD REQUEST TIMING (NEW DATA) ---")
    cache_system.process_request("hyderabad_core_load")

if __name__ == "__main__":
    main()