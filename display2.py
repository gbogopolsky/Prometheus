import numpy as np
import matplotlib.pyplot as plt

sortie = np.loadtxt('vaisseau.dat')
temps = sortie[:,0]*0.020
a_x = sortie[:,1]
a_y = sortie[:,2]
x = sortie[:,3]
y = sortie[:,4]

fig = plt.figure()

plt.subplot(211)
plt.plot(temps, a_x, label='a_x')
plt.plot(temps, a_y, label='a_y')
plt.title('Accélération, vitesse et position en fonction du temps')
plt.legend()
# plt.title('Accélération en fonction du temps')
plt.ylabel('a(t)')

plt.subplot(212)
plt.plot(temps, x, label='x')
plt.plot(temps, y, label='y')
plt.legend()
# plt.title('Position en fonction du temps')
plt.ylabel('x(t) et y(t)')
plt.xlabel('Temps en s')

plt.show()
