#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <locale>
#include <cstring>
#include <algorithm>

int substring (char * input, int len) {
  if (len <= 0) {
    return 0;
  }
  return 1 + substring(&input[--len], len);
}


// GET INPUTS from STDIN
std::vector<std::string> Get_STDIN_Strings(void) {
  std::string line;
  std::vector<std::string> inputs;
  while(std::getline(std::cin, line)) { inputs.push_back(line); }
  return inputs;
}

std::string LowerString(std::string input) {
  std::locale loc;
  for (std::string::size_type i = 0, len = input.length(); i < len; ++i) {
    input[i] = std::tolower(input[i], loc);
  }
  return input;
}

bool Palimdrone(std::string input) {

  std::string tmp(input.c_str());

  std::reverse(tmp.begin(), tmp.end());

  if (strcmp(input.c_str(), tmp.c_str()) == 0) { return true; }

  return false;
}

std::string CleanString(std::string input) {
  std::stringstream ss;
  for (int i = 0, len = input.length(); i < len; ++i) {
    if (ispunct(input[i]) || isspace(input[i])) { continue; }
    ss << input[i];
  }
  return ss.str();
}

int main() {

  std::vector<std::string> inputs = Get_STDIN_Strings();

  for (int i = 0, len = inputs.size(); i < len; ++i) { 
  std::cerr << substring(inputs[i].c_str(), inputs[i].size()) << std::endl;

    if (Palimdrone(LowerString(CleanString(inputs[i])))) {
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
  }

  return 0;
}

