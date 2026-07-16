from collections import deque

# Graph क्लास जो Adjacency List का इस्तेमाल करती है
class Graph:
    def __init__(self):
        # ग्राफ को स्टोर करने के लिए डिक्शनरी
        self.graph = {}

    # ग्राफ में दो नोड्स के बीच कनेक्शन (Edge) जोड़ने के लिए
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
            
        self.graph[u].append(v)
        self.graph[v].append(u)  # Undirected Graph के लिए दोनों तरफ जोड़ेंगे

    # BFS Traversal फंक्शन
    def bfs(self, start_node):
        visited = set()         # ट्रैक रखने के लिए कि कौन सा नोड विजिट हो चुका है
        queue = deque()         # नोड्स को प्रोसेस करने के लिए कतार

        # शुरुआती नोड से शुरुआत करें
        visited.add(start_node)
        queue.append(start_node)

        print(f"BFS Traversal starting from node {start_node}: ", end="")

        while queue:
            # क्यू के सामने से एलिमेंट निकालें
            current = queue.popleft()
            print(f"{current} -> ", end="")

            # करंट नोड के सभी पड़ोसियों को चेक करें
            for neighbor in self.graph[current]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        
        print("End")


# --- Main Driver Code ---
if __name__ == "__main__":
    g = Graph()
    
    print("--- Creating the Graph ---")
    # एक सिंपल ग्राफ का स्ट्रक्चर बना रहे हैं
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 4)

    # BFS रन करें
    g.bfs(0)