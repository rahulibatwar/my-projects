def subset_sum_util(numbers, target, current_subset, index, current_sum):
    # Base Case: Target achieved
    if current_sum == target:
        print(f"  {{ " + " ".join(map(str, current_subset)) + " }}")
        return

    # Loop through the numbers array
    for i in range(index, len(numbers)):
        if current_sum + numbers[i] <= target:
            
            # Action: Include number
            current_subset.append(numbers[i])

            # Recurse
            subset_sum_util(numbers, target, current_subset, i + 1, current_sum + numbers[i])

            # Backtrack
            current_subset.pop()

def main():
    print("--- DSA Masterclass: Subset Sum Problem (Python) ---\n")
    
    numbers = [10, 7, 5, 18, 12, 20]
    target = 35
    
    print(f"Target Sum: {target}")
    print(f"Subsets that sum up to {target} are:")
    print("------------------------------------------")
    subset_sum_util(numbers, target, [], 0, 0)
    print("------------------------------------------")

if __name__ == "__main__":
    main()