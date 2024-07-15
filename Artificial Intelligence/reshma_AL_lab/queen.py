def is_safe(board, row, col):
    # Check if it's safe to place a queen at the given position
    # Check the row
    for c in range(col):
        if board[row][c] == 1:
            return False

    # Check the upper diagonal
    r, c = row, col
    while r >= 0 and c >= 0:
        if board[r][c] == 1:
            return False
        r -= 1
        c -= 1

    # Check the lower diagonal
    r, c = row, col
    while r < len(board) and c >= 0:
        if board[r][c] == 1:
            return False
        r += 1
        c -= 1

    return True


def solve_queens(board, col):
    # Base case: all queens are placed
    if col == len(board):
        return True

    for row in range(len(board)):
        if is_safe(board, row, col):
            board[row][col] = 1

            # Recursively solve for the next column
            if solve_queens(board, col + 1):
                return True

            # If placing the queen at (row, col) doesn't lead to a solution,
            # backtrack by removing the queen from that position
            board[row][col] = 0

    # If all rows have been tried and no solution is found, return False
    return False


def print_board(board):
    # Print the board configuration
    for row in range(len(board)):
        for col in range(len(board[row])):
            print(board[row][col], end=" ")
        print()


def solve_n_queens(n):
    board = [[0] * n for _ in range(n)]

    if solve_queens(board, 0):
        print("Solution found:")
        print_board(board)
    else:
        print("No solution exists.")


n = 8  # Change the value of n for different board sizes
solve_n_queens(n)
