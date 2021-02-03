class Solution:
	def levelOrder(self, root:TreeNode) -> List[List[int]]:
		li1 = []
		li2 = []
		li = []
		temp = []
		if not root:
			return li
		li1.append(root)
		while True:
			temp = []
			if not li1:
				break
			li2 = []
			for node in li1:
				temp.append(node.val)
				if node.left:
					li2.append(node.left)
				if node.right:
					li2.append(node.right)
			li.append(temp)
			if not li2:
				break
			temp = []
			li1 = []
			for node in li2:
			 	temp.append(node.val)
			 	if node.left:
			 		li1.append(node.left)
			 	if node.right:
			 		li1.append(node.right)
			li.append(temp)
			print(li)
		return li
