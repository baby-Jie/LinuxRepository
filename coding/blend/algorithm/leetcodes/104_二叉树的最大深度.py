class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
	def maxDepth(self, root: TreeNode) -> int:
		
		def get_height(node:TreeNode):
			if not node:
				return 0
			left_len = get_height(node.left)
			right_len = get_height(node.right)
			return max(left_len, right_len) + 1
		return get_height(root)
s = Solution()

