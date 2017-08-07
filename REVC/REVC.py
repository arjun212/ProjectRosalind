
file = open('rosalind_revc.txt', 'r')

s = file.read()

flipMap = { 'G' : 'C' ,
	        'C' : 'G' ,
	        'A' : 'T' ,
	        'T' : 'A' }


print "".join( [ flipMap[x] for x in s ] )[::-1]
