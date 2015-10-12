#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct String {
  String(const char *s = "") : size{strlen(s)}, str{new char[size + 1]} {
    strncpy(str, s, size);
    str[size] = '\0';
  };

  String(size_t n, char c) : size{n}, str{new char[size + 1]} {
    fill(str, str + size, c);
    str[size] = '\0';
  };

  ~String() {
    delete[] str;
  };

  struct String_part {
    String_part(const char *s, size_t beg) : ptr_to_str{s}, begin{beg} {}

    String& operator[](size_t end) const {
      String *new_str;

      if (begin < end) {
        size_t new_size = end - begin;
        char *tmp = new char[new_size + 1];

        for (int i = 0; i < new_size; ++i) {
          tmp[i] = ptr_to_str[i + begin];
        }

        tmp[new_size] = '\0';
        new_str = new String(tmp);
        delete[] tmp;
      }
      else {
        new_str = new String("");
      }

      return *new_str;
    }

    const char *ptr_to_str;
    size_t begin;
  };

  String_part operator[](size_t begin) const {
    return String_part(str, begin);
  }

  void append(const String &other);

  size_t size;
  char *str;
};

int main() {
  String s{"hello"};
  String hell = s[0][4];
  String ell = s[1][4];

  cout << s.str << endl;
  cout << hell.str << endl;
  cout << ell.str << endl;

  return 0;
}