//
// IQ.hpp for 205IQ in /home/ikirame/Documents/Projects/205IQ/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Mon Apr 10 17:13:54 2017 Valentin Gérard
// Last update Mon Apr 10 19:43:16 2017 Valentin Gérard
//

#ifndef IQ_HPP_
# define IQ_HPP_

# define EXIT_FAILED 84
# define EXIT_SUCCESS 0

# include <iostream>
# include <cmath>
# include <cstring>
# include <cstdbool>
# include <iomanip>
# include <cstdlib>

class IQ
{
private:
  double	_mu;
  double	_gamma;
  double	_IQ1;
  double	_IQ2;

public:
  IQ(double mu, double gamma = 0, double IQ1 = 0, double IQ2 = 0);
  ~IQ();

  double	normale(double t);
  double	probabilite(double v);
};

void	help(void);
bool	isNumber(const std::string &str);

#endif /* !IQ_HPP_ */
