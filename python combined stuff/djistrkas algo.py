#!/usr/bin/env python3

import heapq

# Sample graph represented as an adjacency list with weighted edges
graph = {
	'A': {'B': 1, 'C': 4},
	'B': {'A': 1, 'C': 2, 'D': 5},
	'C': {'A': 4, 'B': 2, 'D': 1},
	'D': {'B': 5, 'C': 1}
}

def dijkstra(graph, start):
	# Initialize distances to all nodes as infinity except the start node
	distances = {node: float('inf') for node in graph}
	distances[start] = 0
	
	# Priority queue to store nodes by their tentative distance
	priority_queue = [(0, start)]
	
	while priority_queue:
		# Get the node with the smallest tentative distance
		current_distance, current_node = heapq.heappop(priority_queue)
		
		# If current_distance is greater than the recorded distance, skip
		if current_distance > distances[current_node]:
			continue
		
		for neighbor, weight in graph[current_node].items():
			distance = current_distance + weight
			
			# If this path is shorter than the recorded one, update the distance
			if distance < distances[neighbor]:
				distances[neighbor] = distance
				heapq.heappush(priority_queue, (distance, neighbor))
				
	return distances

# Example: Find the shortest distances from 'A' to all other nodes
start_node = 'A'
shortest_distances = dijkstra(graph, start_node)

for node, distance in shortest_distances.items():
	print(f'Shortest distance from {start_node} to {node} is {distance}')
	