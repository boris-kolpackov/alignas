#include <cstddef>
#include <type_traits>

#include <iostream>

using namespace std;

template <size_t N>
static bool
test ()
{
  struct type
  {
    alignas(std::max_align_t) char data[N];
  };

  size_t a1 (alignof (typename aligned_storage<N>::type));
  size_t a2 (alignof (type));

  cerr << N << ' ' << a1 << ' ' << a2 << '\n';

  return a2 >= a1;
}

int main ()
{
  return
    test<sizeof (int)> ()       &&
    test<sizeof (void*) * 1> () &&
    test<sizeof (void*) * 2> () &&
    test<sizeof (void*) * 3> () &&
    test<sizeof (void*) * 4> () &&
    test<sizeof (void*) * 5> () &&
    test<sizeof (void*) * 6> () &&
    test<sizeof (void*) * 7> () &&
    test<sizeof (void*) * 8> () &&
    test<sizeof (void*) * 9> () &&
    test<sizeof (void*) * 16> ()
    ? 0 : 1;
}
