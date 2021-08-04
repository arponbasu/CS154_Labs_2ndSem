import sys
from collections import Counter
c = Counter(list(open(sys.argv[1], 'r').read().replace('\n', '').replace(',', '').replace('.', '').split(" ")))
max_value = max(c.values())
r = sorted(c.items(), key = lambda x: x[1], reverse = True)
for key,value in r:
    print(max_value/value)
