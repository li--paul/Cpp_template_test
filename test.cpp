#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <memory>
#include <sstream>
using namespace std;

#define LOG cout
#define NL endl

#define make_citizen(X)                                                                                                               \
    class tfn_##X                                                                                                                     \
    {                                                                                                                                 \
      public:                                                                                                                         \
        template <typename... Args>                                                                                                   \
        auto operator()(Args &&... args) const -> decltype(X(std::forward<Args>(args)...)) { return X(std::forward<Args>(args)...); } \
    }

/*
template <typename... Args>
void print(Args... args)
{
    (void)(int[]){((LOG << args), 0)...};
    LOG << NL;
}
*/
template <typename T>
void print(T t)
{
    cout << t << endl;
}

make_citizen(print);

int main()
{
    // let's test citizenship...
    tfn_print print;
    print(5 + 8);
    print("hello");
}