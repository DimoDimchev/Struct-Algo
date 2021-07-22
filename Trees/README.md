## Definition
- A collection of nodes linked together to simulate a hierarchy
- Recursive data structure- the root links to a number of subtrees
- Non-linear data structure
- A special kind of graph

## Nodes
- A leaf node is a node without any children
- An internal node is a node that has children
- In a tree with n nodes there will be exactly n - 1 links(edges)

## Properties
- Depth of node x- length of path from root to x
- Height of node x- number of lings in longest path from x to a leaf node
- Height of tree- height of root node

## Other stuff
- Tree traversal- the process of visiting(reading/processing) each node in the tree exactly once in some order
	- Breadth-first- visit all elements of each level before moving to the next level
		-Level-order traversal
	- Depth-first- visit all subtrees of a node before moving to another node of the same level
		- Preorder traversal- DLR(data, left node, right node)
		- Inorder traversal- LDR(left node, data, right node)
		- Postorder traversal- LRD(left node, right node, data)

