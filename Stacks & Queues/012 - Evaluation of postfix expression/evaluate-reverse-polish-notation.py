import math


class Solution:
    def evaluateExpression(self, operand_1: int, operand_2: int, op: str) -> int:
        ans = 0

        if (op == '+'):
            ans = operand_1 + operand_2
        elif (op == "-"):
            ans = operand_1 - operand_2
        elif (op == "*"):
            ans = operand_1 * operand_2
        else:
            res = operand_1 / operand_2
            ans = math.floor(res) if res >= 0 else math.ceil(res)

        return ans

    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        i = 0
        while (i < len(tokens)):
            if (tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"):
                operand_2 = stack.pop()
                operand_1 = stack.pop()
                ans = self.evaluateExpression(operand_1, operand_2, tokens[i])
                stack.append(ans)
            else:
                stack.append(int(tokens[i]))

            i += 1

        return stack[0]
