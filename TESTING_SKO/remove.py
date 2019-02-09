import os

tests = int(1000)
for i in range(tests):
    dir_path = os.path.dirname(os.path.realpath(__file__))
    name = str(dir_path) + '/' + str(i) + '.in'
    name2 = str(dir_path) + '/' + str(i) + '.out'
    if(os.path.isfile(name)):
        os.remove(name)

    if(os.path.isfile(name2)):
        os.remove(name2)
