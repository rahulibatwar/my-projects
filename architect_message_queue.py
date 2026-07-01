import time
from collections import deque

class MessageBroker:
    """Simulating an Enterprise Message Queue Broker (Like RabbitMQ/Kafka)"""
    def __init__(self):
        self.queue = deque() # In-memory FIFO (First-In, First-Out) Buffer

    def publish_event(self, event_name):
        print(f"📥 [Producer] Event published to queue: '{event_name}'")
        self.queue.append(event_name)

    def process_next_event(self, worker_id):
        if not self.queue:
            print(f"💤 [{worker_id}] Queue is empty. Worker is idling...")
            return False

        # FIFO processing logic
        active_event = self.queue.popleft()
        print(f"⚙️  [{worker_id}] Dequeuing and processing: '{active_event}'")
        time.sleep(1) # Simulating heavy background processing task
        print(f"✅ [{worker_id}] Completed processing for: '{active_event}'")
        return True

def main():
    print("=" * 50)
    print("  AI System Architecture: Message Queue Simulator   ")
    print("=" * 50)

    # Initializing central message buffer broker
    broker = MessageBroker()

    print("\n⚡ [Step 1] Simulating instant heavy user requests generation...")
    print("-" * 50)
    # Rapidly dumping continuous back-to-back jobs into the pipeline queue
    broker.publish_event("Generate_Invoice_Order_101")
    broker.publish_event("Send_Welcome_Email_User_405")
    broker.publish_event("Process_Video_Transcoding_HD")
    broker.publish_event("Calculate_Tax_Metrics_Q2")

    print(f"\n📊 Current Buffered Jobs in Queue Memory: {len(broker.queue)} Items")
    print("-" * 50)

    print("\n⚡ [Step 2] Simulating Background Async Workers consumption:")
    print("-" * 50)
    
    # Background workers processing tasks asynchronously one by one without slowing main application
    broker.process_next_event("Worker-Node-Alpha")
    broker.process_next_event("Worker-Node-Beta")
    broker.process_next_event("Worker-Node-Alpha")

    print(f"\n📊 Remaining Backlog Jobs Left in Buffer: {len(broker.queue)} Items")
    print("-" * 50)

if __name__ == "__main__":
    main()