# string slicing
out= "bilal is boy"

print(out[2:4])
print(out[:4])
print(len(out))
#negative index 
door= " my room door is open"
print(door[-3:-1])
print(door[-5:-1])
# use diffent function
sr="i am study of bs"
print(sr.endswith("bs"))
#captailize
sr= sr.capitalize()
print(sr)
#replace
b=" bilal is good boy"
print(b.replace("i","r"))
# find
e="new car is buy biala"
print(e.find("is"))
# find 
re="my name is bial is a ggod boy "
print(re.count("is"))# find input fisrt and lenght
first=input("enter first name =")
print(first)
print(len(first))
# count o $ in this string
a= "amercia $ is very strong courency $is evey power ful"
print(a.count("$"))
run=int(input("enter runs="))
if(run >=100):
    print("That runrate is good and that player is good")
elif(run<=100  and run>=50):
    print("That runrate is bad and that player is not good")
else:
    print("That player is bad  runrate")  
# pritce question for marks and grade system
marks=int(input("Enter marks="))
if(marks>=90):
     print("A")
elif(marks>=80):
    print("B")  
elif(marks>=70):
    print("c")
else:
    print("D")    
          # EVEN ODD NUMBER CHECK IN INT NUMBERS
no=int(input("enter number"))
baki=no%2
if(baki==0):
    print("EVEN NUMBERS")
else:
    print("ODD NUMBERS")
#    
    