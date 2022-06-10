/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:35 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/06 18:23:44 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STACK_HPP
#define STACK_HPP

#include "containers.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef size_t		size_type;
		typedef Container	container_type;

	private:
		container_type		_cont;

	public:
		explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {}

		virtual ~stack(){};

		stack &operator=(stack const &other){
			this->_cont = other._cont;
				return (*this);
		}

		stack(const stack &copy){
			this->_cont = copy._cont;
		}

		value_type& top(void) {
			return (this->_cont.back());
		}

		const value_type	& top() const {
			return (this->_cont.back());
		}

		bool empty(void) const {
			return (this->_cont.empty());
		}

		size_type size(void) const {
			return (this->_cont.size());
		}

		void push( const value_type& value ) {
			return (this->_cont.push_back(value));
		}

		void pop(void) {
			return (this->_cont.pop_back());
		}

	/* !!!!!!!!! double check friend*/
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
    };
};

#endif
