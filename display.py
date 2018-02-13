import numpy as np
import matplotlib.pyplot as plt

sortie = np.loadtxt('vaisseau.dat')
temps = sortie[:,0]*0.020
a_x = sortie[:,1]
a_y = sortie[:,2]
v_x = sortie[:,3]
v_y = sortie[:,4]
x = sortie[:,5]
y = sortie[:,6]

fig = plt.figure()

plt.subplot(311)
plt.plot(temps, a_x, label='a_x')
plt.plot(temps, a_y, label='a_y')
plt.title('Accélération, vitesse et position en fonction du temps')
plt.legend()
# plt.title('Accélération en fonction du temps')
plt.ylabel('a(t)')

plt.subplot(312)
plt.plot(temps, v_x, label='v_x')
plt.plot(temps, v_y, label='v_y')
plt.legend()
# plt.title('Vitesse en fonction du temps')
plt.ylabel('v(t)')

plt.subplot(313)
plt.plot(temps, x, label='x')
plt.plot(temps, y, label='y')
plt.legend()
# plt.title('Position en fonction du temps')
plt.ylabel('x(t) et y(t)')
plt.xlabel('Temps en s')

plt.show()
