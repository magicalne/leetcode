class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        notion = ["+", "-", "*", "/"]
        exp = []
        for i in tokens:
            if i not in notion:
                exp.append(int(i))
            else:
                second = exp.pop()
                first = exp.pop()
                if i == "+":
                    result = first+second
                elif i == "-":
                    result = first-second
                elif i == "*":
                    result = first*second
                else:

                    result = int(float(first)/second)
                exp.append(result)
        return exp[0]
