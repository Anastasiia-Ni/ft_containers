
#include "includes/containers.hpp"

int main(void)
{
	std::string input;
	std::cout << MAGENTA << "\n\t\tEnter the name of the container:" << std::endl;
	std::cout << "\t\tSTACK, VECTOR, MAP, SET, ALL" << std::endl;
	std::cout << "\n>>  ";
	std::cin >> input;
	for (unsigned int i = 0; i < input.size(); i++)
		input[i] = (char)toupper(input[i]);
	//std::cout << input << std::endl << std::endl; // delete
	while (1){
		if (input == "VECTOR"){
			test_vector();
			break ;
        }
		else if (input == "STACK"){
            test_stack();
            break ;
		}
		else if (input == "SET"){
            //test_set();
            break ;
		}
		else if (input == "MAP"){
            test_map();
            break ;
		}
		else if (input == "ALL"){
            test_vector();
            test_stack();
            test_map();
            // test_set();
			break ;
        }
		else{
			std::cout << RED << "ERROR COMMAND" << std::endl;
			break ;
        }
    }
	//run_tests();

	std::cout << MAGENTA << "\nTIME TEST:" << std::endl << std::endl;
	// time_tests_map();
	// time_tests_vector();
	// time_tests_stack();
	//sleep(10);
	return (0);
}
