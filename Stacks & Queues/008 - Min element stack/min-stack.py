import sys
from collections import deque


class MinStack:

    def __init__(self):
        self.stack = deque()
        self.min_ele = sys.maxsize

    def push(self, val: int) -> None:
        last_min_val = self.min_ele
        if (len(self.stack) >= 1):
            last_min_val = min(self.min_ele, self.stack[-1][0])
        self.stack.append((val, last_min_val))
        self.min_ele = min(self.min_ele, val)

    def pop(self) -> None:
        if (len(self.stack) > 0):
            ele, min_ele = self.stack.pop()
            if (ele == self.min_ele):
                self.min_ele = min_ele
            elif (min_ele == sys.maxsize):
                self.min_ele = ele

    def top(self) -> int:
        if (len(self.stack) > 0):
            return self.stack[-1][0]

    def getMin(self) -> int:
        return self.min_ele


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
