def simple_gradient_descent(x_list, y_list):
   # linear regression equation form : y = mx
   m = 5 # initial m value
   lr = 0.01 # learning rate
   N = len(x_list) # number of dataset pairs = len(y_list)
   th = 0.00001 # terminal condition

   E = 0 # cost function of mean square error
   for i in range(N):
      E += (m * x_list[i] - y_list[i]) ** 2
   E /= N

   rErm = 0 # partial differential function of E
   for i in range(N):
      rErm += (-2) * (y_list[i] - (m * x_list[i])) * x_list[i]
   rErm /= N

   cnt=1
   while abs(rErm) > th:
      cnt+=1
      # updating m
      m -= lr * rErm

      E = 0 # cost function of mean square error
      for i in range(N):
         E += (m * x_list[i] - y_list[i]) ** 2
      E /= N

      rErm = 0 # partial differential function of E
      for i in range(N):
         rErm += (-2) * (y_list[i] - (m * x_list[i])) * x_list[i]
      rErm /= N

      print('E:',E)
      print('rErm:',rErm)
      print('m:',m)
      print()
   print('cnt:',cnt)
   return m

X = [1,2,3,4,5,6,7,8,9]
Y = [2,4,5,9,10,13,16,21,32]
print(simple_gradient_descent(X,Y))
