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

  std::stable_sort(vec2.begin(), vec2.end());
  std::stable_sort(vec1.begin(), vec1.end());

  for (int i = 0; i < vec1.size(); i++) {
    result += abs(vec1[i] - vec2[i]);
  }

  std::cout << result;
  return 0;
}
