n = int(input("Input the greatest number of the rohmbus:\n"))
if n >= 10:
    print("Too large!")
    exit()
i = int(n)
j = int(n)
while i > 0:
    print(" " * j + (str(n - j + 1)  + " ") * (n - j + 1))
    j -= 1
    i -= 1
i = int(n) - 1
j = int(n)
while i > 0:
    print(" " * (n - j + 2) + (str(i) + " ") * i)
    i -= 1
    j -= 1