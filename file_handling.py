#file handling
f=open('words.txt','r') #read
str1="people"
s=11
#f=open('words.txt','w')
#f.write(str1)
f=open('words.txt','r+')
data=f.read(s)
print(data)


f.close()
