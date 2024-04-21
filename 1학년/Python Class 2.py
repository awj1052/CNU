class Vector:
    def __init__(self, value):
        self.value = value
        #sum = 0
        #for i in range(len(value)):
        #    sum+=value[i]**2
        #self.amp = sum**(1/2)
        self.amp = sum([self.value[i]**2 for i in range(len(value))]) ** (1/2)
    def __add__(self, obj):
        #nd = []
        #for i in range(len(self.value)):
        #    nd.append(self.value[i]+vec.value[i])
        #return Vector(nd)
        return Vector( [self.value[i]+obj.value[i] for i in range(len(self.value))] )
    def __sub__(self, obj):
        #nd = []
        #for i in range(len(self.value)):
        #    nd.append(self.value[i]-vec.value[i])
        #return Vector(nd)
        return Vector( [self.value[i]-obj.value[i] for i in range(len(self.value))] )
    def __mul__(self, obj):
        v = 0
        for i in range(len(self.value)):
            v += self.value[i]*obj.value[i]
        return v

A = Vector([1,2,3,4])
print(A.amp)
B = Vector([3,1,-1,2])

C = A+B
print(C.value)

C=A*B
print(C)

C=A-B
print(C.value)