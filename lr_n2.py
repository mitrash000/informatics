import random
import math

def monte_carlo_area(num_points):
    inside_points = 0
    for _ in range(num_points):
        x = random.uniform(2, 4)
        y = random.uniform(-1, 0.5)
        if (math.sin(0.5*x)-0.5) > y and y > (math.cos(x)) and (math.sin(x)) > y:
            inside_points += 1

    square_area = 3
    necessary_area = (inside_points / num_points) * square_area
    return necessary_area

cnt = 100000000
estimated_area = monte_carlo_area(cnt)
print(estimated_area)