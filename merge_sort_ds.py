# Function to perform Merge Sort on an array
def merge_sort(arr):
    if len(arr) > 1:
        # Find the middle point to divide the array into two halves
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        # Recursively sort the left and right halves
        merge_sort(left_half)
        merge_sort(right_half)

        # Iterators for traversing the halves and main array
        i = j = k = 0

        # Merge the temporary arrays back into arr[]
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Check if any element was left in the left_half
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        # Check if any element was left in the right_half
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1


# --- Main Driver Code ---
if __name__ == "__main__":
    test_array = [38, 27, 43, 3, 9, 82, 10]
    
    print("--- Merge Sort Demonstration ---")
    print("Original Array:", test_array)
    
    merge_sort(test_array)
    
    print("Sorted Array:  ", test_array)