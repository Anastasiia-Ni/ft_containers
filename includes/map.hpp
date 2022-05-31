# ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"
namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
	{
		public:
			typedef Key                                     key_type;
			typedef T                                       mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
            //size_type;
            //difference_type
            //key_compare
            //allocator_type
            //reference
            //const_reference
            //pointer
            //const_pointer
            //iterator
            //const_iterator
            //reverse_iterator
            //const_reverse_iterator

			private:
			// protected:
			// 	Compare comp;
			// 	value_compare(Compare c) : comp(c)
			// 	{}

			//public:

			map() {

			}
			~map() {

			}
			operator=() {

			}
			get_allocator(){

			}
			at(){

			}
			operator[]() {

			}
			begin() {

			}
			end() {

			}
			rbegin() {

			}
			rend() {

			}
			empty() {

			}
			size() {

			}
			max_size() {

			}
			clear() {

			}
			insert() {

			}
			erase() {

			}
			swap() {

			}
			count() {

			}
			find() {

			}
			equal_range() {

			}
			lower_bound() {

			}
			upper_bound() {

			}
			key_comp() {

			}
			value_comp() {

			}
    };
};

operator==(){

}
operator!=(){

}
operator<() {

}
operator<=() {

}
operator>() {

}
operator>=() {

}

swap


#endif
