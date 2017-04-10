//
// utils.cpp for 205IQ in /home/ikirame/Documents/Projects/205IQ/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Mon Apr 10 18:18:34 2017 Valentin Gérard
// Last update Mon Apr 10 18:35:38 2017 Valentin Gérard
//

#include "IQ.hpp"

void	help(void)
{
  std::cout << "USAGE" << std::endl;
  std::cout << "\t./205IQ mu sigma [IQ1] [IQ2]\n" << std::endl;
  std::cout << "DESCRIPTION" << std::endl;
  std::cout << "\tmu pedetermined mean" << std::endl;
  std::cout << "\tsigma pedetermined standard deviation" << std::endl;
  std::cout << "\tIQ1 minimum IQ" << std::endl;
  std::cout << "\tIQ2 maximum IQ" << std::endl;
}

bool	isNumber(const std::string &str)
{
  std::string::const_iterator it;

  it = str.begin();
  while (it != str.end())
    {
      if (!std::isdigit(*it) and *it != '.')
	return false;
      else
	*it++;
    }
  return true;
}
