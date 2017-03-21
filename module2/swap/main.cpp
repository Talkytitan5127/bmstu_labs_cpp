#include <iostream>

template<typename t>

void swap(t &a, t &b)
{
    t c = a;
    a = b;
    b = c;
}

int main() {
    int a = 5, b = 7;
    swap(a, b);
    std::cout << a << " " << b << '\n';
    
    float c = 4.5, d = 2.3;
    swap(c, d);
    std::cout << c << " " << d << '\n';
    
    std::string s1 = "abc";
    std::string s2 = "gfr";
    swap(s1, s2);
    std::cout << s1 << " " << s2 << '\n';
    
    return 0;
}
