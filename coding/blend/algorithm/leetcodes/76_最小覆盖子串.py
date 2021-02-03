class Solution:
	def mainWindow(self, s: str, t:str):
	
		set1 = set()
		li = []
		str_len = len(s)
		for index in range(0, str_len):
			# 如果子串开始不在其中，那么不继续。
			if s[index] not in t:
				continue
			set1 = set()
			start = index
			end = -1
			for i in range(index + 1, str_len):
				if s[i] in t:
					set1.add(s[i])
				# 如果包含了所有子串 停止遍历
				if len(set1) == len(set(t)):
					end = i
					break
			if end != -1:
				li.add(s[start:end+1])

		if li:
			sortLi()
			return li[0]
		else:
			return ""


s = Solution()
s.mainWindow("ADOBECODEBANC", "ABC")

