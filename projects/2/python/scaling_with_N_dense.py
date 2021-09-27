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
     15,     28,     46,     63,     85,    111,    131,    172,    203,
    247,    284,    333,    385,    444,    501,    554,    612,    687,
    756,    845,    914,    994,   1062,   1166,   1237,   1345,   1435,
   1550,   1670,   1775,   1877,   2021,   2110,   2246,   2382,   2483,
   2634,   2784,   2928,   3020,   3230,   3362,   3506,   3694,   3815,
   3967,   4146,   4331,   4536,   4695,   4849,   5057,   5257,   5438,
   5597,   5905,   6056,   6271,   6432,   6741,   6972,   7177,   7387,
   7647,   7853,   8099,   8341,   8515,   8761,   9105,   9302,   9558,
   9780,   10168,   10383,   10598,   10975,   11311,   11510,   11827,
   12076,   12326,   12651,   13009,   13238,   13610,   13999,   14180,
   14577,   14936,   15249,   15600,   15818,   16266,   16531,   16980,
   17283
])



plt.rcParams["axes.labelsize"] = 17
# plt.xticks(fontsize=17)
# plt.yticks(fontsize=17)
plt.tight_layout()

plt.title(r'Scaling of the number of similarity transformations with \textbf{N} for dense matrix')
plt.xlabel(r'Size of matrix \textbf{A} [\textbf{N}]')
plt.ylabel(r'Number of iterations to convergence')
plt.plot(N,iterations,'ro',markersize=1.5,label='data')
plt.plot(N,iterations,'b',color=colors['lightsteelblue'],linewidth=0.1)
plt.legend(loc=0)
plt.savefig('./output/scaling-with-N-dense.pdf')
