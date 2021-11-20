# -*- coding: utf-8 -*-
"""ans 2.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1esUGNxZXwUCjp7e9EE-o8AuVcGfE-PWx
"""

import matplotlib.pyplot as plt 
 

n =[100,1000,5000]
length= len(n)

for j  in range(length):
  trials=n[j]
  z1=[12,7]      # G1
  u1=[12/16,7/16]   #mannually

  z2=[3,5]
  u2=[3/17,5/17]     #mannually

  z3=[2,7]
  u3=[2/15,7/15]   #mannually

  u_main=[.05980392157,.19828431] #mannually
  iteration=[0,1]

  for i in range(2,trials+1):
    new_z1=(13 * z1[i-1] + z1[i-2] + 3) % 16   #G1
    z1.append(new_z1)
    new_u1= new_z1/16
    u1.append(new_u1)


    new_z2=(12 * z2[i-1]**2 + 13 * z2[i-2] ) % 17 #G2
    z2.append(new_z2)
    new_u2=new_z2/17
    u2.append(new_u2)


    new_z3= (z3[i-1]**3 + z3[i-2]) % 15    #G3
    z3.append(new_z3)
    new_u3= new_z3/15
    u3.append(new_u3)


    iteration.append(i)   #iteration list


    temp=u1[i] + u2[i] + u3[i]
    if temp>1:
      temp1=int(temp)
      u_main.append(temp - temp1) # collecting value after point
    else:
      u_main.append(temp) 
    
    
  
  print("trials", trials)
  print("Random numbers: ", u_main)


  plt.bar(iteration,u_main)

  # naming the x axis 
  plt.xlabel('index of randon number i') 
  # naming the y axis 
  plt.ylabel('random number Z_i')
  plt.show()