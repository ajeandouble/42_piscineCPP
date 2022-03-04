#include <iostream>
#include <stdlib.h>
#include "Fixed.hpp"

namespace Eval
{
	enum
	{
		OPERATOR,
		FIXED_NUMBER,
		BRACKET
	};

	struct	s_Token
	{
		unsigned short type;
		Fixed n;
		char op;
	};

	std::ostream &operator<< (std::ostream &os, s_Token &t)
	{
		if (t.type == OPERATOR || t.type == BRACKET)
			os << "[type=" << (t.type == OPERATOR ? "op" : "br") << " val=" << t.op << "]";
		else
			os << "[type=number n=" << t.n << "]";
		return (os);
	}

	class TokenStack
	{
		private:
			size_t _max_size;
			int _index;
			s_Token *_stack;
		public:
			TokenStack(size_t size);
			int	push_back(s_Token t);
			s_Token	pop_back(void);
			s_Token get_last_elem();
			s_Token get_elem(size_t index);
			s_Token set_elem(size_t index, s_Token t);
			size_t  get_size();
			size_t get_max_size();

			void print_stack();
	};


	TokenStack::TokenStack(size_t size)
	{
		this->_stack = new s_Token[size];
		this->_max_size = size;
		this->_index = -1;
	}

	size_t TokenStack::get_size()
	{
		return (this->_index + 1);
	}

	s_Token TokenStack::set_elem(size_t index, s_Token t)
	{
		return (this->_stack[index] = t);
	}

	s_Token TokenStack::get_elem(size_t index)
	{
		return (this->_stack[index]);
	}
	
	int TokenStack::push_back(s_Token t)
	{
		this->_stack[++this->_index] = t;
		return (this->_index);
	}

	s_Token TokenStack::pop_back(void)
	{
		return (this->_stack[this->_index--]);
	}

	s_Token	TokenStack::get_last_elem()
	{
		return (this->_stack[this->_index]);
	}

	void	TokenStack::print_stack()
	{
		for (int i = 0; i <= this->_index; ++i)
			std::cerr << this->_stack[i];
		std::cerr << std::endl;
	}

	// Create a Stack insted of duplicating stacks *2!
	class evalExprStacks
	{
		private:
			TokenStack *_op_stack;
			TokenStack *_output_stack;
			size_t _max_size;
		public:
			evalExprStacks(size_t size);
			int	op_push_back(s_Token t);
			s_Token	op_pop_back(void);
			int	output_push_back(s_Token t);
			s_Token	output_pop_back(void);
			s_Token op_getLastElem();
			s_Token output_getLastElem();
			s_Token op_getElem(size_t index);
			s_Token op_setElem(size_t index, s_Token t);
			s_Token output_getElem(size_t index);
			bool gt_precedence(char op);
			size_t get_op_size();
			size_t get_output_size();
			size_t get_max_size();

			void print_output_stack();
	};
 
	evalExprStacks::evalExprStacks(size_t size)
	{
		this->_op_stack = new TokenStack(size);
		this->_output_stack = new TokenStack(size);
		this->_max_size = size;
	}

	int evalExprStacks::op_push_back(s_Token t)
	{
		return (this->_op_stack->push_back(t));
	}

	int evalExprStacks::output_push_back(s_Token t)
	{
		return (this->_output_stack->push_back(t));
	}

	s_Token evalExprStacks::op_pop_back(void)
	{
		return (this->_op_stack->pop_back());
	}

	s_Token evalExprStacks::output_pop_back(void)
	{
		return (this->_output_stack->pop_back());
	}

	s_Token evalExprStacks::op_getLastElem()
	{
		return (this->_op_stack->get_last_elem());
	}

	s_Token evalExprStacks::output_getLastElem()
	{
		return (this->_output_stack->get_last_elem());
	}

	bool evalExprStacks::gt_precedence(char op)
	{
		if (this->_op_stack->get_size() <= 0)
			return (false);
		if (op == '+' || op == '-')
		{
			char op_top_stack = this->op_getLastElem().op;
			if (op_top_stack == '*' || op_top_stack == '/')
				return (true);
		}
		return (false);
	}

	size_t evalExprStacks::get_op_size()
	{
		return (this->_op_stack->get_size());
	}

	size_t evalExprStacks::get_output_size()
	{
		return (this->_output_stack->get_size());
	}

	// Utility functions

	void	evalExprStacks::print_output_stack()
	{
		this->_output_stack->print_stack();
	}

	s_Token evalExprStacks::op_getElem(size_t index)
	{
		return (this->_op_stack->get_elem(index));
	}

	s_Token evalExprStacks::output_getElem(size_t index)
	{
		return (this->_output_stack->get_elem(index));
	}

	s_Token evalExprStacks::op_setElem(size_t index, s_Token t)
	{
		return (this->_op_stack->set_elem(index, t));
	}

	size_t evalExprStacks::get_max_size() { return (this->_max_size); }
}

std::string clean_str(std::string str)
{
	bool error = false;
	int	parenthesis = 0;
	std::string removed_spaces("");
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isspace(str[i]))
			removed_spaces += str[i];
	}
	std::cerr << "[" << removed_spaces << "]";
	for (size_t i = 0; i < removed_spaces.length(); ++i)
	{
		if (std::string("0123456789+-*/().").find(removed_spaces[i]) == std::string::npos) 
			error = true;
		if (removed_spaces[i] == '(')	++parenthesis;
		else if (removed_spaces[i] == ')')
		{
			if (parenthesis == 0)
			{
				error = true;
				break ;		
			}
			--parenthesis;
		}
	}
	if (error || parenthesis != 0)
	{
		std::cerr << "Input cannot be evaluated" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (removed_spaces);
}

Fixed my_atoi(std::string str)
{
	size_t i = 0;
	short	sign = 1;
	float result = 0;
	for (; str[i] == '-' || str[i] == '+'; ++i)
	{
		if (str[i] == '-')
		sign *= -1;
	}
	for (; str[i] >= '0' && str[i] <= '9'; ++i)
	{
		result *= 10;
		result += str[i] - '0';
	}
	float decimals = 0;
	if (str[i] == '.')
	{
		size_t dec_len;
		for (dec_len = 1; str[i + dec_len] >= '0' && str[i] <= '9'; ++dec_len)
		{
			decimals *= 10;
			decimals += str[i + dec_len] - '0';
		}
		float division = 0.1;
		for (; dec_len; --dec_len)
			division *= 10;
		decimals /= division;
	}
	return Fixed(result * sign + decimals);
}

Fixed calculate_rpn(Eval::evalExprStacks token_stack)
{
	using namespace Eval;
	TokenStack final_stack(token_stack.get_max_size());
	for (size_t i = 0; i < token_stack.get_output_size(); ++i)
	{
		# ifdef DEBUG
			final_stack.print_stack();
		# endif
		s_Token cur_token = token_stack.output_getElem(i);
		if (cur_token.type == FIXED_NUMBER)
			final_stack.push_back(cur_token);
		else if (cur_token.type == OPERATOR)
		{
			size_t final_stack_len = final_stack.get_size();
			Fixed a = final_stack.get_elem(final_stack_len - 2).n;
			Fixed b = final_stack.get_elem(final_stack_len - 1).n;
			Fixed result;
			if (cur_token.op == '+')
				result = a + b;
			else if (cur_token.op == '-')
				result = a - b;
			else if (cur_token.op == '*')
				result = a * b;
			else if (cur_token.op == '/')
			# ifdef DEBUG
				std::cerr << "a=" << a << "\t" << "b=" << b << "\t" << "result=" << result << std::endl;
			# endif
				result = a / b;
			s_Token result_token = { .n = result, .type = FIXED_NUMBER };
			final_stack.set_elem(final_stack_len - 2, result_token);
			final_stack.pop_back();
		}
	}
	# ifdef DEBUG
		final_stack.print_stack();
	# endif
	return (final_stack.pop_back().n);
}

Fixed eval(const std::string str)
{
	using namespace Eval;
	std::string cleaned_str = clean_str(str);
	evalExprStacks token_stack = evalExprStacks(50);
	for (size_t i = 0; i < cleaned_str.size(); )
	{
		if ((cleaned_str[i] >= '0' && cleaned_str[i] <= '9'))
		{
			size_t n_len = 0;
			while ((cleaned_str[i + n_len] >= '0' && cleaned_str[i + n_len] <= '9'))
				++n_len;
			if (cleaned_str[i + n_len] == '.')
			{
				++n_len;
				while ((cleaned_str[i + n_len] >= '0' && cleaned_str[i + n_len] <= '9'))
					++n_len;
			}
		
			Fixed n = Fixed(my_atoi(cleaned_str.substr(i, i + n_len)));
			i += n_len;

			s_Token number = { .type = FIXED_NUMBER, n = n };
			token_stack.output_push_back(number);
		}
		else if (cleaned_str[i] == '(' || cleaned_str[i] == ')')
		{
			s_Token bracket = { .type = BRACKET, .op = cleaned_str[i] };
			if (cleaned_str[i] == '(')
				token_stack.op_push_back(bracket);
			else if (cleaned_str[i] == ')')
			{
				while (token_stack.get_op_size() > 0 && token_stack.op_getLastElem().op != '(')
					token_stack.output_push_back(token_stack.op_pop_back());
				token_stack.op_pop_back();
			}
			++i;
		}
		else
		{
			s_Token op = { .type = OPERATOR, .op = cleaned_str[i] };
			while (token_stack.gt_precedence(op.op))
				token_stack.output_push_back(token_stack.op_pop_back());
			token_stack.op_push_back(op);
			++i;
		}
		// debug print stack
		token_stack.print_output_stack();
	}

	size_t op_size = token_stack.get_op_size();
	for (size_t i = 0; i < op_size; ++i)
	{
		token_stack.output_push_back(token_stack.op_pop_back());
	}
	// debug print stack
	token_stack.print_output_stack();

	return (calculate_rpn(token_stack));
}

// TODO DESTRUCTORS FOR EACH ELEMENTS. CHECK LEAKS.
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " \"expression\"" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << eval(av[1]) << std::endl;
	return 0;
}
