#include "../includes/containers.hpp"
//#include "../includes/vector.hpp"

static void	test_constructor(){
	std::cout << "Test default constructor:\t";
	   
	size_t n = 10;
    std::vector<int>std_vec(n);
    ft::vector<int>my_vec(n);
    if (std_vec.size() != my_vec.size())
		std::cout << FAIL << std::endl;
	// if (!test_iterator(std_vec, my_vec)){
	// 	std::cout << FAIL << std::endl;
	// 	return ;
	// }
    // std::vector<int>std_vec1(5, 21);
    // ft::vector<int>my_vec1(5, 21);
    // if (s_vec1.size() != my_vec1.size())
    //     std::cout << FAIL << std::endl;
    // if (!iter_test(s_vec1, my_vec1)){
    //     std::cout << FAIL << std::endl;
    //     return ;
	// }
    // std::vector<std::string>std_vec2(5, "A");
    // ft::Vector<std::string>my_vec2(5, "A");
    // if (s_vec2.size() != my_vec2.size())
    //     std::cout << FAIL << std::endl;
    // if (!iter_test(s_vec2, my_vec2)){
    //     std::cout << FAIL << std::endl;
    //     return ;
	// }
    // std::vector<int> std_vec1(std_vec);
    // ft::vector<int> my_vec1(my_vec);
    // if (std_vec1.size() != my_vec1.size())
    //     std::cout << FAIL << std::endl;
    // if (!iter_test(s_vec1, my_vec1)){
    //     std::cout << FAIL << std::endl;
    //     return ;
	// }
    std::cout << SUCS << std::endl;
}

static void	test_iterator(){

}

static void	test_size(){
	std::cout << "Size test:\t\t\t ";  
	size_t n = 42;
	std::vector<int>std_vec(n);
	ft::vector<int>my_vec(n);
	if (std_vec.size() != my_vec.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::vector<int>std_vec1;
	ft::vector<int>my_vec1;
	if (std_vec1.size() != my_vec1.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_begin_end(){

}

static void	test_capacity(){
    std::cout << "Capacity test:\t\t\t"; 
	size_t n = 142;
	std::vector<int>std_vec(n);
	ft::vector<int>my_vec(n);
	if (std_vec.capacity() != my_vec.capacity()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::vector<int>std_vec1;
	ft::vector<int>my_vec1;
	if (std_vec1.size() != my_vec1.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_at(){
   std::cout << "At test:\t\t\t\t";
	std::vector<int>std_vec;
	ft::vector<int>my_vec;
}

static void	test_operator(){

}

static void	test_push_back(){
	std::cout << "Push_back test:\t\t\t"; 
	size_t n = 42;
	std::vector<int>std_vec;
	ft::vector<int>my_vec;
	for (size_t i = 0; i < n / 2; i++) {
		std_vec.push_back(i);
		my_vec.push_back(i);
	}
	if (std_vec.size() != my_vec.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std_vec.push_back(n);
	my_vec.push_back(n);
	if (std_vec.size() != my_vec.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_pop_back(){

}

static void	test_insert(){

}

static void	test_emty(){

}

static void	test_erase(){

}

static void	test_assign(){

}

static void	test_swap(){

}

static void	test_clear(){

}


int test_vector( void ){
    std::cout << MAGENTA << "-------------------------------" << std::endl;
    std::cout << "     VECTOR TESTER IS HERE" << std::endl;
    std::cout << "-------------------------------" << RESET << std::endl;

    std::vector<int> std_vec;
	ft::vector<int> ft_vec;
	test_constructor();
	test_iterator();
	test_size();
	test_begin_end();
	test_capacity();
	test_at();
	test_operator();
	test_push_back();
	test_pop_back();
	test_insert();
	test_emty();
	test_erase();
	test_assign();
	test_swap();
	test_clear();
    // test_front();
    // test_back();
	return (0);
}