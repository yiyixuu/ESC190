def fib(n):
    if n == 0: # base case
        return 0
    elif n == 1:
        return 1
    
    return fib(n-1) + fib(n-2)

print(fib(2000))