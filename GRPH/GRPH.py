
file = open('rosalind_grph.txt', 'r')

data = [ (b[:13], b[ 13: ]) for b in [ a.replace( '\n', '' ) for a in file.read().split( '>' ) ][ 1: ] ]

for i, dat1 in data :
	for j, dat2 in data :
		if ( i != j ) and ( dat1 != dat2 ) :
			if dat1[-3:] == dat2[:3] :
				print i, j

