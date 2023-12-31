#include <iostream>
#include "pimpl.h"

int main()
{
#ifdef DEBUG
	std::cout << "Debug version\n";
#else
	std::cout << "Release version\n";
#endif

	auto pimpl(std::make_unique<Pimpl>());
	pimpl->print();

	Pimpl impl = std::move(*pimpl.release());
	impl.print();
	// pimpl->print(); //to już się wywali

	std::unique_ptr<Pimpl> pimpl2;
	pimpl2 = std::make_unique<Pimpl>(std::move(impl));
	pimpl2->print();

	impl = std::move(*pimpl2.release());
	impl.print();

	std::cout << "Program finished\n";
	return 0;
}
