def is_safe(v, graph, color, c, num_vertices):
    # Check if any adjacent vertex has the same color
    for i in range(num_vertices):
        if graph[v][i] == 1 and color[i] == c:
            return False
    return True

def graph_coloring_util(graph, m, color, v, num_vertices):
    # Base Case: All vertices are colored
    if v == num_vertices:
        return True

    # Try different colors for vertex v
    for c in range(1, m + 1):
        if is_safe(v, graph, color, c, num_vertices):
            color[v] = c
            
            # Recur to color rest of the vertices
            if graph_coloring_util(graph, m, color, v + 1, num_vertices):
                return True
            
            # BACKTRACK
            color[v] = 0
            
    return False

def main():
    print("--- DSA Masterclass: Graph Coloring (Python) ---\n")
    
    # Adjacency Matrix representation
    graph = [
        [0, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 1, 0, 1],
        [1, 0, 1, 0]
    ]
    
    num_vertices = len(graph)
    m = 3  # Number of available colors
    color = [0] * num_vertices  # Initialize colors as 0

    if not graph_coloring_util(graph, m, color, 0, num_vertices):
        print("Solution does not exist")
    else:
        print("Graph Vertex Coloring Scheme (Python):")
        for i in range(num_vertices):
            print(f" -> Vertex {i} -> Color ID: {color[i]}")

if __name__ == "__main__":
    main()