"""Use '+' operator for addition"""
nums1= float(input("Enter the first number "))
nums2= float(input("Enter the second number "))
# .format() is use for print many veriable in print statement
print("Sum of {0} and {1} is {2}".format(nums1,nums2,nums1+nums2))


"""Use user define function for addition"""
def add(nums1,nums2):
    return nums1+nums2
sum=add(nums1,nums2)
print("Sum of {0} and {1} is {2}".format(nums1,nums2,sum))


"""Use operator library for addition"""
import operator
sum1=operator.add(nums1,nums2)
print("Sum of {0} and {1} is {2}".format(nums1,nums2,sum1))


"""Use lambda function for addition"""
add = lambda x,y: nums1+nums2
print("Sum of {0} and {1} is {2}".format(nums1,nums2,add(nums1,nums2)))


"""Use python class for addition"""
class calculator:
  """When you call obj.add(10, 20), the instance obj is
   automatically passed as the first argument to the method add,
  and it is assigned to self"""
def add(self,nums1,num2): return nums1+nums2
obj=calculator()
sum2=obj.add(nums1,nums2)
print("Sum of {0} and {1} is {2}".format(nums1,nums2,sum2))

    
    


