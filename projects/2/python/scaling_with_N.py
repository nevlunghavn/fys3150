from os import read
import numpy as np
import matplotlib
matplotlib.rcParams['text.usetex'] = True
import matplotlib.pyplot as plt
from matplotlib import colors as mcolors
colors = dict(mcolors.BASE_COLORS, **mcolors.CSS4_COLORS)



N=np.zeros(97)
for i in range(97):
    N[i] = i

iterations = np.array([
    6,   31,   35,   69,   91,  118,  151,  195,  208,  266,
  293,  362,  404,  473,  522,  606,  653,  724,  790,  893,
  951, 1055, 1127, 1225, 1312, 1409, 1513, 1642, 1734, 1875,
 1961, 2119, 2185, 2376, 2426, 2619, 2761, 2832, 2999, 3138,
 3330, 3464, 3609, 3802, 3972, 4095, 4299, 4467, 4668, 4859,
  4985, 5211, 5392, 5596, 5820, 6048, 6179, 6461, 6650, 6837,
 7097, 7345, 7488, 7791, 8021, 8326, 8470, 8793, 9087, 9229,
 9469, 9815,10024,10325,10653,10873,11174,11418,11700,11913,
12297,12627,12866,13141,13563,13895,14148,14439,14707,15037,
15391,15717,16157,16401,16714,17071,17485
])



plt.rcParams["axes.labelsize"] = 17
# plt.xticks(fontsize=17)
# plt.yticks(fontsize=17)
plt.tight_layout()

plt.title(r'Scaling of the number of similarity transformations with \textbf{N}')
plt.xlabel(r'Size of matrix \textbf{A} [\textbf{N}]')
plt.ylabel(r'Number of iterations to convergence')
plt.plot(N,iterations,'ro',markersize=1.5,label='sparse data')
plt.plot(N,iterations,color=colors['lightskyblue'],linewidth=0.1)

plt.legend(loc=0)
plt.savefig('./output/scaling-with-N.pdf')

