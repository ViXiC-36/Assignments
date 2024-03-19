e = float(input())
a = []
k = 0
a.append((1 / (16 ** k)) * (4 / (8 * k + 1) - 2 / (8 * k + 4) - 1 / (8 * k + 5) - 1 / (8 * k + 6)))
k += 1
s = sum(a[:])
while a[k - 1] > e:
    a.append((1 / (16 ** k)) * (4 / (8 * k + 1) - 2 / (8 * k + 4) - 1 / (8 * k + 5) - 1 / (8 * k + 6)))
    k += 1
    s = sum(a[:])
print("When the precisy reaches the " + str(k - 1) + "th, the result of phi is " + str(float(s)) + ".")