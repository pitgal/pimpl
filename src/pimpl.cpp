#include "pimpl.h"
#include <memory>
#include "foo.h"
#include "bar.h"

class Pimpl::Impl{
public:
	Impl() : m_pFoo(std::make_unique<Foo>() ), m_pBar(std::make_unique<Bar>()){}
	void printFoo() const { m_pFoo->print(); }
	void printBar() const { m_pBar->print(); }

private:
	int m_someNumber = 0;
	std::unique_ptr<Foo> m_pFoo;
	std::unique_ptr<Bar> m_pBar;
};

void Pimpl::print() const {
	if(m_pImpl) {
		m_pImpl->printFoo();
		m_pImpl->printBar();
	}
}

Pimpl::Pimpl() : m_pImpl(std::make_unique<Impl>()){}

Pimpl::~Pimpl() = default;

Pimpl::Pimpl(Pimpl&& other) noexcept : m_pImpl(nullptr) { this->swap(other); }

Pimpl& Pimpl::swap(Pimpl& rhs) {
    std::swap( m_pImpl, rhs.m_pImpl);
    return *this;
}

Pimpl& Pimpl::operator=(Pimpl&& rhs) noexcept { return this->swap(rhs); }

// Pimpl::Pimpl(const Pimpl& other) : m_pImpl(std::make_unique<Impl>(*other.m_pImpl)) {}

// Pimpl& Pimpl::operator=(const Pimpl& rhs) {
// 	if (this != &rhs)
// 		*m_pImpl = *rhs.m_pImpl;
// 	return *this;
// }