#include <iostream>

using namespace std;

vector<string> split(const string &input, string delimiter) {
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimiter);
  while (end != string::npos) {
    result.push_back(input.substr(start, end - start));
    start = end + delimiter.size();
    end = input.find(delimiter, start);
  }

  result.push_back(input.substr(start));
  return result;
}

vector<string> prac_split(const string &input, string delimeter) {
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimeter);

  while (end != string::npos) {
    result.push_back(input.substr(start, end - start));
    start = end + delimeter.size();
    end = input.find(delimeter, start);
  }
  result.push_back(input.substr(start));
  return result;
}

int main() {
  string str = "one->two->three->four";
  vector<string> numbers = prac_split(str, "->");
  for (auto number : numbers) {
    cout << number << "\n";
  }
  return 0;
}