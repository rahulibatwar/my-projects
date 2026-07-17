import heapq

class GraphDijkstra:
    def __init__(self):
        self.graph = {}

    # वेटेड ग्राफ के लिए कनेक्शन जोड़ना (u से v का वजन/दूरी w है)
    def add_edge(self, u, v, weight):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
            
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))  # Undirected Graph

    # डाईकस्ट्रा एल्गोरिदम मुख्य फंक्शन
    def dijkstra(self, start_node):
        # शुरुआत में सभी नोड्स की दूरी Infinity (असीम) मान लेते हैं
        distances = {node: float('inf') for node in self.graph}
        distances[start_node] = 0
        
        # मिनिमम हीप (Priority Queue) सबसे छोटे रास्ते को पहले प्रोसेस करने के लिए
        min_heap = [(0, start_node)]  # (distance, node)

        while min_heap:
            current_distance, current_node = heapq.heappop(min_heap)

            # अगर हमें पहले से ही कोई छोटा रास्ता मिल चुका है, तो आगे बढ़ें
            if current_distance > distances[current_node]:
                continue

            # पड़ोसी नोड्स और उनकी दूरी को चेक करें
            for neighbor, weight in self.graph[current_node]:
                distance = current_distance + weight

                # अगर नया रास्ता पुराना रास्ते से छोटा है, तो अपडेट करें
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(min_heap, (distance, neighbor))

        # रिजल्ट प्रिंट करें
        print(f"--- Shortest distances from node {start_node} ---")
        for node, dist in distances.items():
            print(f"Distance to node {node} : {dist}")


# --- Main Driver Code ---
if __name__ == "__main__":
    g = GraphDijkstra()
    
    # ग्राफ में नोड्स और उनके बीच की दूरी (Weight) जोड़ रहे हैं
    g.add_edge(0, 1, 4)
    g.add_edge(0, 2, 1)
    g.add_edge(2, 1, 2)
    g.add_edge(1, 3, 5)
    g.add_edge(2, 3, 8)

    # नोड 0 से सभी नोड्स की सबसे छोटी दूरी निकालें
    g.dijkstra(0)