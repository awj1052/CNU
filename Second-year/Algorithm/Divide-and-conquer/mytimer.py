import time
from functools import wraps

def mytimer(f):
    @wraps(f)
    def wrapper(*args, **kwargs):
        start = time.time()
        res = f(*args, **kwargs)
        print(f'{f.__name__}\t{time.time()-start:.9f} sec', end='')
        return res
    return wrapper

