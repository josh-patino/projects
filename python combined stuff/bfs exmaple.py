#!/usr/bin/env python3

from collections import defaultdict, deque

class Graph:
	def __init__(self):
		self.graph = defaultdict(list)
		
	def add_edge(self, u, v):
		self.graph[u].append(v)
		self.graph[v].append(u)
		
	def bfs(self, start, end):
		visited = set()
		queue = deque()
		parent = {}
		
		queue.append(start)
		visited.add(start)
		found = False
		
		while queue:
			current_node = queue.popleft()
			
			if current_node == end:
				found = True
				break
			
			for neighbor in self.graph[current_node]:
				if neighbor not in visited:
					queue.append(neighbor)
					visited.add(neighbor)
					parent[neighbor] = current_node
					
		if not found:
			return None  # No path found
		
		# Reconstruct the shortest path
		path = []
		node = end
		while node != start:
			path.append(node)
			node = parent[node]
		path.append(start)
		path.reverse()
		
		return path
	
# Example usage:
if __name__ == "__main__":
	g = Graph()
	g.add_edge('A', 'B')
	g.add_edge('A', 'C')
	g.add_edge('B', 'D')
	g.add_edge('B', 'E')
	g.add_edge('C', 'F')
	g.add_edge('E', 'F')
	g.add_edge('D', 'E')
	
	start_node = 'A'
	end_node = 'F'
	
	shortest_path = g.bfs(start_node, end_node)
	
	if shortest_path:
		print(f"Shortest path from {start_node} to {end_node}:", ' -> '.join(shortest_path))
	else:
		print(f"No path found from {start_node} to {end_node}")
		