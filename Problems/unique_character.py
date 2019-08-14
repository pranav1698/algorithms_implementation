def uniqueChars(string):
    # Please add your code here
    char=list()
    for character in string:
        if character not in char:
            char.append(character)
    result=""
    for character in char:
        result = result + character
    return result

# Main
string = input()
print(uniqueChars(string))
