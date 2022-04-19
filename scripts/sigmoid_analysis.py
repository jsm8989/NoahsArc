import numpy as np
import matplotlib.pyplot as plt




# define sigmoidal curve
def Hill(x,n=3):
	"""
	Takes single value x and Hill coefficient [3] and outputs the function (x^n)/(1+x^n)
	"""
	return (x**n)/(1+x**n)

Hill=np.vectorize(Hill)

# compact all into a function to generate sigmoids
def generate_curves(x_range=5, Hill_coeff = 3, verbose=False):
	"""
	In case of generating many similar curves later might be useful to function this
	"""

	x=np.linspace(0,x_range)
	if verbose: print("x: ", np.shape(x))
	

	y=(Hill(x))

	if verbose: print("y: ", np.shape(y))
	return x,y


#plt.plot(x,y)
#plt.show()


curve = generate_curves(x_range=10)
# now want to find the maximum tangent, initial tangent and characteristic saturation time
x,y=curve[0],curve[1]

tangents = [0]
i=1
while i < (len(x)):
# assuming len(x) == len(y)
	tangents.append(np.tan(y[i]/x[i]))
	i+=1

initial_tangent = tangents[1]
max_tangent = np.max(tangents)

print("initial tangent: ", initial_tangent)
print("max tangent: ", max_tangent)



plt.plot(x,y)
plt.title("Original sigmoidal curve")
plt.show()


plt.close()

#del x[0]
plt.plot(x,tangents)
plt.title("Gradient of sigmoidal curve")
plt.show()



# now have gradients (ie rates); need to think about saturation time.
## possible ideas: when the gradient falls to 37% of its max value
## when I/(I_sat) > x where x~0.99
# what are the relative merits of each?...
