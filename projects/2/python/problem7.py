from os import read
import numpy as np
import matplotlib
matplotlib.rcParams['text.usetex'] = True
import matplotlib.pyplot as plt
from matplotlib import colors as mcolors
colors = dict(mcolors.BASE_COLORS, **mcolors.CSS4_COLORS)

# the mesh points x
x = np.linspace(0,1,11)


analytic_eigenvec_0 = np.array([
                               0.0,
                               1.3819660113e-01,
                               2.6286555606e-01,
                               3.6180339887e-01,
                               4.2532540418e-01,
                               4.4721359550e-01,
                               4.2532540418e-01,
                               3.6180339887e-01,
                               2.6286555606e-01,
                               1.3819660113e-01,
                                0.0
                              ])
analytic_eigenvec_1 = np.array([
                               0.0,
                                2.6286555606e-01,
                                4.2532540418e-01,
                                4.2532540418e-01,
                                2.6286555606e-01,
                                5.4767869826e-17,
                               -2.6286555606e-01,
                               -4.2532540418e-01,
                               -4.2532540418e-01,
                               -2.6286555606e-01,
                               0.0
                                ])

analytic_eigenvec_2 = np.array([
                               0.0,
                                3.6180339887e-01,
                                4.2532540418e-01,
                                1.3819660113e-01,
                               -2.6286555606e-01,
                               -4.4721359550e-01,
                               -2.6286555606e-01,
                                1.3819660113e-01,
                                4.2532540418e-01,
                                3.6180339887e-01,
                               0.0
                               ])
# 3 lowest Jacobi rotation eigenvalues of A
jacobi_rot_eigenvec_0 = np.array([
                                0.0,
                                1.3820e-01,
                                2.6287e-01,
                                3.6180e-01,
                                4.2533e-01,
                                4.4721e-01,
                                4.2533e-01,
                                3.6180e-01,
                                2.6287e-01,
                                1.3820e-01,
                                0.0
                                ])

jacobi_rot_eigenvec_1 = np.array([
                                0.0,
                                2.6287e-01,
                                4.2533e-01,
                                4.2533e-01,
                                2.6287e-01,
                                2.4954e-11,
                               -2.6287e-01,
                               -4.2533e-01,
                               -4.2533e-01,
                               -2.6287e-01,
                                0.0
                                ])

jacobi_rot_eigenvec_2 = -1*np.array([
                                0.0,
                                -3.6180e-01,
                                -4.2533e-01,
                                -1.3820e-01,
                                 2.6287e-01,
                                 4.4721e-01,
                                 2.6287e-01,
                                -1.3820e-01,
                                -4.2533e-01,
                                -3.6180e-01,
                                0.0
                                ])

plt.rcParams["axes.labelsize"] = 17
plt.xticks(fontsize=13)
plt.yticks(fontsize=13)
plt.title(r'Comparison of analytical and Jacobi rotation eigenvectors')
plt.xlabel(r'$\hat{x}_i$')
plt.ylabel(r'$v_i$')
plt.plot(x,jacobi_rot_eigenvec_0,'ro',markersize=1.5,label='Jacobi 0')
plt.plot(x,jacobi_rot_eigenvec_1,'go',markersize=1.5,label='Jacobi 1')
plt.plot(x,jacobi_rot_eigenvec_2,'bo',markersize=1.5,label='Jacobi 2')

plt.plot(x,analytic_eigenvec_0,color=colors['lightsalmon'],linewidth=0.1,label='analytical 0')
plt.plot(x,analytic_eigenvec_1,color=colors['lightgreen'],linewidth=0.1,label='analytical 1')
plt.plot(x,analytic_eigenvec_2,color=colors['lightskyblue'],linewidth=0.1,label='analytical 2')


plt.legend(loc=0)
plt.savefig('./output/problem7a.pdf')

