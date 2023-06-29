#pragma once

#include <memory>

class Pimpl
{
private:
	class Impl;
	std::unique_ptr<Impl> m_pImpl;

public:
	Pimpl();
	Pimpl(const Pimpl& other) = delete; 		//konstruktor kopiujący
	Pimpl(Pimpl&& other) noexcept;				//konstruktor przenoszący
	~Pimpl();									//destruktor zapobiega powstaniu automatycznego inline

	Pimpl& swap(Pimpl& rhs);
	Pimpl &operator=(const Pimpl& rhs) = delete;//kopiujący operator przypisania
	Pimpl &operator=(Pimpl&& rhs) noexcept;		//przenoszący operator przypisania

	void printBar() const;
	void printFoo() const;
};