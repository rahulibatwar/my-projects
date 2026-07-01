def print_solution(board):
    for row in board:
        print("  " + " ".join(["Q" if x == 1 else "." for x in row]))
    print("-----------------------")

def is_safe(board, row, col, n):
    # Check this row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solve_nq_util(board, col, n):
    # Base Case: All queens are placed
    if col >= n:
        return True

    for i in range(n):
        if is_safe(board, i, col, n):
            # Place queen
            board[i][col] = 1

            # Recur to place rest
            if solve_nq_util(board, col + 1, n):
                return True

            # BACKTRACK
            board[i][col] = 0

    return False

def main():
    print("--- DSA Masterclass: N-Queen Problem (Python) ---\n")
    
    n = 4
    board = [[0] * n for _ in range(n)]

    if not solve_nq_util(board, 0, n):
        print("Solution does not exist")
    else:
        print("One of the valid configurations for 4-Queens (Python):")
        print_solution(board)

if __name__ == "__main__":
    main()