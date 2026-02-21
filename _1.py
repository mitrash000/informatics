import time
def measure_execution_time(func, *args, **kw):
    start_time = time.time()  # Начинаем отсчет времени
    result = func(*args, **kw)  # Выполняем переданную функцию с аргументами
    end_time = time.time()  # Останавливаем отсчет времени
    execution_time = (end_time - start_time) * 1000  # Время в миллисекундах
    return result, execution_time

def is_stack_0_1(stack):
    return not stack

stack=[]

print(measure_execution_time(is_stack_0_1,stack))