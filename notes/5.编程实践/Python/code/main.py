from test1 import *

from sound.effects import *

def main():
    test()
    # test1() # NameError: name 'test1' is not defined

main()

print('echo', echo)
print('surround', surround)
print('reverse', reverse)
# print('concat', concat) # NameError: name 'concat' is not defined

# echo.echoMethod()