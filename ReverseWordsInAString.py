class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
		s = s.strip()
		list1 = s.split()
		list1 = list1[::-1]
		result = ""
		for i in list1:
			result += i+" "
		return result.strip()
