from os import read
import numpy as np
import matplotlib
matplotlib.rcParams['text.usetex'] = True
import matplotlib.pyplot as plt
from matplotlib import colors as mcolors
colors = dict(mcolors.BASE_COLORS, **mcolors.CSS4_COLORS)


inFile = open('../data/x_u.dat', 'r')

# read the header
line = inFile.readline()
col1, col2 = line.split()

# read data into numpy ndarray
data = np.loadtxt(inFile,skiprows=2)

plt.plot(data[:,0], data[:,1],'ro',markersize=1.5,label='data')
plt.plot(data[:,0], data[:,1],'b',color=colors['lightsteelblue'],linewidth=0.1)
plt.title(r'$1.0 - (1.0 - e^{-10.0})  x - e^{-10.0x}$')
plt.xlabel(r'$'+col1+'$')
plt.ylabel(r'$'+col2+'$')
plt.legend(loc=0)

plt.savefig('../../img/problem2-fig-x-u.pdf')
