def simple_gradient_descent(x_list, y_list):
   # linear regression equation form : y = mx + n

   m = 5 # initial m value
   n = 5 # initial n value

   lr = 0.01 # learning rate
   N = len(x_list) # number of dataset pairs = len(y_list)
   th = 0.00001 # terminal condition

   E = 0 # cost function of mean square error
   for i in range(N):
      E += (m * x_list[i] + n - y_list[i]) ** 2
   E /= N

   rErm = 0 # partial differential function of E
   for i in range(N):
      rErm += (-2) * (y_list[i] - n - (m * x_list[i])) * x_list[i]
   rErm /= N

   rErn = 0 # partial differential function of E
   for i in range(N):
      rErn += 2 * (n + (m * x_list[i]) - y_list[i])
   rErn /= N

   cnt=1
   while abs(rErm) > th and abs(rErn) > th:
      cnt+=1
      # updating m and n
      m -= lr * rErm
      n -= lr * rErn

      E = 0 # cost function of mean square error
      for i in range(N):
         E += (m * x_list[i] + n - y_list[i]) ** 2
      E /= N

      rErm = 0 # partial differential function of E
      for i in range(N):
         rErm += (-2) * (y_list[i] - n - (m * x_list[i])) * x_list[i]
      rErm /= N

      rErn = 0 # partial differential function of E
      for i in range(N):
         rErn += 2 * (n + (m * x_list[i]) - y_list[i])
      rErn /= N

      print('E:',E)
      print('rErm: {}, rErn: {}'.format(rErm, rErn))
      print('mx + n : {}x + {}'.format(m,n))
      print()
   print('cnt:',cnt)
   return m,n

# y = 2x + 1
#X = [1,2,3,4,5,6,7,8,9] 
#Y = [3,5,7,9,11,13,15,17,19]

# y = x -> y = 0.31x + 3.2
#X = [1,2,3,3,5,4,6,3,9,7,8] 
#Y = [1,3,2,5,3,6,4,9,3,8,7]

# y = -0.64x + 7.25
#X = [2,3,4,4,5,6,7] 
#Y = [6,6,5,4,3,4,3]

# y = 2.6251x when form y=mx
# y = 3.28x - 3.97 whereas form y=mx+n
X = [1,2,3,4,5,6,7,8,9]
Y = [2,4,5,9,10,13,16,21,32]
print(simple_gradient_descent(X,Y))
