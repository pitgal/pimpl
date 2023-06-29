#include "pimpl.h"
#include <memory>
#include "foo.h"
#include "bar.h"

class Pimpl::Impl{
public:
	int cnt_ = 0;
	Foo* pFoo;
	Bar* pBar;
	Impl() : pFoo(new Foo), pBar(new Bar){}
	~Impl() { delete pFoo; delete pBar; }
};

void Pimpl::printBar() const {
	if(pImpl)
		pImpl->pBar->print();
}

void Pimpl::printFoo() const {
	if(pImpl)
		pImpl->pFoo->print();
}

void Pimpl::setFoo(float val) {
	if(pImpl)
		pImpl->pFoo->value = val;
}

void Pimpl::setBar(int val) {
	if(pImpl)
		pImpl->pBar->value = val;
}

Pimpl::Pimpl() : pImpl(std::make_unique<Impl>()){}

// Pimpl::Pimpl(const Pimpl& other) : pImpl(std::make_unique<Impl>(*other.pImpl)) {}

Pimpl::~Pimpl() {}

// Pimpl& Pimpl::operator=(const Pimpl& rhs) {
// 	if (this != &rhs)
// 		*pImpl = *rhs.pImpl;
// 	return *this;
// }

Pimpl::Pimpl(Pimpl&& other) noexcept : pImpl(nullptr) { this->swap(other); }

Pimpl& Pimpl::swap(Pimpl& rhs) {
    std::swap( pImpl, rhs.pImpl);
    return *this;
}

Pimpl& Pimpl::operator=(Pimpl&& rhs) noexcept { return this->swap(rhs); }
