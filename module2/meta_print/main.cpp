#include <iostream>

template<size_t N>
size_t print()
{
    std::cout << 100 - N << " ";
    return print<N-1>();
}

template<>
size_t print<-1>()
{
    return 0;
}

int main() {

    print<100>();

    return 0;
}
