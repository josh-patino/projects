#!/usr/bin/env python3

# Sample graph represented as an adjacency list
graph = {
	'A': ['B', 'C'],
	'B': ['A', 'D', 'E'],
	'C': ['A', 'F'],
	'D': ['B'],
	'E': ['B', 'F'],
	'F': ['C', 'E']
}

visited = set()  # To keep track of visited nodes

def dfs(node):
	if node not in visited:
		print(node, end=' ')  # Process the current node
		visited.add(node)
		for neighbor in graph[node]:
			dfs(neighbor)  # Recursive call for unvisited neighbors
			
# Starting DFS from node 'A'
dfs('A')
