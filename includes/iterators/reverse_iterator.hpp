#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterators_traits.hpp"

namespace ft
{
	template <typename Iterator>
	class reverse_iterator {
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

		private:
			iterator_type	_ri;

		public:
			reverse_iterator() { iterator_type(); }

			reverse_iterator(iterator_type it) {
				_ri = it;
			}

            template <typename Iter>
            reverse_iterator(const reverse_iterator<Iter>& rev_it) {
                _ri = rev_it.base();
            }

            reverse_iterator operator=(const reverse_iterator& rhs) {
                _ri = rhs.base();
                return (*this);
            }

            ~reverse_iterator() {}

            iterator_type		base() const {
                return (_ri);
            }

            reference			operator*() const {
                return *(_ri - 1);
            }

            pointer				operator->() const {
                return &(operator*());
            }

            reference			operator[](difference_type n) const {
                return (base()[-n - 1]);
            }

            reverse_iterator	operator+(difference_type n) const {
                return (reverse_iterator(_ri - n));
            }

            reverse_iterator	operator-(difference_type n) const {
                return (reverse_iterator(_ri + n));
            }

            reverse_iterator&	operator++() {
                --_ri;
                return (*this);
            }

            reverse_iterator	operator++(int) {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

            reverse_iterator&	operator--() {
                ++_ri;
                return (*this);
            }

            reverse_iterator	operator--(int) {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }

            reverse_iterator&	operator+=(difference_type n) {
                _ri -= n;
                return (*this);
            }

            reverse_iterator&	operator-=(difference_type n) {
                _ri += n;
                return (*this);
            }
    };

    template <typename Iter>
    bool operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
        return (lhs.base() == rhs.base());
    }

    template <typename Iter>
    bool operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
        return (lhs.base() != rhs.base());
    }

    template <typename Iter>
    bool operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
        return (lhs.base() > rhs.base());
    }

    template <typename Iter>
    bool operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
        return (lhs.base() >= rhs.base());
    }

    template <typename Iter>
    bool operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
        return (lhs.base() < rhs.base());
    }

    template <typename Iter>
    bool operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
        return (lhs.base() <= rhs.base());
    }

    template <typename Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rhs) {
        return (rhs + n);
    }

    template <typename Iter>
    typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
        return (rhs.base() - lhs.base());
    }
}

#endif
