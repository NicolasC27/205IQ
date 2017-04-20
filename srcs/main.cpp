//
// main.cpp for 205IQ in /home/ikirame/Documents/Projects/205IQ/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Mon Apr 10 17:33:14 2017 Valentin Gérard
// Last update Thu Apr 20 15:23:49 2017 Valentin Gérard
//

#include "IQ.hpp"

static bool	IQ_2(double mu, double sigma)
{
  IQ		iq(mu, sigma);
  int		t;

  t = 0;
  while (t < 200)
    {
      std::cout << t << std::setprecision(2) << std::fixed << " " << iq.normale(t) * 100 << std::endl;
      t++;
    }
  return (true);
}

static bool	IQ_3(double mu, double sigma, double IQ1)
{
  IQ		iq(mu, sigma, IQ1);

  std::cout << std::setprecision(1) << std::fixed << iq.probabilite(IQ1) * 100 << "% of people have a IQ inferior to " << std::setprecision(0) << IQ1 << std::endl;
  return (true);
}

static bool	IQ_4(double mu, double sigma, double IQ1, double IQ2)
{
  IQ		iq(mu, sigma, IQ1, IQ2);

  std::cout << std::setprecision(1) << std::fixed << (iq.probabilite(IQ2) - iq.probabilite(IQ1)) * 100 << "% of people have a IQ between " << std::setprecision(0) << IQ1 << " and " << IQ2 << std::endl;
  return (true);
}

int	main(int ac, char *av[])
{
  if (ac < 2 || ac > 6)
    return (EXIT_FAILED);
  if (ac == 2 && strcmp(av[1], "-h") == 0)
    help();
  else if (ac == 3 && isNumber(av[1]) && isNumber(av[2]))
    {
      if (!IQ_2(atof(av[1]), atof(av[2])))
	return (EXIT_FAILED);
    }
  else if (ac == 4 && isNumber(av[1]) && isNumber(av[2]) && isNumber(av[3]))
    {
      if (!IQ_3(atof(av[1]), atof(av[2]), atof(av[3])))
	return (EXIT_FAILED);
    }
  else if (ac == 5 && isNumber(av[1]) && isNumber(av[2]) && isNumber(av[3]) && isNumber(av[4]))
    {
      if (!IQ_4(atof(av[1]), atof(av[2]), atof(av[3]), atof(av[4])))
	return (EXIT_FAILED);
    }
  else
    return (EXIT_FAILED);
  return (EXIT_SUCCESS);
}
