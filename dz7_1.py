def solveNQueens(n):
    solutions = []
    board = [['.' for _ in range(n)] for _ in range(n)]
    cols = [False] * n
    diag1 = [False] * (2 * n - 1)
    diag2 = [False] * (2 * n - 1)
   
    stack = [] 
    row = 0
    col = 0
    
    while True:
        if row == n:
            solutions.append([''.join(r) for r in board])
            if not stack:
                break
            row, col = stack.pop()
            d1 = row - col + n - 1
            d2 = row + col
            board[row][col] = '.'
            cols[col] = diag1[d1] = diag2[d2] = False
            col += 1
            continue
        placed = False
        while col < n:
            d1 = row - col + n - 1
            d2 = row + col
            if not (cols[col] or diag1[d1] or diag2[d2]):
                board[row][col] = 'Q'
                cols[col] = diag1[d1] = diag2[d2] = True
                stack.append((row, col))
                row += 1
                col = 0
                placed = True
                break
            col += 1
        
        if not placed:
            if not stack:
                break
            row, col = stack.pop()
            d1 = row - col + n - 1
            d2 = row + col
            board[row][col] = '.'
            cols[col] = diag1[d1] = diag2[d2] = False
            col += 1
    
    return solutions

n = 4
n2 = 5
n3 = 6



def print_solutions_as_squares(solutions):
    if not solutions:
        return
    
    n = len(solutions[0])
    
    # Для каждой строки доски (от 0 до n-1)
    for row in range(n):
        # Проходим по всем решениям
        for sol_idx, solution in enumerate(solutions):
            print(f'"{solution[row]}"', end="  ")
            # Добавляем пробел между решениями
            if sol_idx < len(solutions) - 1:
                print(" ", end="")
        print()  # Переход на новую строку для следующей строки доски



print("Решения для n=4:")
print_solutions_as_squares(solveNQueens(n))

print("\n---------------------")

print("Решения для n=5:")
print_solutions_as_squares(solveNQueens(n2))

print("\n---------------------")

print("Решения для n=6:")
print_solutions_as_squares(solveNQueens(n3))
