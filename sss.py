times = int(input())
for _ in range(times):
    exp = input()
    try:
        result = eval(exp)
    except NameError:
        print("NameError")
    except ZeroDivisionError:
        print("ZeroDivisionError")
    except SyntaxError:
        print("SyntaxError")
    else:
        print("%.2f"%result)
