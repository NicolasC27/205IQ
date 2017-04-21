#!/usr/bin/python2

import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
import math
import sys
import numpy as np

def help():
    print ("USAGE\n")
    print ("./205QI [graphic] mu sigma [IQ1] [IQ2]\n")
    print ("DESCRIPTION\n")
    print ("graphic type 1 for the histogram or 0 for curse.")
    print ("mu predetermined mean")
    print ("sigma pedetermined standard deviation")
    print ("IQ1 minimum IQ")
    print ("IQ2 maximum IQ")
    exit()

def parser():
    histo = 0
    if int(sys.argv[1]) == 1:
        histo = 1
    try:
        mu = int(sys.argv[2])
        gamma = int(sys.argv[3])
    except:
        print ("./205QI -h to use the program.")
        exit()
    qimin = 0
    qimax = 200

    if histo == 1:
        if len(sys.argv) == 5:
            print("./205QI 1 [mu] [gamma] only two argument.")
            exit(0)
    if len(sys.argv) == 5:
        qimin = int(sys.argv[4])
    if len(sys.argv) > 5:
        qimin = int(sys.argv[4])
        qimax = int(sys.argv[5])

    draw_lines(qimin, qimax, mu, gamma, histo)
    board(mu, gamma, histo)

def histogram(mu, gamma, labelx):
    np.random.seed(19680801)
    x = mu + gamma * np.random.randn(10000)
    fig = plt.figure()
    ax = fig.add_subplot(111)
    n, bins, patches = plt.hist(x, 50, normed=1, facecolor='g', alpha=0.75)
    bincenters = 0.5 * (bins[1:] + bins[:-1])
    y = mlab.normpdf(bincenters, mu, gamma)
    l = ax.plot(bincenters, y, 'r--', linewidth=1)
    plt.axis([x, y, 1, 0.3])



def draw_lines(qimin, qimax, mu, gamma, histo):
    probability = 0
    result = 0
    x = []
    y = []
    labelx = (mu / 2) + 10
    while qimin < qimax:
        probability = (1 / (gamma * np.sqrt(2 * np.pi)))
        probability *= np.exp(-(pow(qimin - mu, 2) / (pow(gamma, 2) * 2)))
        result += probability

        y.append(result)
        x.append(qimin)

        qimin += 0.01
        probability = 0
    try:
        if histo == 1:
            histogram(mu, gamma, labelx)
        else:
            plt.plot(x, y, color='#ff0004', label='distribution', linewidth=3)
            plt.text(50, labelx, r'$\mu=$')
            plt.text(62, labelx, mu)
            plt.text(72, labelx, r', $\sigma=$')
            plt.text(89, labelx, gamma)

    except:
        print("Problem display")

def board(mu, gamma, histo):
    try:
        if histo == 1:
            plt.title(r'$\mathrm{Histogram\ of\ IQ:}\ \mu=%s,\ \sigma=%s $'%(mu, gamma))
            plt.ylabel('Probability', fontsize=15)
        else:
            plt.title('Intelligence Quotient', fontsize=20)
            plt.ylabel('Probability', fontsize=15)
        plt.xlabel('QI', fontsize=15)
        plt.legend()
        plt.grid(True)
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

main()