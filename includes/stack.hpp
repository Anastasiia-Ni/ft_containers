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
		typedef Container	container_type;
		typedef size_t		size_type;

	private:
		container_type		_contr;

	public:
		explicit stack (const container_type& ctnr = container_type()) : _contr(ctnr) {}

		virtual ~stack(){};

		stack &operator=(stack const &other){
			this->_contr = other._contr;
				return (*this);
		}

		stack(const stack &copy){
			this->_contr = copy._contr;
		}

		// reference top() {		//check reference type
		// 	return (this->_contr.back());
		// }

		// const_reference top() const {	//check reference type
		// 	return (this->_contr.back());
		// }

		bool empty() const {
			return (this->_contr.empty());
		}

		size_type size() const {
			return (this->_contr.size());
		}

		void push( const value_type& value ) {
			return (this->_contr.push_back(value));
		}

		// void pop() {
		// 	return (this->_contr.pop_back());
		// }

		// template <class T, class Container>
		// bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		// 	return (lhs._contr == _rhs.contr);
		// }

		// bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		// 	return (lhs.contr != rhs.contr);
		// }

		// bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		// 	return (lhs.contr < rhs.contr);
		// }

		// bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		// 	return (lhs.contr <= rhs.contr);
		// }

		// bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		// 	return (lhs.contr > rhs.contr);
		// }

		// bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		// 	return (lhs.contr >= rhs.contr);
		// }
    };
};

#endif
