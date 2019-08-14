names=input().strip().split()
map = dict()

for name in names:
	if name in map.keys():
		map[name] = map[name] + 1
	else:
		map[name] = 1

count=0
for name in map.keys():
	if(map[name] > 1):
		print(name + " " + str(map[name]))
		count= count+1

if(count==0):
	print(-1)

