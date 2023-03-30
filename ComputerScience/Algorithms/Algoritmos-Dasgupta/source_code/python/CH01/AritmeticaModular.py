# -*- coding: utf-8 -*-
"""
Created on Mon Mar  6 21:25:12 2023

@author: Luis Carlos A. Rojas Torres
email: redtower.soft@gmail.com
github: https://github.com/LuisCarlosRojasTorres
"""

'''
This functions calculates the remainder of:
    x^y mod N = remainder
'''
def modexp(x,y,N):
    ans = 1
    counter = 0
    while counter < y:
        ans = ( ans * x) % N
        counter+=1
    return ans

print(modexp(2000,3000,7)) # Deve dar 1
print(modexp(7,5,9)) #Deve dar 4
print(modexp(4,13,497)) #Deve dar 445
