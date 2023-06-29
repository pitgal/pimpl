#include <iostream>
#include "globbase.h"
#include "foo.h"
#include "bar.h"

int main() {
  auto gb(std::make_unique<GlobBase>());
  // GlobBase gb;
  auto ptrBar = gb->getBar();
  auto ptrFoo = gb->getFoo();
  ptrBar->print();
  ptrFoo->print();
  std::cout << "Koniec wykonania\n";
  return 0;
}
