#include "../includes/containers.hpp"
//#include "../includes/vector.hpp"

static void	test_constructor()
{

}

static void	test_iterator()
{

}

static void	test_size()
{

}

static void	test_begin_end()
{

}

static void	test_capacity()
{

}

static void	test_at()
{

}

static void	test_operator()
{

}

static void	test_push_back()
{

}

static void	test_pop_back()
{

}

static void	test_insert();
static void	test_emty();
static void	test_erase();
static void	test_assign();
static void	test_swap();
static void	test_clear();



int test_vector( void )
{
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