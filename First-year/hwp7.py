def list_average(list_):
    r=0
    for i in list_:
        r+=i
    return r/len(list_)
    #from functools import reduce
    #return reduce(lambda x,y: x+y, list(map(lambda x: value[x], range(len(list_)))))/len(list_)
def selection_sort(list_):
    for i in range(len(list_)-1):
        minidx = i
        for j in range(i+1, len(list_)):
            if (list_[j] < list_[minidx]):
                minidx = j
        list_[i], list_[minidx] = list_[minidx], list_[i]
    return list_
def insertion_sort(list_):
    for i in range(1, len(list_)):
        j=i-1
        key=list_[i]
        while((list_[j]>key) and (j>=0)):
            list_[j+1]=list_[j]
            j=j-1
        list_[j+1]=key
    return list_
def counting_sort(list_):
    maxvalue = max(list_)
    count = [0 for i in range(maxvalue)]
    for x in range(len(list_)):
        count[list_[x]-1]+=1
    pos = [0 for i in range(maxvalue)]
    for i in range(1, maxvalue):
        pos[i] = pos[i-1] + count[i-1]
    listout = [0 for x in range(len(list_))]
    for x in range(len(list_)):
        listout[pos[list_[x]-1]] = list_[x]
        pos[list_[x]-1]+=1
    return listout
def draw_graph(list_):
    for i in range(len(list_)):
        print(list_[i], end=" ")
        for j in range(list_[i]):
            print("*", end="")
        print()
def input_int(s):
    a = input(s)
    while (not a.isdigit()) or (a=="0"):
        a = input(s)
    return int(a)
count = input_int("입력할 값의 개수 : ")
#value = list(map(lambda x: input_int(f"{x+1}번째 정수값을 입력하세요 : "), range(count)))
value = []
for i in range(count):
    value.append(input_int(f"{i+1}번째 정수값을 입력하세요 : "))
print("평균 : ", list_average(value))
print("정렬 알고리즘 : (1) 선택정렬 (2) 삽입정렬 (3) 계수정렬")
select = input_int("정렬 알고리즘을 선택하시오 : ")
while (select != 1) and (select != 2) and (select != 3):
    select = input_int("정렬 알고리즘을 선택하시오 : ")
if select == 1:
    print("선택 정렬을 수행합니다.....")
    value = selection_sort(value)
elif select == 2:
    print("삽입 정렬을 수행합니다.....")
    value = insertion_sort(value)
elif select == 3:
    print("계수 정렬을 수행합니다.....")
    value = counting_sort(value)
print("정렬 결과 리스트 : ",value)
print("막대그래프를 그립니다.")
draw_graph(value)