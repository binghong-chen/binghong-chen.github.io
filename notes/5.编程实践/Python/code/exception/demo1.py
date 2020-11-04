# try:
#     x = 12
#     x = 1 / 0
# except ZeroDivisionError:
#     print('error')
# finally:
#     print('finally run', x)
# print('after run', x)

'''
A finally clause is always executed before leaving the try statement, 
whether an exception has occurred or not. When an exception has 
occurred in the try clause and has not been handled by an except 
clause (or it has occurred in a except or else clause), it is 
re-raised after the finally clause has been executed. The finally 
clause is also executed “on the way out” when any other clause of 
the try statement is left via a break, continue or return statement.
'''

def func(d):
    try:
        x = 12
        x = x / d
        '''try块中包含break、continue或者return语句的，
        在离开try块之前，finally中的语句也会被执行'''
        return x    
    except ZeroDivisionError:
        print('error')
    finally:
        print('finally run', x)
        return 111  # 最后执行的是 finally
    print('after run', x)

dd = func(1)
print(dd)   # 12.0
dd = func(0)
print(dd)   # None