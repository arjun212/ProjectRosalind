
import operator

file = open('rosalind_cons.txt', 'r')

x = [ b[ 13: ] for b in [ a.replace( '\n', '' ) for a in file.read().split( '>' ) ][ 1: ] ]

strLen = len( x[ 0 ] )

profile = {
	'A' : ( [ 0 ] * strLen ) ,
	'C' : ( [ 0 ] * strLen ) ,
	'G' : ( [ 0 ] * strLen ) ,
	'T' : ( [ 0 ] * strLen ) }


for i in range( strLen ) :
	for s in x :
		profile[s[i]][i] += 1


#indexMap
im = [ 'A', 'C', 'G', 'T' ]

result = []
for i in range( strLen ) :
	index, value = max( enumerate( [ profile['A'][i], profile['C'][i], profile['G'][i], profile['T'][i] ] ), 
						key = lambda e: e[ 1 ] )

	result.append( im[ index ] )


print "".join( result )
print "A: ", " ".join( [ str( n ) for n in profile[ 'A' ] ] )
print "C: ", " ".join( [ str( n ) for n in profile[ 'C' ] ] )
print "G: ", " ".join( [ str( n ) for n in profile[ 'G' ] ] )
print "T: ", " ".join( [ str( n ) for n in profile[ 'T' ] ] )

