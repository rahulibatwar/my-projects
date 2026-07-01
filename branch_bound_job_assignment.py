import sys

def assign_jobs(cost_matrix, person, current_cost, job_assigned, current_assignment, state, n):
    # Base Case
    if person == n:
        if current_cost < state["min_cost"]:
            state["min_cost"] = current_cost
            state["best_assignment"] = list(current_assignment)
        return

    # Branching & Bounding loop
    for job in range(n):
        if not job_assigned[job]:
            # Bound condition check
            if current_cost + cost_matrix[person][job] < state["min_cost"]:
                
                job_assigned[job] = True
                current_assignment[person] = job

                # Recurse for next person
                assign_jobs(cost_matrix, person + 1, current_cost + cost_matrix[person][job], job_assigned, current_assignment, state, n)

                # Reset state
                job_assigned[job] = False
                current_assignment[person] = -1

def main():
    print("--- DSA Masterclass: Job Assignment using Branch & Bound (Python) ---\n")

    cost_matrix = [
        [9, 2, 7, 8],
        [6, 4, 3, 7],
        [5, 8, 1, 8],
        [7, 6, 9, 4]
    ]
    
    n = len(cost_matrix)
    job_assigned = [False] * n
    current_assignment = [-1] * n
    
    state = {
        "min_cost": sys.maxsize,
        "best_assignment": [-1] * n
    }

    assign_jobs(cost_matrix, 0, 0, job_assigned, current_assignment, state, n)

    print("Optimal Job Allocation Mapping (Python):")
    for i in range(n):
        assigned_job = state["best_assignment"][i]
        print(f"  Person {i} -> assigned to Job {assigned_job} (Cost: {cost_matrix[i][assigned_job]})")
    print("---------------------------------")
    print(f"Minimum Total Safe Cost: {state['min_cost']}\n")

if __name__ == "__main__":
    main()