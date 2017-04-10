//
// IQ.cpp for 205IQ in /home/ikirame/Documents/Projects/205IQ/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Mon Apr 10 17:33:45 2017 Valentin Gérard
// Last update Mon Apr 10 19:51:05 2017 Valentin Gérard
//

#include "IQ.hpp"

IQ::IQ(double mu, double gamma, double IQ1, double IQ2) : _mu(mu), _gamma(gamma), _IQ1(IQ1), _IQ2(IQ2)
{}

IQ::~IQ()
{}

double		IQ::normale(double t)
{
  double	QI;
  double	z;

  z = (t - this->_mu) / this->_gamma;
  QI = (1 / (this->_gamma * sqrt(2 * M_PI))) * exp(-pow(z, 2) / 2);

  return (QI);
}

double		IQ::probabilite(double v)
{
  double	t;
  double	t2;
  double	proba;
  double	probat;
  double	probat2;

  t = 1;
  proba = normale(0);
  while (t <= v)
    {
      t2 = t - 0.5;
      probat = normale(t);
      probat2 = normale(t2);
      proba += (2.0 * probat + 4.0 * probat2) / 6;
      t++;
    }
  proba = proba - normale(v) / 6.0;
  return (proba);
}
