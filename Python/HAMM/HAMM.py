
file = open('rosalind_hamm.txt', 'r')

top, bot = file.read().split( '\n' )

print [ x == bot[ i ] for i, x in enumerate( top ) ].count( False )


