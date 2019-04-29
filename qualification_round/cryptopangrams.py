import math
from sys import stdin, stdout
def primeFactor(n): 
	if n % 2 == 0: 
		return 2

	l = int(3)
	r = int(math.sqrt(n))+1

	while l<=r:
		if n%l == 0:
			return l
		l += 1

T = int(stdin.readline()) 
for t in range(1,T+1):
	n, l  = [int(num) for num in stdin.readline().split()] 

	crs = {}
	pnums = [-1]*(l+1)

	nums = [int(num) for num in stdin.readline().split()] 
	x = primeFactor(nums[0])
	y = nums[0]/x

	prims = [-1]*(l+1)
	pi = 1
	prims[0] = x
	crs[x] = ''

	if not(y in crs.keys()):
		prims[pi] = y
		crs[y] = ''
		pi+=1

	if nums[1]%x == 0:
		pnums[0] = y
		pnums[1] = x
		y = nums[1]/x	
	else:
		pnums[0] = x
		pnums[1] = y
		y = nums[1]/y

	pnums[2] = y

	if not(y in crs.keys()):
		prims[pi] = y
		crs[y] = ''
		pi+=1	

	for i in range(3,l+1):
		curr_num = nums[i-1]
		pnums[i] = curr_num/pnums[i-1]

		if not(pnums[i] in crs.keys()):
			prims[pi] = pnums[i]
			crs[pnums[i]] = ''
			pi+=1

	unique_pnums = crs.keys()
	unique_pnums.sort()
	i = 0 
	while i < len(unique_pnums):
		crs[unique_pnums[i]] = chr(65+i)
		i+=1

	ans = ''
	i = 0 
	while i< len(pnums):
		ans  += crs[pnums[i]]
		i+=1
	print("Case #%d: %s"%(t,ans))	
	
