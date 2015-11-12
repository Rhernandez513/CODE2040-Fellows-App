#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>

// GET INPUTS from STDIN
std::vector<std::string> Get_STDIN_Strings(void) {

  std::vector<std::string> inputs; std::string line;

  while(std::getline(std::cin, line)) { inputs.push_back(line); }

  return inputs;
}

// Deletes the first Char of a string, returns result
std::string DeleteFirstChar(const std::string input) {

  std::string reversed_input(input);

  std::reverse(reversed_input.begin(), reversed_input.end());

  reversed_input.erase(reversed_input.size() - 1);

  std::reverse(reversed_input.begin(), reversed_input.end());

  return reversed_input;
}

// For each iteration, insert string
// Delete last char, repeat
long all_substring_helper(std::unordered_set<std::string> & container, std::string input) {
  long count = 0; 
  for (int i = 0, len = input.size(); i < len; ++i) {
    auto result = container.insert(input);
    input.erase(input.size() - 1);
    if (result.second) { ++count; }
  }
  return count;
}

// Calculates # of substrings in a string
long all_substrings(std::string input) {
  long count = 0;
  std::unordered_set<std::string> valid_permutations;
  for (auto i : input) {
    count += all_substring_helper(valid_permutations, input);
    input = DeleteFirstChar(input);
  }
  return count;
}

int main() {

  std::vector<std::string> inputs = Get_STDIN_Strings();

  std::cout << all_substrings(inputs[0]) << std::endl;

  return 0;
}

