#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef size_t		size_type;
		typedef Container	container_type;


		/* Default Constrctor */
		explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {}

		/* Copy Constrctor */
		stack(const stack &copy){
			this->_cont = copy._cont;
		}

		/*  Destructor */
		virtual ~stack() {}

		/* Assignment operator overload */
		stack &operator=(stack const &rhs){
			if (&rhs != this)
				this->_cont = rhs._cont;
			return (*this);
		}

		/* Element access */
		value_type& top(void) {
			return (this->_cont.back());
		}

		const value_type& top() const {
			return (this->_cont.back());
		}

		/* Capacity */
		bool empty(void) const {
			return (this->_cont.empty());
		}

		size_type size(void) const {
			return (this->_cont.size());
		}

		/* Modifiers */
		void push( const value_type& value ) {
			return (this->_cont.push_back(value));
		}

		void pop(void) {
			return (this->_cont.pop_back());
		}

		/* Overload functions */
		friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._cont == rhs._cont);
		}

		friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._cont != rhs._cont);
		}

		friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._cont < rhs._cont);
		}

		friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._cont <= rhs._cont);
		}

		friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._cont > rhs._cont);
		}

		friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._cont >= rhs._cont);
		}

	private:
		container_type		_cont;

	}; // end of class stack

};	// end of namespace ft

#endif
