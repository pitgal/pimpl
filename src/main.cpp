#include <iostream>
#include "globbase.h"
#include "foo.h"
#include "bar.h"

int main() {
  auto gb(std::make_unique<GlobBase>());

  auto ptrBar = gb->getBar();
  ptrBar->print();

  auto ptrFoo = gb->getFoo();
  ptrFoo->print();

  std::cout << "Koniec wykonania\n";
  return 0;
}
