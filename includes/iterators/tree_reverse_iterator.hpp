#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

namespace ft
{
    template <class Iterator>
    class   tree_reverse_iterator
    {
        public:
            typedef  Iterator                               iterator_type;
            typedef  typename   Iterator::value_type        value_type;
            typedef  typename   Iterator::pointer           pointer;
            typedef  typename   Iterator::reference         reference;
            typedef  ptrdiff_t                              difference_type;
            typedef  typename Iterator::iterator_category   iterator_category;

            tree_reverse_iterator(void): baseIterator(){}

            tree_reverse_iterator(iterator_type it): baseIterator(it) {}

            template <typename U>
            tree_reverse_iterator(const tree_reverse_iterator<U>& other): baseIterator(other.base()){}

            tree_reverse_iterator&   operator=(const tree_reverse_iterator& rhs)
            {
                this->baseIterator = rhs.baseIterator;
                return (*this);
            }

            iterator_type base()const { return (baseIterator); }	

            reference operator*() const 
            { 			
                iterator_type temp = baseIterator;
			    return (*(--temp));
            }

            pointer operator->() const { return (&operator*()); }

            tree_reverse_iterator& operator++() { --baseIterator; return *this; }  

            tree_reverse_iterator operator++(int) { tree_reverse_iterator tmp = *this; ++(*this); return tmp; }
            
            tree_reverse_iterator& operator--() { ++baseIterator; return *this; }  

            tree_reverse_iterator operator--(int) { tree_reverse_iterator tmp = *this; --(*this); return tmp; }

        private:
            iterator_type    baseIterator;
    };

    template<typename T>
    bool  operator==(const ft::tree_reverse_iterator<T> lhs, const ft::tree_reverse_iterator<T> rhs){ return (lhs.base() == rhs.base()); }
    template<typename T1, typename T2>
    bool operator==(const ft::tree_reverse_iterator<T1> lhs, const ft::tree_reverse_iterator<T2> rhs){ return (lhs.base() == rhs.base()); }

    template<typename T>
    bool  operator!=(const ft::tree_reverse_iterator<T> lhs, const ft::tree_reverse_iterator<T> rhs){ return (lhs.base() != rhs.base()); }
    template<typename T1, typename T2>
    bool operator!=(const ft::tree_reverse_iterator<T1> lhs, const ft::tree_reverse_iterator<T2> rhs){ return (lhs.base() != rhs.base()); }
}

#endif