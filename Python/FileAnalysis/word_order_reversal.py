# function to reverse the order of the words
def wordReverse(str):
    i = len(str) - 1
    start = end = i + 1
    result = ''

    while i >= 0:
        if str[i] == ' ':
            start = i + 1
            while start != end:
                result += str[start]
                start += 1
            result += ' '
            end = i
        i -= 1
    start = 0
    while start != end:
        result += str[start]
        start += 1
    return result


f = open("file1.txt", "r")
print("before reversing ")
for x in f:
    print(x)

f = open("file1.txt", "r")
for x in f:
    print(wordReverse(x))
