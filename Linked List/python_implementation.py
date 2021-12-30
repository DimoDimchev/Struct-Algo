class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def size(self):
        count = 0
        current = self.head

        while current:
            count += 1
            current = current.next
        
        return count
    
    def is_empty(self):
        return self.head == None

    def print_list(self):
        arr = []
        current = self.head

        while current:
            arr.append(current.data)
            current = current.next
        
        print(arr)
    
    def reverse(self):
        current = self.head
        previous = None

        while current:
            next = current.next
            current.next = previous
            previous = current
            current = next
        
        self.head = previous
    
    def value_at(self, index):
        if index == 0:
            return self.head
        
        current = self.head
        count = 0

        while current:
            if count == index:
                return current
            
            count += 1
            current = current.next

    def front(self):
        return self.head
    
    def back(self):
        last_element = self.head

        while last_element.next:
            last_element = last_element.next
        
        return last_element

    def insert(self, index, value):
        node = Node(value)

        if index == 0:
            node.next = self.head.next
            self.head = node

            return
        
        current = self.head
        previous = current
        count = 0

        while current:
            if count == index:
                node.next = previous.next
                previous.next = node
                return
            
            previous = current
            current = current.next
            count += 1

    def erase(self, index):
        if index == 0:
            next = self.head.next
            previous = self.head
            self.head = next

            del previous
            return 
        
        count = 0
        current = self.head
        previous = current

        while current:
            if count == index:
                next = current.next
                previous.next = next

                del current
                return
            
            count += 1
            previous = current
            current = current.next

    def remove_value(self, value):
        if self.head:
            current = self.head
            if current.data == value:
                next = self.head.next
                self.head = next
                del current
                return

        current = self.head
        previous = current

        while current:
            if current.data == value:
                next = current.next
                previous.next = next
                del current
                return
            
            previous = current
            current =  current.next

    def push_front(self, value):
        node = Node(value)

        node.next = self.head
        self.head = node
    
    def push_back(self, value):
        node = Node(value)

        if not self.head:
            self.head = node
            return
        
        last_element = self.head
        while last_element.next:
            last_element = last_element.next
        
        last_element.next = node

    def pop_front(self):
        next = self.head.next
        element_to_pop = self.head

        self.head = next

        return element_to_pop

    def pop_back(self):
        last_element = self.head
        while last_element.next.next:
            last_element = last_element.next
        
        last_element_value = last_element.next
        last_element.next = None

        return last_element_value
        
list1 = LinkedList()

list1.push_front(1)
list1.push_front(2)
list1.push_front(1)

# print(list1.pop_front().data)

list1.push_back(4)

# print(list1.pop_back().data)

list1.insert(3, 5)

list1.print_list()

list1.reverse()

list1.print_list()