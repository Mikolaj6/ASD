import random as rnd
import os

tests = int(1000)

for i in range(tests):
    vertices = rnd.randint(2, 800)
    if vertices%2 == 1:
        vertices += 1

    name = str(i) + '.in'
    tmp = 'tmp'
    f = open(name, 'w')
    f2 = open(tmp, 'w')
    count = 0
    f.write(str(vertices) + ' ')

    for i in range(1, vertices):

        val1 = rnd.randint(1, 57)
        if rnd.random() > 0.27:
            f2.write(str(i) + ' ' + str(i+1) + ' ' + str(val1) + '\n')
            count += 1

        val2 = rnd.randint(1, 7)
        if rnd.random() > 0.31 and i != vertices - 1:
            f2.write(str(i) + ' ' + str(i + 2) + ' ' + str(val2) + '\n')
            count += 1

    f.write(str(count) + '\n')
    f2.close()
    f2 = open(tmp, 'r')
    f.write(f2.read())
    f.close()
    dir_path = os.path.dirname(os.path.realpath(__file__))
    name = str(dir_path) + '/' + tmp
    if os.path.isfile(name):
        os.remove(name)
