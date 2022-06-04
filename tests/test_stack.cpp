#include "../includes/containers.hpp"

//template <class stack>

static void empty_test() {
	std::cout << "Test empty:\t\t\t";
	// std::stack<int, std::list<int> > Std_stack;
    // ft::stack<int, ft::List<int> > My_stack;
    // if (Std_stack.empty() != My_stack.empty())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // Std_stack.push(42);
    // My_stack.push(42);
    // if (Std_stack.empty() != My_stack.empty())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // std::cout << SUCS << std::endl;	
}

static void size_test() {
	std::cout << "Test size:\t\t\t";
	//     std::stack<int, std::list<int> > Std_stack;
    // ft::Stack<int, ft::List<int> > My_stack;
    // if (Std_stack.size() != My_stack.size())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // for(int i = 0; i < 10; i++)
    // {
    //     Std_stack.push(21);
    //     My_stack.push(21);
    // }
    // if (Std_stack.size() != My_stack.size())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // std::cout << SUCCESS << std::endl;

}

static void top_test() {
    std::cout << "Test top:\t\t\t";
	//     std::stack<int, std::list<int> > Std_stack;
    // ft::Stack<int, ft::List<int> > My_stack;
    // if (Std_stack.size() != My_stack.size())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // Std_stack.push(42);
    // My_stack.push(42);
    // if (Std_stack.top() != My_stack.top())
    // {
    //     std::cout << "Std Stack top - " << Std_stack.top() << std::endl;
    //     std::cout << "My Stack top - " << My_stack.top() << std::endl;
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // std::cout << SUCCESS << std::endl;

}

static void pop_test() {
    std::cout << "Test pop:\t\t\t";
	//     std::stack<int, std::list<int> > Std_stack;
    // ft::Stack<int, ft::List<int> > My_stack;
    // Std_stack.push(42);
    // My_stack.push(42);
    // if (Std_stack.size() != My_stack.size())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // My_stack.pop();
    // Std_stack.pop();
    // if (Std_stack.empty() != My_stack.empty())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // std::cout << SUCCESS << std::endl;

}

static void push_test() {
    std::cout << "Test push:\t\t\t";
	//     std::stack<int, std::list<int> > Std_stack;
    // ft::Stack<int, ft::List<int> > My_stack;
    // Std_stack.push(42);
    // My_stack.push(42);
    // if (Std_stack.size() != My_stack.size())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // Std_stack.push(21);
    // My_stack.push(21);
    // if (Std_stack.size() != My_stack.size())
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // std::cout << SUCCESS << std::endl;

}

static void compare_test() {
    std::cout << "Test compare:\t\t\t";
	//     std::stack<int, std::list<int> > Std_stack_1;
    // ft::Stack<int, ft::List<int> > My_stack_1;
    // std::stack<int, std::list<int> > Std_stack_2;
    // ft::Stack<int, ft::List<int> > My_stack_2;
    // My_stack_1.push(21);
    // Std_stack_1.push(21);
    // My_stack_2.push(42);
    // Std_stack_2.push(42);
    // if ((My_stack_1 == My_stack_2) != (Std_stack_1 == Std_stack_2))
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // if ((My_stack_1 != My_stack_2) != (Std_stack_1 != Std_stack_2))
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // if ((My_stack_1 > My_stack_2) != (Std_stack_1 > Std_stack_2))
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // if ((My_stack_1 >= My_stack_2) != (Std_stack_1 >= Std_stack_2))
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // if ((My_stack_1 < My_stack_2) != (Std_stack_1 < Std_stack_2))
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // if ((My_stack_1 <= My_stack_2) != (Std_stack_1 <= Std_stack_2))
    // {
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // std::cout << SUCCESS << std::endl;
}

int test_stack( void ){
	std::cout << MAGENTA << "-------------------------------" << std::endl;
	std::cout << "     STACK TESTER IS HERE" << std::endl;
	std::cout << "-------------------------------" << RESET << std::endl;

	std::cout << GREEN << "STD STACK" << RESET << std::endl;
    std::vector<int> std_vec(100);
    std::stack<int, std::vector<int> > std_stack1;
    std::stack<int, std::vector<int> > std_stack2(std_vec);
    std::cout << "Size of first: " << std_stack1.size() << std::endl;
    std::cout << "Size of second: " << std_stack2.size() << std::endl;

	std::cout << GREEN << "MY STACK" << RESET << std::endl;
	ft::vector<int> my_vec(100);
	ft::stack<int, ft::vector<int> > my_stack1;
	ft::stack<int, ft::vector<int> > my_stack2(my_vec);
	std::cout << "Size of first: " << my_stack1.size() << std::endl;
	std::cout << "Size of second: " << my_stack2.size() << std::endl;
	
	std::cout << "Test default constructor:\t\t\t";
	if (std_stack2.size() != my_stack2.size())
		std::cout << FAIL << std::endl;
	else
		std::cout << SUCS << std::endl;

    empty_test();
    size_test();
    top_test();
    pop_test();
    push_test();
    compare_test();
	
	return (0);
}