def minimumSum(num: int):
    numArr = list(str(num))
    
    n1 = ''
    n1 += min(numArr)
    numArr.remove(min(numArr))

    n2 = ''
    n2 += min(numArr)
    numArr.remove(min(numArr))

    n1 += max(numArr)
    numArr.remove(max(numArr))

    n2 += max(numArr)
    numArr.remove(max(numArr))

    return int(n1) + int(n2)

num = 4009
print(minimumSum(num))