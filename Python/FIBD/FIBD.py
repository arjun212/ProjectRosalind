
file = open('rosalind_fibd.txt', 'r')

n, k = [ int(x) for x in file.read().split(' ') ]


#Store the number of rabbits of each age in a map/dict
rabbitAges = {}

for i in range( k+1 ) :
	rabbitAges[str(i)] = 0

rabbitAges[ '0' ] = 1

#Rabbits die after 1 month :(
if k == 1 : 
	print 0

turn = 1

while turn < n :
	#All rabbits age by 1 year
	for i in range( k, 0, -1 ) :
		rabbitAges[ str( i ) ] = rabbitAges[ str( i-1 ) ]

	#Rabbits being born
	rabbitAges[ '0' ] = 0
	for i in range( 2, k+1 ) :
		rabbitAges[ '0' ] += rabbitAges[ str( i ) ]

	turn += 1

acc = 0
for i in range( k ) :
	acc += rabbitAges[ str( i ) ]

print acc


