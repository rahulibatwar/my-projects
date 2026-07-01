def is_safe(maze, x, y, n):
    if x >= 0 and x < n and y >= 0 and y < n and maze[x][y] == 1:
        return True
    return False

def solve_maze_util(maze, x, y, sol, n):
    # Base Case
    if x == n - 1 and y == n - 1 and maze[x][y] == 1:
        sol[x][y] = 1
        return True

    if is_safe(maze, x, y, n):
        if sol[x][y] == 1:
            return False

        # Mark tracking point
        sol[x][y] = 1

        # Move Right
        if solve_maze_util(maze, x + 1, y, sol, n):
            return True

        # Move Down
        if solve_maze_util(maze, x, y + 1, sol, n):
            return True

        # BACKTRACK
        sol[x][y] = 0
        return False

    return False

def main():
    print("--- DSA Masterclass: Rat in a Maze (Python) ---\n")

    maze = [
        [1, 0, 0, 0],
        [1, 1, 0, 1],
        [0, 1, 0, 0],
        [1, 1, 1, 1]
    ]
    
    n = len(maze)
    sol = [[0] * n for _ in range(n)]

    if not solve_maze_util(maze, 0, 0, sol, n):
        print("Solution does not exist")
    else:
        print("Final Solution Path Matrix (Python):")
        for row in sol:
            print("  " + " ".join(map(str, row)))

if __name__ == "__main__":
    main()