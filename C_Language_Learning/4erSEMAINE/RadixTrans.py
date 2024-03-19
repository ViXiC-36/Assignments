def Radix_Trans(data, ori_base = 10, target_base = 10, precisy = 10):
    """i'm good"""
    fin = ""
    if data < 0:
        fin += "-"
        data = -data
    integer_part = int(data)
    data = float(data)
    fraction_part = data - integer_part
    #Process the integer part
    #ori_base -> 10
    digit = 0
    number = 1
    value = 0
    while number != 0:
        number = int((integer_part / (10 ** digit)) % 10)
        value += number * (ori_base ** digit)
        digit += 1
    #10 -> target_base   
    digit = 0
    quotient = int(value)
    results = []
    while quotient != 0:
        number = quotient % target_base
        quotient = int(quotient / int(target_base))
        results.append(number)
    results.reverse()
    for res in results:
        if res >= 10:
            fin += chr(55 + int(res))
        else:
            fin += str(res)
    #Process the fraction part
    if fraction_part == 0:
        return fin
    fin += "."
    digit = -1
    value = 0
    while digit >= -precisy:
        number = int(fraction_part * (10 ** ((-1) * digit))) % 10
        value += number * (ori_base ** digit)
        digit -= 1
    fracs = []
    quotient = value
    while digit < -1:
        number = int(quotient * target_base)
        quotient = quotient * target_base - number
        fracs.append(number)
        digit += 1
    for res in fracs:
        if res >= 10:
            fin += chr(55 + int(res))
        else:
            fin += str(res)
    return fin


fin = Radix_Trans(-243.1, 10, 2)
print(fin)
print(Radix_Trans.__doc__)