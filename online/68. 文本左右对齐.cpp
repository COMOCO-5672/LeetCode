#include <iostream>
#include <vector>

using namespace std;

std::vector<std::string> fullJustify(std::vector<std::string> &words,
                                     int maxWidth) {
  std::vector<std::string> result;
  int i = 0;

  while (i < words.size()) {
    int j = i + 1;
    int lineWidth = words[i].size();

    while (j < words.size() && lineWidth + 1 + words[j].size() <= maxWidth) {
      lineWidth += 1 + words[j].size();
      j++;
    }

    int numWord = j - i;
    int numSpaces = maxWidth - lineWidth + numWord - 1;

    std::string line = words[i];

    // 如果最后一行或者之后一个单词，左对齐
    if (j == words.size() || numWord == 1) {
      for (int k = i + 1; k < j; k++) {
        line += ' ' + words[k];
      }

      // 补齐剩余空格
      line += std::string(maxWidth - line.length(), ' ');
    } else {
      int spaceBetweenWords = numSpaces / (numWord - 1);
      int extraSpaces = numSpaces % (numWord - 1);

      for (int k = i + 1; k < j; k++) {
        int space = (k - i <= extraSpaces) ? spaceBetweenWords + 1 : spaceBetweenWords;
        line += std::string(space, ' ') + words[k];
      }
    }

    result.emplace_back(line);
    i = j;
  }
  return result;
}

int main() {
  vector<string> words = {"This",          "is", "an", "example", "of", "text",
                         "justification."};
  int maxWidth = 16;
  vector<string> result = fullJustify(words, maxWidth);

  cout << "Justified Text:" << endl;
  for (const string &line : result) {
    cout << '"' << line << '"' << endl;
  }
  return 0;
}
