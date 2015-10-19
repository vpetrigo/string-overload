/* Author: vpetrigo
 * Task:
 * Implement overloading of double subscription for String class
 * Example:
 * String s {"Hello"};
 * String Hell = s[0][4];
 * String ell = s[1][4];
 *
 * cout << Hell.str // prints "Hell"
 * cout << ell.str // prints "ell"
 */


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct String {
  explicit String(const char *s = "") : size{strlen(s)}, str{new char[size + 1]} {
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

  String(const String& s) : size{s.size}, str{new char[size + 1]} {
    copy(s.str, s.str + size, str);
    str[size] = '\0';
  }

  String& operator=(const String& s) {
    if (this != &s) {
      String{s}.swap(*this);
    }

    return *this;
  }

  void swap(String& s) {
    ::swap(size, s.size);
    ::swap(str, s.str);
  }

  // class for getting part of current string
  struct String_part {
    // Constructor for calling from String operator[]
    // Pass pointer to the string it uses for making new shorten string
    // and an index of the characters to start from
    String_part(const char *s, size_t beg) : ptr_to_str{s}, begin{beg} {}

    // If the boundary [begin, end) meets begin < end construct new string
    // in all other cases return an empty string
    // String_part(s.str, 1)[3] -> String_part::operator[](end = 3)
    String operator[](size_t end) const {
      char *tmp;

      if (begin < end) {
        size_t new_size = end - begin;
        tmp = new char[new_size + 1];
        fill(tmp, tmp + new_size + 1, '\0');

        for (int i = 0; i < new_size; ++i) {
          tmp[i] = ptr_to_str[i + begin];
        }
      }
      else {
        const size_t one_sym = 1;
        tmp = new char[one_sym];
        fill(tmp, tmp + one_sym, '\0');
      }

      String s {tmp};
      delete[] tmp;

      return s;
    }

    const char *ptr_to_str;
    size_t begin;
  };

  // Getting temporary String_part object:
  // String s {"Hello"};
  // Expression s[1] constructs an object String_part(s.str, 1);
  // which has the second overloaded operator[]
  // Expression s[1][2] has the following flow:
  // s[1] -> String_part(s.str, 1)
  // String_part(s.str, 1)[2] -> String_part::operator[](...)
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