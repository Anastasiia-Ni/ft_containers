
#include "includes/containers.hpp"

int main(void)
{
	std::string input;
	std::cout << MAGENTA << "\n\t\tEnter the name of the container:" << std::endl;
	std::cout << "\t\tLIST, STACK, VECTOR, QUEUE, MAP, ALL" << std::endl;
	std::cout << "\n>>  ";
	std::cin >> input;
	for (unsigned int i = 0; i < input.size(); i++)
		input[i] = (char)toupper(input[i]);
	std::cout << input << std::endl << std::endl; // delete
	while (1){
		if (input == "VECTOR"){
			test_vector();
			break ;
        }
		else if (input == "STACK"){
            //test_stack();
            break ;
		}
		else if (input == "QUEUE"){
            //test_queue();
            break ;
		}
		else if (input == "LIST"){
            //test_list();
			break ;
		}
		else if (input == "MAP"){
            //test_map();
            break ;
		}
		else if (input == "ALL"){
            // test_list();
            // test_map();
            // test_vector();
            // test_queue();
            // test_stack();
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
