# Node Class: जो डेटा और अगले नोड का रेफरेंस रखेगी
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # C++ के nullptr की जगह Python में None होता है

# Linked List Class: सभी ऑपरेशन्स को संभालने के लिए
class LinkedList:
    def __init__(self):
        self.head = None

    # 1. Insert at End: लिस्ट के आखिरी में नया डेटा जोड़ना
    def insert_at_end(self, val):
        new_node = Node(val)
        
        # अगर लिस्ट खाली है, तो नया नोड ही head बन जाएगा
        if self.head is None:
            self.head = new_node
            return

        # आखिरी नोड तक पहुँचने के लिए ट्रैवर्सल
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node

    # 2. Delete Node: किसी खास वैल्यू वाले नोड को डिलीट करना
    def delete_node(self, val):
        if self.head is None:
            print("List खाली है, डिलीट नहीं कर सकते!")
            return

        # अगर पहला ही नोड डिलीट करना हो
        if self.head.data == val:
            self.head = self.head.next
            return

        temp = self.head
        while temp.next is not None and temp.next.data != val:
            temp = temp.next

        if temp.next is None:
            print(f"वैल्यू {val} लिस्ट में नहीं मिली!")
        else:
            temp.next = temp.next.next
            print(f"वैल्यू {val} को डिलीट कर दिया गया है।")

    # 3. Display: पूरी लिस्ट को प्रिंट करना
    def display(self):
        if self.head is None:
            print("List खाली है!")
            return
        
        temp = self.head
        while temp is not None:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")


# --- कोड को रन करके टेस्ट करते हैं ---
if __name__ == "__main__":
    # लिस्ट का ऑब्जेक्ट बनाया
    my_list = LinkedList()

    print("--- Linked List में डेटा डाल रहे हैं ---")
    my_list.insert_at_end(10)
    my_list.insert_at_end(20)
    my_list.insert_at_end(30)
    my_list.insert_at_end(40)
    
    print("करंट लिस्ट: ", end="")
    my_list.display()

    print("\n--- 30 नंबर वाले नोड को डिलीट कर रहे हैं ---")
    my_list.delete_node(30)

    print("अपडेटेड लिस्ट: ", end="")
    my_list.display()