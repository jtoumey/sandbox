import sys
import matplotlib.pyplot as plt
from sympy import diff, lambdify, exp, sin
from sympy.abc import u,x

if __name__ == '__main__':
    n = int(sys.argv[1])        # Number of unknowns
    xi = np.linspace(0,1,n+1)   # Grid points
    
    u = exp(x)/(1+x)            # Manufactured solution to test methods
    ux = diff(u,x)              # First derivative
    uxx = diff(ux,x)            # Second derivative
    f = -uxx                    # Forcing function
  
    U = lambdify(x,u,"numpy")   # make u a callable function 
    Ux = lambdify(x,ux,"numpy") # make ux a callable function
    F = lambdify(x,f,"numpy")   # make f a callable function

    a = Ux(0)                   # Neumann boundary value
    b = U(1)                    # Dirichlet boundary value
    
    # Compute solution with all three methods
    xi,u1 = fd_neumann(n,F,a,b,1) 
    xi,u2 = fd_neumann(n,F,a,b,2) 
    xi,u3 = fd_neumann(n,F,a,b,3) 

    # Compute error for each approximation
    uex = U(xi)      # Evaluate exact solution
    e1 = uex-u1
    e2 = uex-u2
    e3 = uex-u3

    print 'h = ', 1.0/n
    print 'The max error of method 1 is:', max(abs(e1))
    print 'The max error of method 2 is:', max(abs(e2))
    print 'The max error of method 3 is:', max(abs(e3))
 
    plt.plot(xi,e1,xi,e2,xi,e3)
    plt.show()
