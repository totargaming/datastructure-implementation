from collections import deque
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
def getWords(digits,dictionary):
    if not digit:
        return []
    new_dict = set(dictionary)
    queue = deque([""])
    for digit in digits:
        for _ in range(len(queue)):
            combination = queue.popleft()
            for letter in phone[digit]:
                queue.append(combination+letter)
    return[word for word in queue if word in new_dict]