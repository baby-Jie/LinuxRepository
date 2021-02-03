class Solution:
	def addBinary(self, a:str, b:str)->str:
		a1 = eval("0b" + a)
		a2 = eval("0b" + b)
		c = a1 + a2
		return bin(c)[2:]
s = Solution()
ret = s.addBinary("11", "1")
print(ret)
