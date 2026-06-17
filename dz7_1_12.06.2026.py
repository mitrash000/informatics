def solveNQueens(n):
    solutions = []
    board = [['.' for _ in range(n)] for _ in range(n)]

    cols = [False] * n
    diag1 = [False] * (2 * n - 1)
    diag2 = [False] * (2 * n - 1)

    def backtrack(row):
        if row == n:
            solutions.append([''.join(r) for r in board])
            return

        for col in range(n):
            d1 = row - col + n - 1
            d2 = row + col

            if cols[col] or diag1[d1] or diag2[d2]:
                continue

            board[row][col] = 'Q'
            cols[col] = diag1[d1] = diag2[d2] = True

            backtrack(row + 1)

            board[row][col] = '.'
            cols[col] = diag1[d1] = diag2[d2] = False

    backtrack(0)
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