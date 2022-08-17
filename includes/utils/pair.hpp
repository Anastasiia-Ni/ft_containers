#include "../containers.hpp"

# ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;
		
		pair() : first(T1()), second(T2()) {}

		template<class U, class V>
		pair (const pair<U,V> &other) : first(other.first), second(other.second) {};

		pair(const first_type &x, const second_type &y) : first(x), second(y) {}

		~pair() {};

		pair &operator=(const pair &rhs)
		{
			if (*this != rhs) {
				this->first = rhs.first;
				this->second = rhs.second;
			}
			return (*this);
		}
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return (pair<T1,T2>(x,y));
	}

	template <class T1, class T2>
	inline bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs < rhs));
	}

    template<typename Arg1, typename Arg2, typename Result>
	struct binary_function {
		typedef Arg1	frist_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};
	
	template<typename T>
	struct less: binary_function<T,T,bool> {
		bool operator()(const T& x, const T& y) const {
			return (x < y);
		}
	};
};

#endif
