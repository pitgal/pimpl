#pragma once

#include <memory>

class Pimpl
{
private:
	class Impl;
	std::unique_ptr<Impl> pImpl;

public:
	Pimpl();
	Pimpl(const Pimpl& other) = delete;
	Pimpl(Pimpl&& other) noexcept;
	~Pimpl();

	Pimpl& swap(Pimpl& rhs);
	Pimpl &operator=(const Pimpl& rhs) = delete;
	Pimpl &operator=(Pimpl&& rhs) noexcept;

	void printBar() const;
	void printFoo() const;
	void setBar(int val);
	void setFoo(float val);
};