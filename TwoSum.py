class Solution:
	def twoSum(self, num, target):
		d = dict()
		for i in num:
			d[i] = 1
		for i in range(0, len(num)):
			if (target - num[i]) not in d:
				continue
			for j in range(i+1, len(num)):
				if num[i] + num[j] == target:
					return (i+1, j+1)

s = Solution()
num = [1, 2, 3, 4, 5]
print s.twoSum(num, 9)
