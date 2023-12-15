#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
std::unordered_map<char, std::string> phone = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

void backtrack(const std::string &combination, const std::string &digits,
               std::vector<std::string> &all_combinations) {
  if (digits.length() == 0)
    all_combinations.push_back(combination);
  else {
    char digit = digits[0];
    std::string letters = phone[digit];
    for (char letter : letters) {
      backtrack(combination + letter, digits.substr(1), all_combinations);
    }
  }
}

std::vector<std::string> getWords(
    const std::string &digits,
    const std::unordered_set<std::string> &dictionary) {
  std::vector<std::string> all_combinations;
  if (digits.length() != 0) backtrack("", digits, all_combinations);
  std::vector<std::string> result;
  for (const std::string &word : all_combinations) {
    if (dictionary.count(word) > 0) result.push_back(word);
  }
  return result;
}