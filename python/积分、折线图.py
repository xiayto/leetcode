import numpy as np
from scipy.integrate import quad,dblquad,nquad

#求积分
res, error = quad(lambda x:(np.log(x+2)-np.log(x+1))/np.log(50+1), 0, 50)
#求二重积分
res2, error2 = dblquad(lambda t,x:np.exp(-x*t)/t**3,0,np.inf,lambda x:1,lambda x:np.inf)

#画折线图
import matplotlib.pyplot as plt
def plot_line_chart(x_min, x_max, function):
    x = [(x_max-x_min)/20*i for i in range(20)]
    y = list(map(function, x))
    plt.plot(x, y)
    plt.show()
    
def function(x):
    return (np.log(x+2)-np.log(x+1))/np.log(50+1)

plot_line_chart(0, 50, function)
