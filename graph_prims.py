import heapq

class GraphPrims:
    def __init__(self, vertices):
        self.V = vertices
        # Adjacency list: हर नोड के लिए खाली लिस्ट बनाएंगे
        self.adj = {i: [] for i in range(vertices)}

    def add_edge(self, u, v, weight):
        # Un-directed ग्राफ है, इसलिए दोनों तरफ जोड़ेंगे
        self.adj[u].append((v, weight))
        self.adj[v].append((u, weight))

    def prims_mst(self):
        # Min-Heap: (weight, current_node, parent_node) स्टोर करेगा
        # हम 0 नोड से शुरू कर रहे हैं, जिसका शुरुआती वेट 0 है और पैरेंट None है
        min_heap = [(0, 0, None)]
        
        # यह ट्रैक करने के लिए कि कौन सा नोड MST में शामिल हो चुका है
        visited = [False] * self.V
        
        mst_edges = []
        total_mst_weight = 0

        print("--- Edges included in Minimum Spanning Tree (Prim's) ---")

        while min_heap:
            weight, u, parent = heapq.heappop(min_heap)

            # अगर नोड पहले से विज़िट हो चुका है, तो छोड़ दें
            if visited[u]:
                continue

            # नोड को MST में शामिल करें
            visited[u] = True
            total_mst_weight += weight

            # अगर यह सोर्स नोड नहीं है, तो इसकी एज को रिजल्ट में दिखाएं
            if parent is not None:
                print(f"Edge ({parent} - {u}) with weight: {weight}")

            # अब इस नोड के सभी पड़ोसियों को हीप में डालें
            for neighbor, edge_weight in self.adj[u]:
                if not visited[neighbor]:
                    heapq.heappush(min_heap, (edge_weight, neighbor, u))

        print(f"Total Weight of MST: {total_mst_weight}")

# --- Main Driver Code ---
if __name__ == "__main__":
    # 4 नोड्स वाला ग्राफ (0, 1, 2, 3)
    g = GraphPrims(4)

    g.add_edge(0, 1, 10)
    g.add_edge(0, 2, 6)
    g.add_edge(0, 3, 5)
    g.add_edge(1, 3, 15)
    g.add_edge(2, 3, 4)

    # Prim's MST रन करें
    g.prims_mst()