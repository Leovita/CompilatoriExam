#include <iostream>
#include <stdint.h>

extern "C" {
    int32_t OUT(int x);
}

extern "C" {
    int32_t IN(int verbose);
}

int OUT(int32_t v) {
    std::cout << v << std::endl;
    return 0;
}

int32_t IN(int verbose) {
  int32_t n;
  if (verbose) std::cout << "Inserisci il valore di input: \n";
  std::cin >> n;
  return n;
}



