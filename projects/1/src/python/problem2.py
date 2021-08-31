from os import read
import numpy as np
import matplotlib.pyplot as plt


inFile = open('../data/x_u.dat', 'r')

# read the header
line = inFile.readline()
col1, col2 = line.split()

# read data into numpy ndarray
data = np.loadtxt(inFile,skiprows=2)

plt.plot(data[:,0], data[:,1])
plt.xlabel(r'$'+col1+'$')
plt.ylabel(r'$'+col2+'$')
plt.show()