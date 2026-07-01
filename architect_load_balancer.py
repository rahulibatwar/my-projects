import time

class ComputeServer:
    """Simulating an independent Google Compute Backend Server Node"""
    def __init__(self, server_id):
        self.server_id = server_id
        self.active_connections = 0

    def handle_request(self, user_request):
        self.active_connections += 1
        print(f"🖥️  [{self.server_id}] Processing request from '{user_request}'... (Active Threads: {self.active_connections})")
        time.sleep(0.5) # Simulating server execution time
        self.active_connections -= 1
        return f"Response from {self.server_id} successfully delivered."

class RoundRobinLoadBalancer:
    """Architectural Gateway Traffic Distributor"""
    def __init__(self, backend_servers):
        self.servers = backend_servers
        self.current_index = 0  # Pointer to keep track of the next server

    def route_traffic(self, user_request):
        if not self.servers:
            print("🚨 [Load Balancer] CRITICAL: No backend servers available!")
            return

        # Round Robin Selection Logic
        selected_server = self.servers[self.current_index]
        print(f"\n🔀 [Load Balancer] Routing '{user_request}' to Node: {selected_server.server_id}")
        
        # Forwarding the request to the selected server
        response = selected_server.handle_request(user_request)
        print(f"✅ [Status] {response}")

        # Move the pointer to the next server sequentially
        self.current_index = (self.current_index + 1) % len(self.servers)

def main():
    print("=" * 50)
    print("  AI System Architecture: Round-Robin Load Balancer ")
    print("=" * 50)

    # Creating a cluster of 3 independent backend servers
    cluster = [
        ComputeServer("Vizag-Node-Alpha"),
        ComputeServer("Vizag-Node-Beta"),
        ComputeServer("Vizag-Node-Gamma")
    ]

    # Initializing the Load Balancer with our server pool
    balancer = RoundRobinLoadBalancer(cluster)

    # Simulating 6 back-to-back incoming user requests
    incoming_traffic = [
        "User_Rahul_Request", "User_Amit_Request", "User_Pooja_Request",
        "User_Kiran_Request", "User_Vijay_Request", "User_Sneha_Request"
    ]

    print(f"\n🚀 Booting Cluster Network with {len(cluster)} Nodes...")
    print("Simulating sequential massive traffic burst:")
    print("-" * 50)

    for request in incoming_traffic:
        balancer.route_traffic(request)
        time.sleep(0.2) # Delay between new hits entering the gateway

    print("-" * 50)
    print("🎯 All traffic routed successfully without any server crash!")

if __name__ == "__main__":
    main()