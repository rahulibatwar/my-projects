# DSU (Disjoint Set Union) क्लास जो साइकल डिटेक्ट करने में मदद करेगी
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])  # Path compression
        return self.parent[i]

    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)

        if root_i != root_j:
            if self.rank[root_i] < self.rank[root_j]:
                self.parent[root_i] = root_j
            elif self.rank[root_i] > self.rank[root_j]:
                self.parent[root_j] = root_i
            else:
                self.parent[root_j] = root_i
                self.rank[root_i] += 1
            return True
        return False


class GraphKruskal:
    def __init__(self, vertices):
        self.V = vertices  # नोड्स की संख्या
        self.graph = []    # सभी एजेस को स्टोर करने के लिए लिस्ट

    # ग्राफ में कनेक्शन जोड़ना (u से v का वजन w है)
    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    # क्रुस्कल एल्गोरिदम का मुख्य फंक्शन
    def kruskal_mst(self):
        mst = []  # मिनिमम स्पैनिंग ट्री की एजेस स्टोर करने के लिए
        
        # 1. सभी एजेस को उनके वजन (Weight) के हिसाब से सॉर्ट करें
        self.graph = sorted(self.graph, key=lambda item: item[2])
        
        ds = DisjointSet(self.V)
        mst_weight = 0

        print("--- Edges included in Minimum Spanning Tree ---")
        for u, v, w in self.graph:
            # 2. चेक करें कि इस एज को जोड़ने से साइकल तो नहीं बन रहा
            if ds.union(u, v):
                mst.append([u, v, w])
                mst_weight += w
                print(f"Edge ({u} - {v}) with weight: {w}")

        print(f"Total Weight of MST: {mst_weight}")


# --- Main Driver Code ---
if __name__ == "__main__":
    # 4 नोड्स वाला ग्राफ बना रहे हैं (0, 1, 2, 3)
    g = GraphKruskal(4)
    
    g.add_edge(0, 1, 10)
    g.add_edge(0, 2, 6)
    g.add_edge(0, 3, 5)
    g.add_edge(1, 3, 15)
    g.add_edge(2, 3, 4)

    # Kruskal's MST रन करें
    g.kruskal_mst()
    