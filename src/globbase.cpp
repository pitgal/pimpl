#include "globbase.h"
#include <memory>
#include "foo.h"
#include "bar.h"

class GlobBase::Impl{
public:
	int cnt_ = 0;
	Foo* pFoo;
	Bar* pBar;
	Impl() : pFoo(new Foo), pBar(new Bar){}
	~Impl() { delete pFoo; delete pBar; }
};

GlobBase::GlobBase() : pImpl(std::make_unique<Impl>()){}
GlobBase::~GlobBase() = default;
//GlobBase::GlobBase(const GlobBase& rhs) = default;
//GlobBase& GlobBase::operator=(const GlobBase& rhs) = default;
GlobBase::GlobBase(GlobBase&& rhs) = default;
GlobBase& GlobBase::operator=(GlobBase&& rhs) = default;
Bar* GlobBase::getBar() const { return pImpl->pBar; }
Foo* GlobBase::getFoo() const { return pImpl->pFoo; }