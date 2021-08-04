import sys
from collections import Counter
print(Counter(list(open(sys.argv[1], 'r').read().replace('\n', '').replace(',', '').replace('.', '').split(" "))))
