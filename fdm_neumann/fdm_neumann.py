import sys
import numpy as np
from scipy.sparse import spdiags
from scipy.sparse.linalg import spsolve

def fd_neumann(n,f,a,b,method)
   """ Solve the two-point bvp -u''(x) = f(x)
       on [0,1] with b.c. u'(0) = a and u(1) = b
       on n + 1 grid points """

   h = 1.0/n     # grid spacing
   xi = np.linspace(0,1,n+1) # vector of grid points
   rhs = h**2*f(xi[:-1])      # Evaluate forcing function
   rhs[-1] += b               # Dirichlet data
  
    if method == 1:            # first-order symmetric
        rhs[0] = -h*a 
        stencil = np.array((-1, 2, -1))   # Approx for 2nd derivative 
        diags = range(-1,2)               # Offsets of diags [-1,0,1]
        bands = np.tile(stencil,(n,1)).T  # Default bands
        bands[1,0] *= 0.5                 # Modify for Neumman 

     elif method == 2:         # second-order nonsymmetric
         rhs[0] = -2*h*a 
         stencil = np.array((-1, 2, -1, 0)) # Approx for 2nd derivative 
         diags = range(-1,3)                # Offsets of diags [-1,0,1,2]
         bands = np.tile(stencil,(n,1)).T   # Default bands
         bands[1,0] = 3                     # one-sided differences
         bands[2,1] = -4
         bands[3,2] = 1

     elif method == 3:         # second-order symmetric 
         rhs[0] *= 0.5
         rhs[0] -= h*a 
         stencil = np.array((-1, 2, -1))    # Approx for 2nd derivative 
         diags = range(-1,2)                # Offsets of diags [-1,0,1]
         bands = np.tile(stencil,(n,1)).T   # Default bands
         bands[1,0] *= 0.5                  # Modify for Neumman 

    A = spdiags(bands,diags,n,n).tocsc()    # Form sparse matrix

    u = np.zeros(n+1)
    u[-1] = b                               # Set boundary value
    u[:-1] = spsolve(A,rhs)

    return xi, u
