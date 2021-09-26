from os import read
import numpy as np
import matplotlib
matplotlib.rcParams['text.usetex'] = True
import matplotlib.pyplot as plt
from matplotlib import colors as mcolors
colors = dict(mcolors.BASE_COLORS, **mcolors.CSS4_COLORS)


N = np.array([4,5,6,7,8,9,10,11,12,13,14,15,
              16,17,18,19,20,21,22,23,24,25,
              26,27,28,29,30,31,32,33,34,35,
              36,37,38,39,40,41,42,43,44,45,
              46,47,48,49,50])
iterations = np.array([6,31,35,69,91,118,151,195,208,266,293,
                       362,404,473,522,606,653,724,790,893,
                       951,1055,1127,1225,1312,1409,1513,1642,
                       1734,1875,1961,2119,2185,2376,2426,2619,
                       2761,2832,2999,3138,3330,3464,3609,3802,
                       3972,4095,4299])


plt.title(r'Scaling of the number of similarity transformations with \textbf{N}')
plt.xlabel(r'Size of matrix \textbf{A} [\textbf{N}]')
plt.ylabel(r'Number of iterations to convergence')
plt.plot(N,iterations,'ro',markersize=1.5,label='data')
plt.plot(N,iterations,'b',color=colors['lightsteelblue'],linewidth=0.1)
plt.legend(loc=0)
plt.savefig('./output/scaling-with-N.pdf')
