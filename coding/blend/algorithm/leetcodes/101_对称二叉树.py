class Solution:
	def isSymmetric(self, root:TreeNode)->bool:
		if not root:
			return True
		def isMirror(node1, node2):
			if node1 == None and node2 == None:
				return True
			if node1 == None or node2 == None:
				return False
			if node1.val != node2.val:
				return False
			return isMirror(node1.left, node2.right) and isMirror(node1.right, node2.left)
		return isMirror(root.left, root.right)
