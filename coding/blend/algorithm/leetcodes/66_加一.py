class Solution:
	def plusOne(self, digits):
		s = ""

		for item in digits:
			s = s + str(item)
		ret = int(s) + 1
		s = str(ret)
		li = []
		for item in s:
			li.append(int(item))
		return li 
s = Solution()
li = [0]
print(s.plusOne(li))
