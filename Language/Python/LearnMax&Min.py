# find maximum b/w two numbers using max() function.
x=int(input("Enter the first number "))
y=int(input("Enter the second number "))
print("Maximunmax of {0} and {1} is {2}".format(x,y,max(x,y)))


# find maximum b/w two numbers using conditional statement.
def max1(x,y):
    if x>y:
        return x
    else:
        return y   
print("Maximunmax of {0} and {1} is {2}".format(x,y,max1(x,y)))


# find maximum b/w two numbers using ternary operator.
max = x if x>y else y
print("Maximunmax of {0} and {1} is {2}".format(x,y,max))


# find maximum b/w two numbers using tuple.
res=(y,x)[x>y]
print("Maximunmax of {0} and {1} is {2}".format(x,y,res))


# find maximum b/w two numbers using dictionary.
res={True:x,False:y}[x>y]
print("Maximunmax of {0} and {1} is {2}".format(x,y,res))


# find maximum b/w two numbers using dictionary.
res=(lambda a,b: a if a>b else b)(x,y)
print("Maximunmax of {0} and {1} is {2}".format(x,y,res))






