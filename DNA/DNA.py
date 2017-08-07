
file = open('rosalind_dna.txt', 'r')

s = file.read()

print "{0} {1} {2} {3}".format( s.count('A'), s.count('C'), s.count('G'), s.count('T') )
