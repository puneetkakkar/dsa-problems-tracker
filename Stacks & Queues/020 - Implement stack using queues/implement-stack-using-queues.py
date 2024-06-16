class MyQueue:

    def __init__(self):
        self.list_1 = []
        self.list_2 = []

    def push(self, x: int) -> None:
        self.list_2 = self.list_1[::-1]
        self.list_2.append(x)
        self.list_1 = self.list_2[::-1]
        self.list_2 = []

    def pop(self) -> int:
        return self.list_1.pop()

    def peek(self) -> int:
        return self.list_1[-1]

    def empty(self) -> bool:
        return True if(len(self.list_1) == 0) else False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()