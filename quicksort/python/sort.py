import time
from random import randint
def selection_sort(list):
	for i in range(len(list)-1):
		j = i+1
		min = j
		while j < len(list):
			if list[j] < list[min]:
				min = j
			j+=1
		temp = list[i]
		list[i] = list[min]
		list[min] = temp

def sort_quicker(start, end, list):
	if(start-end == 0):
		return
	pivot = randint(start, end)
	for i in range((start-end)/2)


def sort(list):
	if(len(list) <= 1):
		return list
	pivot = randint(0, len(list)-1)
	less = []
	greater = []
	for i in range(len(list)):
		if(i != pivot):
			if list[i] < list[pivot]:
				less.append(list[i])
			else:
				greater.append(list[i])
	return sort(less)+ [list[pivot]] + sort(greater)

l = []
for i in range(100000):
	l.append(randint(0,1000))

h = l[:]
w = l[:]
z = l[:]

time1 = time.time()
sort(h)
print time.time()-time1

time1 = time.time()
w.sort()
print time.time()-time1

time1 = time.time()
selection_sort(z)
print time.time()-time1
