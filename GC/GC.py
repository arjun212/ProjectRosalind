
def GC( s ):
	return ( ( s.count('G') + s.count('C') ) * 100.0 ) / len(s)

file = open('rosalind_gc.txt', 'r')

fileSplit = [ x.split('\n') for x in file.read().split('>')[1:] ]

s = []

for x in fileSplit :
	s.append(x[0])
	s.append("".join(x[1:]))

r_id = s[::2]

vals = [ GC(x) for x in s[ 1::2 ] ]

maxIndex = vals.index( max( vals ) )

print r_id[ maxIndex ]
print vals[ maxIndex ]
