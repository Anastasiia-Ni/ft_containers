#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace   ft
{
    template <class Iterator>
    class   reverse_iterator
    {
        public:
            typedef  Iterator                               iterator_type;
            typedef  typename   Iterator::value_type        value_type;
            typedef  typename   Iterator::pointer           pointer;
            typedef  typename   Iterator::reference         reference;
            typedef  ptrdiff_t                              difference_type;
            typedef  typename Iterator::iterator_category   iterator_category;

            reverse_iterator(void): _reverse_ptr(NULL){}

            reverse_iterator(iterator_type it): _reverse_ptr(it) {}
            
            template <typename U>
            reverse_iterator(const reverse_iterator<U>& other): _reverse_ptr(other.base()){}

            reverse_iterator&   operator=(const reverse_iterator& rhs){
                this->_reverse_ptr = rhs._reverse_ptr;
                return (*this);
            }

            iterator_type base()const {
                return (_reverse_ptr);
            }	

            reference operator*() const { 			
			    return (*(_reverse_ptr - 1));
            }

            pointer operator->() { 
                return (&operator*()); 
            }

            reverse_iterator& operator++() { 
                --_reverse_ptr; return *this; 
            }  

            reverse_iterator operator++(int) { 
                reverse_iterator tmp = *this; 
                ++(*this); 
                return tmp; 
            }
            
            reverse_iterator& operator--() { 
                ++_reverse_ptr; 
                return *this; 
            }  

            reverse_iterator operator--(int) { 
                reverse_iterator tmp = *this; 
                --(*this); 
                return tmp; 
            }

            reverse_iterator    operator+(difference_type n) const { 
                return (_reverse_ptr - n); 
            }

            reverse_iterator    operator-(difference_type n) const { 
                return (_reverse_ptr + n); 
            }
            
			reverse_iterator& operator+=(difference_type num) {
				_reverse_ptr = _reverse_ptr - num;
				return (*this);
			}	
			
			reverse_iterator& operator-=(difference_type num) {
				_reverse_ptr = _reverse_ptr + num;
				return (*this);
			}

            value_type& operator[](difference_type num) {
				return (*(_reverse_ptr - num - 1));
			}

        private:
            iterator_type  _reverse_ptr;
    };

    template<typename T>
    bool  operator==(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (lhs.base() == rhs.base()); 
    }
    
    template<typename T1, typename T2>
    bool operator==(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (lhs.base() == rhs.base()); 
    }

    template<typename T>
    bool  operator!=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (lhs.base() != rhs.base()); 
    }
    
    template<typename T1, typename T2>
    bool operator!=(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (lhs.base() != rhs.base()); 
    }
    
    template<typename T>
    bool  operator>(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (lhs.base() < rhs.base()); 
    }
    
    template<typename T1, typename T2>
    bool operator>(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (lhs.base() < rhs.base()); 
    }

    template<typename T>
    bool  operator<(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (lhs.base() > rhs.base()); 
    }
   
    template<typename T1, typename T2>
    bool operator<(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (lhs.base() > rhs.base()); 
    }

    template<typename T>
    bool  operator>=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (lhs.base() <= rhs.base()); 
    }
    
    template<typename T1, typename T2>
    bool operator>=(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (lhs.base() <= rhs.base()); 
    }

    template<typename T>
    bool  operator<=(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (lhs.base() >= rhs.base()); 
    }
    
    template<typename T1, typename T2>
    bool operator<=(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (lhs.base() >= rhs.base()); 
    }

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type operator-(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (rhs.base() - lhs.base()); 
    }

    template<typename T1, typename T2>
    typename ft::reverse_iterator<T1>::difference_type operator-(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (rhs.base() - lhs.base()); 
    }

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type operator+(const ft::reverse_iterator<T> lhs, const ft::reverse_iterator<T> rhs){ 
        return (lhs.base() + rhs.base()); 
    }

    template<typename T1, typename T2>
    typename ft::reverse_iterator<T1>::difference_type operator+(const ft::reverse_iterator<T1> lhs, const ft::reverse_iterator<T2> rhs){ 
        return (lhs.base() + rhs.base()); 
    }

    template<typename T> ft::reverse_iterator<T> operator+(
        typename ft::reverse_iterator<T>::difference_type x,
        typename ft::reverse_iterator<T>& rhs){ 
            return (rhs + x); 
        }
}

#endif
