# Graph क्लास जो Adjacency List का इस्तेमाल करती है
class GraphDFS:
    def __init__(self):
        self.graph = {}

    # ग्राफ में दो नोड्स के बीच कनेक्शन (Edge) जोड़ने के लिए
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
            
        self.graph[u].append(v)
        self.graph[v].append(u)  # Undirected Graph

    # DFS ट्रैवर्सल का मुख्य फंक्शन
    def dfs(self, start_node):
        visited = set()  # विजिट किए गए नोड्स का रिकॉर्ड रखने के लिए
        print(f"DFS Traversal starting from node {start_node}: ", end="")
        self._dfs_recursive(start_node, visited)
        print("End")

    # रिकर्सिव हेल्पर फंक्शन जो गहराई में जाएगा
    def _dfs_recursive(self, node, visited):
        # करंट नोड को विजिट मार्क करें और प्रिंट करें
        visited.add(node)
        print(f"{node} -> ", end="")

        # करंट नोड के सभी पड़ोसियों को चेक करें
        for neighbor in self.graph[node]:
            if neighbor not in visited:
                # अगर पड़ोसी विजिट नहीं हुआ है, तो गहराई में जाएं
                self._dfs_recursive(neighbor, visited)


# --- Main Driver Code ---
if __name__ == "__main__":
    g = GraphDFS()
    
    print("--- Creating the Graph for DFS ---")
    # समान ग्राफ स्ट्रक्चर का उपयोग कर रहे हैं
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 4)

    # DFS रन करें
    g.dfs(0)