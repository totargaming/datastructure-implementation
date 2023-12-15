phone = {
    '2': "abc",
    '3': "def",
    '4': "ghi",
    '5': "jkl",
    '6': "mno",
    '7': "pqrs",
    '8': "tuv",
    '9': "wxyz"
}

def backtrack(combination, next_digits, result):
    if len(next_digits) == 0:
        result.append(combination)
    else:
        for letter in phone[next_digits[0]]:
            backtrack(combination+ letter,next_digits[1:],result)
            
def getWords(digits,dictionary):
    new_dict = set(dictionary)
    all_combination = list()
    if len(digits) != 0:
        backtrack("",digits,all_combination)
    result = list()
    for word in all_combination:
        if new_dict.count(word) > 0:
            result.append(word)
    return result