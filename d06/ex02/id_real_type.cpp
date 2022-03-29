#include <iostream>
#include <random>
#include <ctime>

class	Base {
	public:
		virtual ~Base(void);
};

Base::~Base() { };

class	A : public Base	{ };
class	B : public Base	{ };
class	C : public Base	{ };

Base	*generate(void)
{
	int	n = std::rand() % 3;
	if (n == 0)
		return (new A());
	else if (n == 1)
		return  (new B());
	return  (new C());
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch(std::exception e) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch(std::exception e) {}	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch(std::exception e) {}
}

int	main()
{
	std::srand(time(0));
	Base *rand_p = generate();
	identify_from_pointer(rand_p);
	identify_from_reference(*rand_p);
	return (0);
}