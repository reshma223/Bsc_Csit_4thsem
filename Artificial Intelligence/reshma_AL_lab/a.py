import heapq


def heuristic(node, goal):
    # Heuristic function to estimate the cost from the current node to the goal node
    heuristic_values = {
        '5': 4,
        '3': 2,
        '7': 2,
        '2': 1,
        '4': 1,
        '8': 0
    }
    return heuristic_values[node]


def a_star_search(graph, start, goal):
    open_set = []  # Priority queue for nodes to be explored
    closed_set = set()  # Set to track visited nodes

    # Dictionary to store the cost from the start node to each node
    g = {node: float('inf') for node in graph}
    g[start] = 0

    # Dictionary to store the parent node of each node in the final path
    parents = {}

    # Add the start node to the open set with priority based on the heuristic
    heapq.heappush(open_set, (heuristic(start, goal), start))

    while open_set:
        _, current_node = heapq.heappop(open_set)

        # Check if the current node is the goal node
        if current_node == goal:
            return reconstruct_path(parents, goal)

        # Add the current node to the closed set
        closed_set.add(current_node)

        # Explore the neighbors of the current node
        for neighbor, cost in graph[current_node]:
            if neighbor in closed_set:
                continue

            # Calculate the tentative cost from the start node to the neighbor node
            tentative_g = g[current_node] + cost

            if tentative_g < g[neighbor]:
                # Update the cost and parent of the neighbor node
                g[neighbor] = tentative_g
                parents[neighbor] = current_node

                # Add the neighbor node to the open set with priority based on the cost and heuristic
                heapq.heappush(open_set, (tentative_g + heuristic(neighbor, goal), neighbor))

    print('Path does not exist!')
    return None


def reconstruct_path(parents, goal):
    # Reconstruct the path from the goal node to the start node
    path = [goal]
    current_node = goal

    while current_node in parents:
        current_node = parents[current_node]
        path.append(current_node)

    path.reverse()
    return path


# Define the adjacency list representation of the graph
graph = {
    '5': [('3', 4), ('7', 3)],
    '3': [('2', 2), ('4', 3)],
    '7': [('8', 2)],
    '2': [],
    '4': [('8', 2)],
    '8': []
}

# Define the start and goal nodes
start_node = '5'
goal_node = '8'

print("Following is the A* Search path:")
path = a_star_search(graph, start_node, goal_node)
if path:
    for node in path:
        print(node, end=" ")
else:
    print("No path found.")
