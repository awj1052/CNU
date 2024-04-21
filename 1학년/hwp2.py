import turtle, math

turtle.setup(width=900, height=900)
t = turtle.Turtle()
t.ht()
t.speed(10)

def fc(a):
    if a == "도형":
        b = turtle.textinput("", "도형을 입력하시오")
        if (b != "원") and (b != "사각형") and (b != "삼각형"):
            return fc("도형") # 재귀함수는 return으로 하는 편이 좋다. 안할 경우 특수한 상황에서 None을 반환함
        else:
            return b
    else:
        b = turtle.textinput("", "%s" % a)
        if b.isdigit():
            return int(b)
        else:
            return fc(a)

def draw():
    figure = fc("도형")
    if figure == "사각형":
        l1 = fc("가로")        
        l2 = fc("세로")
        t.penup()
        t.goto(-l1/2, -l2/2)
        t.pendown()
        t.forward(l1)
        t.left(90)
        t.forward(l2)
        t.left(90)
        t.forward(l1)
        t.left(90)
        t.forward(l2)
    if figure == "원":
        radius = fc("반지름")
        t.penup()
        t.goto(0, -radius)
        t.pendown()
        t.circle(radius)
    if figure == "삼각형":
        l1 = fc("변 a의 길이")
        l2 = fc("변 b의 길이")
        l3 = fc("변 c의 길이")
        if l1 > l2:
            lm = l1
        else:
            lm = l2
        if lm < l3:
            lm = l3
        if 2*lm >= l1+l2+l3:
            draw()
        else:
            calc = (l1*l1+l2*l2-l3*l3)/2/l1/l2
            t.penup()
            t.goto((-2*l1+l2*calc)/3, -l2*math.sin(math.acos(calc))/3)
            t.pendown()
            t.forward(l1)
            t.right(180)
            t.right(math.acos(calc)*180/math.pi)
            t.forward(l2)
            t.right(180)
            t.right(math.acos((l2*l2+l3*l3-l1*l1)/2/l2/l3)*180/math.pi)
            t.forward(l3)
draw()

turtle.mainloop()
turtle.bye()