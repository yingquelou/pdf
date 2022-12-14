#include <iostream>
template <typename T>
T *mm(T x)
{
    return new T(x);
}
int main(int argc, char *argv[])
{
    std::cout << *mm(10) << std::endl;
    return 0;
}