#include <iostream>
#include "pimpl.h"

int main()
{
	auto pimpl(std::make_unique<Pimpl>());
	pimpl->printFoo();
	pimpl->printBar();

#ifdef DEBUG
	Pimpl impl = std::move(*pimpl.get());
	impl.printFoo();
	impl.printBar();
	pimpl->printFoo();
	pimpl->printBar();
#endif

	std::cout << "Koniec wykonania\n";
	return 0;
}
