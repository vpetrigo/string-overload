# Several overloading of subscription operator in C++
This test projects aims for letting better understanding of how it is possible to make _double/triple/etc_ overloading
of subscription operator in C++.
Sometimes we want to use such construction:
```cpp
String s {"I love you so much"};
String love = s[2][6];
String so_much = s[11][18];

// love -> "love"
// so_much -> "so much"
```
But as we know we could pass only one argument to an `operator[]` overloading in C++.
It is often better to use overloading of the `operator()`, but sometimes we need to do like in the example.

This project gives you short overview how to do double subscription `operator[]`, but it is possible to scale
for your needs.