
file = open('rosalind_fib.txt', 'r')

s = file.read()

n = int( s.split(' ')[0] )
k = int( s.split(' ')[1] )

pop = [ 1, 1 ]

if ( n <= 2 ) :
	print pop[ n-1 ]

while len( pop ) < n :
	pop.append( pop[-1] + (k * pop[-2]) )

print pop[ -1 ]
