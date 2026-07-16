# Function to partition the array based on a pivot
def partition(arr, low, high):
    # Choosing the rightmost element as the pivot
    pivot = arr[high]
    i = low - 1  # Index of the smaller element

    for j in range(low, high):
        # If the current element is smaller than or equal to the pivot
        if arr[j] <= pivot:
            i += 1
            # Swap elements
            arr[i], arr[j] = arr[j], arr[i]

    # Swap the pivot element with the element at i + 1
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# Main Quick Sort function
def quick_sort(arr, low, high):
    if low < high:
        # pi is the partitioning index
        pi = partition(arr, low, high)

        # Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


# --- Main Driver Code ---
if __name__ == "__main__":
    test_array = [10, 80, 30, 90, 40, 50, 70]
    
    print("--- Quick Sort Demonstration ---")
    print("Original Array:", test_array)
    
    # Run Quick Sort on the entire array
    quick_sort(test_array, 0, len(test_array) - 1)
    
    print("Sorted Array:  ", test_array)