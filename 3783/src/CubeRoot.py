from decimal import *
from math import floor

def cubeRoot(inputNum):
    ans = inputNum ** (Decimal('1') / Decimal('3'))
    ans = round(ans, 500)
    ans = ans.quantize(Decimal('0.0000000001'), rounding = ROUND_DOWN)
    print(ans)

N = int(input())
getcontext().prec = 1000
for i in range(0, N):
    num = Decimal(input() + '.000000000000')
    cubeRoot(num)



