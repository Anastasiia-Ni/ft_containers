# ifndef STACK_HPP
#define STACK_HPP

#include "containers.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	private:
		container_type      _contr;
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit stack (const container_type& ctnr = container_type()) : _contr(ctnr) {}

		virtual ~stack(){};

		stack &operator=(Stack const &other){
			this->_contr = other._contr;
				return (*this);
		}

		//stack(const Stack &copy){_contr = copy._contr;}; ???

		reference top();
		const_reference top() const;
		
		bool empty() const {
			return (_contr.empty());
		}

		size_type size() const {
			return (_contr.size());
		}

		void push( const value_type& value ) {
			return (_contr.push_back(val));
		}

		void pop() {
			return (_contr.pop_back());
		}

		template <class T, class Container>
		bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._contr == _rhs.contr);
		}

		bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.contr != rhs.contr);
		}

		bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.contr < rhs.contr);
		}

		bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.contr <= rhs.contr);
		}

		bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.contr > rhs.contr);
		}

		bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.contr >= rhs.contr);
		}
    };
};

#endif
