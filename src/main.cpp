#include <iostream>
#include "pimpl.h"

int main()
{
	auto pimpl(std::make_unique<Pimpl>());
	pimpl->printFoo();

#ifdef DEBUG
	Pimpl impl = std::move(*pimpl.release());
	impl.printBar();
	// pimpl->printFoo(); //to już się wywali

	// Pimpl pimpl2;
	// pimpl2 = std::move(std::make_unique<Pimpl>(impl));
	// pimpl2.printBar();

	impl.printBar();
#endif

	std::cout << "Koniec wykonania\n";
	return 0;
}
