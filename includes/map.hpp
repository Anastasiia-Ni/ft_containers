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
            typedef size_t									size_type;
            //difference_type
            //key_compare
            //allocator_type
            typedef T&										reference;
            typedef T const & 								const_reference;
            typedef T*										pointer;
            typedef const T*								const_pointer;
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

			map& operator=(const map& other) {

			}

			allocator_type get_allocator() const{

			}

			T& at(const Key& key){

			}

			const T& at(const Key& key) const {

			}

			T& operator[](const Key& key) {

			}

			iterator begin() {

			}

			const_iterator begin() const {

			}

			iterator end() {

			}

			const_iterator end() const {

			}

			reverse_iterator rbegin() {

			}

			const_reverse_iterator rbegin() const {

			}

			reverse_iterator rend() {

			}

			const_reverse_iterator rend() const {

			}

			bool empty() const {

			}

			size_type size() const {

			}

			size_type max_size() const {

			}

			void clear() {

			}
			ft::pair<iterator, bool> insert(const value_type& value) {

			}

			iterator insert(iterator hint, const value_type& value) {

			}

			template <class InputIt>
			void insert( InputIt first, InputIt last ){

			}

			void erase(iterator pos) {

			}

			void erase(iterator first, iterator last) {

			}

			size_type erase( const Key& key ) {

			}

			void swap(map& other) {

			}

			size_type count(const Key& key) const {

			}

			iterator find(const Key& key) {

			}

			const_iterator find(const Key& key) const {

			}

			ft::pair<iterator,iterator> equal_range(const Key& key) {

			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {

			}

			iterator lower_bound(const Key& key) {

			}

			const_iterator lower_bound(const Key& key) const {

			}

			iterator upper_bound(const Key& key) {

			}

			const_iterator upper_bound(const Key& key) const {

			}
			
			key_compare key_comp() const {

			}

			std::map::value_compare value_comp() const {

			}
    };
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const std::map<Key,T,Compare,Alloc>& lhs,
					const std::map<Key,T,Compare,Alloc>& rhs) {

	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const std::map<Key,T,Compare,Alloc>& lhs,
					const std::map<Key,T,Compare,Alloc>& rhs){

	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const std::map<Key,T,Compare,Alloc>& lhs,
					const std::map<Key,T,Compare,Alloc>& rhs){

	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const std::map<Key,T,Compare,Alloc>& lhs,
					const std::map<Key,T,Compare,Alloc>& rhs){

	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const std::map<Key,T,Compare,Alloc>& lhs,
					const std::map<Key,T,Compare,Alloc>& rhs){

	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const std::map<Key,T,Compare,Alloc>& lhs,
					const std::map<Key,T,Compare,Alloc>& rhs){

	}
};

//swap()*/


#endif
