import sys

def greedy_max_cities(cities, budget):
    # Sort cities by cost (Low to High) - Greedy Choice
    sorted_cities = sorted(cities, key=lambda x: x['cost'])
    
    selected = []
    total_cost = 0
    
    for city in sorted_cities:
        if total_cost + city['cost'] <= budget:
            selected.append(city)
            total_cost += city['cost']
            
    return selected, total_cost

def dp_optimized_tour(cities, budget):
    n = len(cities)
    # DP Matrix initialization
    dp = [[0 for _ in range(budget + 1)] for _ in range(n + 1)]
    
    # Build DP Table
    for i in range(1, n + 1):
        for w in range(1, budget + 1):
            cost = cities[i-1]['cost']
            value = cities[i-1]['rating']
            
            if cost <= w:
                dp[i][w] = max(value + dp[i-1][w-cost], dp[i-1][w])
            else:
                dp[i][w] = dp[i-1][w]
                
    # Backtracking to find selected cities
    w = budget
    selected = []
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i-1][w]:
            selected.append(cities[i-1])
            w -= cities[i-1]['cost']
            
    return selected, dp[n][budget]

def main():
    print("=" * 50)
    print("   Welcome to AI Smart Tour Planner Engine   ")
    print("=" * 50)
    
    # Hardcoded master data of cities
    cities = [
        {"name": "Hyderabad", "cost": 8000, "rating": 9},
        {"name": "Bangalore", "cost": 12000, "rating": 8},
        {"name": "Chennai", "cost": 7000, "rating": 7},
        {"name": "Mumbai", "cost": 15000, "rating": 9},
        {"name": "Pune", "cost": 6000, "rating": 8}
    ]
    
    print("\nAvailable Destinations:")
    for c in cities:
        print(f" - {c['name']}: Cost = ₹{c['cost']} | Tourist Rating = {c['rating']}/10")
        
    try:
        budget = int(input("\nEnter your total travel budget (₹): "))
    except ValueError:
        print("Invalid budget amount. Exiting.")
        return

    print("\n" + "-"*40)
    print("CHOOSE YOUR OPTIMIZATION STRATEGY:")
    print("1. Maximize Number of Cities (Greedy Engine)")
    print("2. Maximize Trip Quality Rating (DP Knapsack Engine)")
    print("-"*40)
    
    choice = input("Enter choice (1 or 2): ")
    
    if choice == '1':
        selected, total = greedy_max_cities(cities, budget)
        print(f"\n⚡ [Greedy Results] Budget utilized: ₹{total} out of ₹{budget}")
        print(f"Total Cities Planned: {len(selected)}")
        print("Itinerary Path:")
        for idx, c in enumerate(selected, 1):
            print(f"  {idx}. {c['name']} (Cost: ₹{c['cost']})")
            
    elif choice == '2':
        selected, max_val = dp_optimized_tour(cities, budget)
        total_cost = sum(c['cost'] for c in selected)
        print(f"\n🧠 [DP Results] Total Experience Value: {max_val} Points")
        print(f"Budget spent: ₹{total_cost} out of ₹{budget}")
        print("Premium Selection:")
        for idx, c in enumerate(selected, 1):
            print(f"  {idx}. {c['name']} [Rating: {c['rating']}/10] (Cost: ₹{c['cost']})")
    else:
        print("Invalid Selection!")

if __name__ == "__main__":
    main()