#include <iostream>

using namespace std;

string s;
int vowel_cnt, consonant_cnt;

bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
  while (true) {
    cin >> s;
    if (s == "end")
      break;

    vowel_cnt = consonant_cnt = 0;
    bool invalid = false;
    bool has_vowel = false;
    char prev = '\0';

    for (int i = 0; i < s.size(); i++) {
      char c = s[i];

      if (isVowel(c)) {
        vowel_cnt++;
        consonant_cnt = 0;
        has_vowel = true;
      } else {
        consonant_cnt++;
        vowel_cnt = 0;
      }

      if (vowel_cnt == 3 || consonant_cnt == 3) {
        invalid = true;
      }

      if (i >= 1 && (prev == c) && (c != 'e' && c != 'o')) {
        invalid = true;
      }

      prev = c;
    }

    if (!has_vowel)
      invalid = true;

    if (invalid) {
      cout << "<" << s << ">"
           << " is not acceptable.\n";
    } else {
      cout << "<" << s << ">"
           << " is acceptable.\n";
    }
  }
  return 0;
}