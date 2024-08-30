
list1 = [11,22,33,44,55]

mx = max(list1[0], list1[1]) 
smax = min(list1[0], list1[1]) 
n = len(list1)
for i in range(2,n): 
	if list1[i] > mx: 
		smax = mx
		mx = list1[i] 
	elif list1[i] > smax and \
		mx != list1[i]: 
		smax = list1[i]
	elif mx == smax and \
		smax != list1[i]:
		smax = list1[i]

print("Second highest number is : ",\
	str(smax))
