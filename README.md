# 205IQ

Most of the reference curves were created using Gaussians, such as classical weight and height curves. Those curves
seem to describe correctly "normality", and that’s the reason why the Gaussian distribution is also called normal distribution.
The same way, psychometric intelligence tests, named IQ tests, are realized so that results follow a normal distribution.
They are calibrated to match predetermined mean (µ) and standard deviation (σ).
For historical reasons, the mean is always equal to 100.
Regarding standard deviation, it is most often worth 15 (defining the Standard IQ), but could vary (24 for instance for
the Cattell test).
The interpretation of the resulting IQ obviously depends on the calibration of the test.

Your psychiatrist of a brother-in-law, Dr Von Humleit, plans to create his own IQ test, fitting better to the actual
population than previous century classical tests. You have to code a software so that he could calibrate his test, with
3 options :
1. given µ and σ, export the values of the density function of the IQ (for any integer between 0 and 200) to be
drawn by gnuplot,
2. given µ, σ and one IQ value, print the percentage of people with an IQ inferior to this value,
3. given µ, σ and two IQ values, print the percentage of people with an IQ in between those values.
