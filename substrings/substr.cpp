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

// Shifts all chars to lowercase
std::string LowerString(std::string input) {
  std::locale loc;

  for (std::string::size_type i = 0, len = input.length(); i < len; ++i) {
    input[i] = std::tolower(input[i], loc);
  }
  return input;
}

// Removes whitespace and punctuation
std::string CleanString(std::string input) {
  std::stringstream ss;

  for (int i = 0, len = input.length(); i < len; ++i) {
    if (ispunct(input[i]) || isspace(input[i])) { continue; }
    ss << input[i];
  }

  return ss.str();
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
int all_substring_helper(std::unordered_set<std::string> & container, std::string input) {
  int count = 0; 
  for (int i = 0, len = input.size(); i < len; ++i) {
    auto result = container.insert(input);
    input.erase(input.size() - 1);
    /* if (result.second) { std::cout << *result.first << std::endl; } */
    if (result.second) { ++count; }
  }
  return count;
}

// Calculates # of substrings in a string
int all_substrings(std::string input) {
  int count = 0;
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

