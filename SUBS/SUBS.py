
import re

file = open('rosalind_subs.txt', 'r')

s, substr, _ = file.read().split( '\n' )

print " ".join( [ str( m.start() + 1 ) for m in re.finditer( "(?={})".format( substr ), s ) ] )

