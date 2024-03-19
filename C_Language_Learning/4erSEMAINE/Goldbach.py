def prime(num):
    sqrt_n = int(int(num) ** 0.5)
    i = 2
    while i <= sqrt_n:
        if num % i == 0:
            return 0
        else:
            i += 1
    return 1

#main part
k = int(input("Input a number to split into two prime numbers:\n"))
if k < 4:
    print("Too small!")
    exit
a = 2
while a <= k / 2:
    if ((prime(a)) and (prime(k - a))):
        fml = str(k) + "=" + str(a) + "+" + str(k - a)
        print(fml)
    a += 1