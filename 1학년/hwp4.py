import turtle

count = int(input('학급 수를 입력하시오 : '))

grade = list()
mini = 100
for i in range(count):
    inputg = int(input(f'{i+1}반의 성적 평균 : '))
    grade.append(inputg)
    if mini > inputg:
        mini = inputg

def draw_bar(height):
    t.forward(height)
    t.right(90)
    t.write(str(height), font = ('Times New Roman', 16, 'bold'))
    t.forward(80)
    t.right(90)
    t.forward(height)
    t.left(90)
    t.forward(2)
    t.left(90)

turtle.setup(width=600, height=400)
t = turtle.Turtle()
t.ht()
t.speed(10)
t.penup()
t.goto(-40*count, -2/3*mini)
t.pendown()
t.left(90)

for h in grade:
    draw_bar(h)

turtle.mainloop()
turtle.bye()