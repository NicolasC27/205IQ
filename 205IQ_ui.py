#!/usr/bin/python2.7

import matplotlib.pyplot as plt
import math
import sys
import numpy as np

def help():
    print ("USAGE\n")
    print ("./205QI mu sigma [IQ1] [IQ2]\n")
    print ("DESCRIPTION\n")
    print ("mu predetermined mean")
    print ("sigma pedetermined standard deviation")
    print ("IQ1 minimum IQ")
    print ("IQ2 maximum IQ")
    exit()

def parser():
    try:
        mu = int(sys.argv[1])
        gamma = int(sys.argv[2])
    except:
        print ("./205QI -h to use the program.")
        exit()
    qimin = 0
    qimax = 200
    if len(sys.argv) == 4:
        qimin = int(sys.argv[3])
    if len(sys.argv) > 4:
        qimin = int(sys.argv[3])
        qimax = int(sys.argv[4])
    draw_lines(qimin, qimax, mu, gamma)

def draw_lines(qimin, qimax, mu, gamma):
    probability = 0
    result = 0
    x = []
    y = []
    while qimin < qimax:
        prob = (1 / (gamma * np.sqrt(2 * np.pi)))
        prob *= np.exp(-(pow(qimin - mu, 2) / (pow(gamma, 2) * 2)))
        result += prob

        y.append(result)
        x.append(qimin)
        qimin += 0.01
        probability = 0
    try:
        plt.plot(x, y, color='#ff0004', label='distribution', linewidth=3)
    except:
        print("Problem display")

def board():
    try:
        plt.title('Intelligence Quotient', fontsize=20)
        plt.ylabel('Probability (%)', fontsize=15)
        plt.xlabel('QI', fontsize=15)
        plt.legend()
        plt.show()
    except:
        print ("Problem display")

def main():
    try:
        sys.argv[1]
    except:
        print ("./205QI -h to use the program.")
        exit()
    if sys.argv[1] == "-h":
        help()
    parser()
    board()

main()