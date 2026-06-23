import time

class TokenBucketRateLimiter:
    """Simulating an API Rate Limiter using Token Bucket Concept"""
    def __init__(self, max_tokens, cooldown_period):
        self.max_tokens = max_tokens          # Max capacity of bucket
        self.cooldown_period = cooldown_period # Time in seconds to reset tokens
        self.user_buckets = {}                # Tracks individual user states

    def _get_user_tokens(self, username):
        current_time = time.time()
        
        # If user hits for the first time, initialize bucket
        if username not in self.user_buckets:
            self.user_buckets[username] = {
                "tokens": self.max_tokens,
                "last_check": current_time
            }
            return self.user_buckets[username]

        user_data = self.user_buckets[username]
        elapsed = current_time - user_data["last_check"]

        # If cooldown period has passed, reset/refill the bucket tokens
        if elapsed >= self.cooldown_period:
            user_data["tokens"] = self.max_tokens
            user_data["last_check"] = current_time
            print(f"🔄 [Rate Limiter] Cooldown window reset for @{username}. Bucket Refilled!")

        return user_data

    def allow_request(self, username):
        user_data = self._get_user_tokens(username)

        if user_data["tokens"] > 0:
            user_data["tokens"] -= 1
            print(f"🟢 [ALLOWED] Request processed for @{username}. (Tokens Left: {user_data['tokens']})")
            return True
        else:
            print(f"🔴 [BLOCKED] Rate Limit Exceeded for @{username}! HTTP 429 Too Many Requests.")
            return False

def main():
    print("=" * 50)
    print("   AI System Architecture: API Rate Limiter Engine   ")
    print("=" * 50)

    # Configuration: Max 3 requests allowed, resets every 5 seconds
    limiter = TokenBucketRateLimiter(max_tokens=3, cooldown_period=5)

    print("\n🚀 Simulating rapid continuous hits from @rahul_ibatwar:")
    print("-" * 50)
    
    # Simulating 5 immediate hits back-to-back
    for i in range(1, 6):
        print(f"Hit #{i}:")
        limiter.allow_request("rahul_ibatwar")
        time.sleep(0.1) # Rapid hits

    print("\n⏱️ Pausing traffic for 5 seconds to let the window reset...")
    time.sleep(5)

    print("\n🚀 Simulating fresh hit after cooldown:")
    print("-" * 50)
    limiter.allow_request("rahul_ibatwar")

if __name__ == "__main__":
    main()