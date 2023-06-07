class set_operate:
    def __init__(self):
         data=set()
         data1=set()
         data2=set()

    def add_elem(self,data):
        print("Enter number of element you want to add in set: ")
        n=int(input())
        for i in range(n):
            elem=input("Enter the element: ")
            data.add(elem)
            print(data)

    def del_elem(self,data):
        print(data)
        delem=input("Enter the element to reomove: ")
        data.remove(delem)
        print(data)

    def size_of_set(self,data):
        print("Size of Sef is: ",len(data))

    def intersection(self,data1,data2):
        print("Intersection of Set are: ",data1.intersection(data2))

    def union(self,data1,data2):
        print("Union of Sets are: ",data1.union(data2))

    def difference(self,data1,data2):
        print("Difference of Set are: ",data1.difference(data2))

    def sub_set(self,data1,data2):
        if(data1.issubset(data2)):
            print("SET 1 is subset of SET 2")
        if(data2.issubset(data1)):
            print("SET 2 is subset of SET 1")
        else:
            print("No subset are present")

a = True
s=set_operate()
data1=set()
data2=set()
while(a==True):
    c=int(input("Enter Operation you want to carry on set: \n 1.Add Element \n 2.Delete Element \n 3.Display Size of Set \n 4.Intersection \n 5.Union \n 6.Difference \n 7.Sub-Set Checker \n 8.End \n"))
    if(c==1):
        d=int(input("Enter set in which you want to add element: \n 1.SET 1 \n 2.SET 2 \n"))
        if(d==1):
            s.add_elem(data1)
        else:
            s.add_elem(data2)
    if(c==2):
        d=int(input("Enter set from which you want to delete element: \n 1.SET 1 \n 2.SET 2 \n "))
        if(d==1):
            s.del_elem(data1)
        else:
            s.del_elem(data2)
    if(c==3):
        d=int(input("Enter set from which you want to display the size of: \n 1.SET 1 \n 2.SET 2 \n "))
        if(d==1):
            s.size_of_set(data1)
        else:
            s.size_of_set(data2)
    if(c==4):
        s.intersection(data1,data2)
    if(c==5):
        s.union(data1,data2)
    if(c==6):
        d=int(input("Enter Difference you want to perform: \n 1.SET 1 - SET 2 \n 2.SET 2 - SET 1\n "))
        if(d==1):
            s.difference(data1,data2)
        else:
            s.difference(data2,data1)
    if(c==7):
        s.sub_set(data1,data2)
    if(c==8):
        a=False
        print("Thank you!!")
        break
        
 """Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
1
Enter set in which you want to add element:
 1.SET 1
 2.SET 2
1
Enter number of element you want to add in set:
3
Enter the element: a
{'a'}
Enter the element: b
{'b', 'a'}
Enter the element: c
{'b', 'a', 'c'}
Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
1
Enter set in which you want to add element:
 1.SET 1
 2.SET 2
2
Enter number of element you want to add in set:
3
Enter the element: b
{'b'}
Enter the element: c
{'b', 'c'}
Enter the element: d
{'b', 'd', 'c'}
Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
2
Enter set from which you want to delete element:
 1.SET 1
 2.SET 2
 2
{'b', 'd', 'c'}
Enter the element to reomove: d
{'b', 'c'}
Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
3
Enter set from which you want to display the size of:
 1.SET 1
 2.SET 2
 1
Size of Sef is:  3
Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
5
Union of Sets are:  {'a', 'c', 'b'}
Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
6
Enter Difference you want to perform:
 1.SET 1 - SET 2
 2.SET 2 - SET 1
 1
Difference of Set are:  {'a'}
Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
6
Enter Difference you want to perform:
 1.SET 1 - SET 2
 2.SET 2 - SET 1
 2
Difference of Set are:  set()
Enter Operation you want to carry on set:
 1.Add Element
 2.Delete Element
 3.Display Size of Set
 4.Intersection
 5.Union
 6.Difference
 7.Sub-Set Checker
 8.End
7
SET 2 is subset of SET 1 """
    

