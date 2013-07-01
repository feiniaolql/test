import random
import sys

"""pass the number count as the first argument
   name as the second argument
   usage: python *.py <count> <filename>
"""

if __name__ == '__main__':
    #print sys.argv[1]
    COUNT = int(sys.argv[1])
    f = open(sys.argv[2], 'w')
    string  = '{0:>5d}'.format(COUNT) + '\n'
    f.write(string)
    i = 1
    while i <= COUNT:
        val = random.randint(1, COUNT)
        string  = '{0:>5d}'.format(val)
        f.write(string)
        if i % 16 == 0:
            f.write('\n')
        i += 1
    f.close()
 
