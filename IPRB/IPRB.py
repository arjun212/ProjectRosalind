
def domAllelePresent( fatherAlleles, motherAlleles ) :
	lst = []
	for a in fatherAlleles :
		for b in motherAlleles :
			lst.append( a + b )

	domAlleles =  len( [ x for x in lst if x[0].isupper() or x[1].isupper() ] )
	return ( domAlleles * 1.0 ) / len(lst)

def probOfAlleleType( firstPick, secondPick, k, m, n ) :
	fpProb = 0
	spProb = 0
	population = ( k + m + n ) * 1.0

	if firstPick == 0 : #k
		fpProb = k / population
		if k != 0 :
			k -= 1

	if firstPick == 1 : #m
		fpProb = m / population
		if m != 0 :
			m -= 1

	if firstPick == 2 : #n
		fpProb = n / population
		if n != 0 :
			n -= 1

	population -= 1

	if secondPick == 0 : #k
		spProb = k / population

	if secondPick == 1 : #m
		spProb = m / population

	if secondPick == 2 : #n
		spProb = n / population

	return fpProb * spProb

def getAllele( type ):
	if type == 0 :
		return "XX"
	if type == 1 :
		return "Xy"
	if type == 2 :
		return "yy"

file = open('rosalind_iprb.txt', 'r')

k, m, n = [ int(x) for x in file.read().split( ' ' ) ]

acc = 0

# types[0,1,2] = [k, m, n]
for h in range(3) :
	for i in range(3) :
		firstPick = getAllele(h)
		seconPick = getAllele(i)

		acc += ( probOfAlleleType( h, i, k, m, n) * domAllelePresent( firstPick, seconPick ) )

print acc