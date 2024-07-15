import heapq

def heuristic(node, goal):
    # Heuristic function to estimate the cost from the current node to the goal node
    heuristic_values = {
        'A': 6,
        'B': 5,
        'C': 3,
        'D': 4,
        'E': 2,
        'F': 3,
        'G': 0
    }
    return heuristic_values[node]

def gbfs_search(graph, start, goal):
    open_list = [(heuristic(start, goal), start)]
    came_from = {}
    visited = set()
    
    while open_list:
        _, current = heapq.heappop(open_list)
        
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path
        
        visited.add(current)
        
        for neighbor in graph[current]:
            if neighbor not in visited:
                came_from[neighbor] = current
                heapq.heappush(open_list, (heuristic(neighbor, goal), neighbor))
    
    return None  # No path found

graph = {
    'A': {'B': 2, 'C': 3},
    'B': {'A': 2, 'D': 3},
    'C': {'A': 3, 'E': 2},
    'D': {'B': 3, 'F': 2},
    'E': {'C': 2, 'F': 3},
    'F': {'D': 2, 'E': 3, 'G': 1},
    'G': {'F': 1}
}

start_node = 'A'
goal_node = 'G'

path = gbfs_search(graph, start_node, goal_node)

if path:
    print("Path:", ' -> '.join(path))
else:
    print("No path found.")
