#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::vector<int> vec1, vec2;
  std::ifstream file("input.txt");
  std::string line;

  long result = 0;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    int a, b;
    if (iss >> a >> b) {
      vec1.push_back(a);
      vec2.push_back(b);
    }
  }

  for (int i = 0; i < vec1.size(); i++) {
    long count = std::count(vec2.begin(), vec2.end(), vec1[i]) * vec1[i];
    result += count;
  }

  std::cout << result;
  return 0;
}
