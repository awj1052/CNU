from random import randint

class Dice:
    def __init__(self):
        self.number_list = []
    def PlayDice(self):
        self.number_list.append(randint(1,6))
    def getNumbers(self):
        return self.number_list
    def getSum(self):
        r = 0
        for i in self.number_list:
            r+=i
        return r

members = 3 # 게임에 참여할 인원 수 조정
member = []
for i in range(members):
    member.append(Dice())
    for j in range(5): # 주사위를 굴릴 횟수 조정
        member[i].PlayDice()
value_list = []
index_list = []
for i in range(members):
    print(f"Gamer{i+1}이 던진 주사위 눈들의 리스트 :", member[i].getNumbers())
    print(f"Gamer{i+1}이 던진 주사위 눈들의 합 :", member[i].getSum())
    value_list.append(member[i].getSum())
    index_list.append(i)
    print("----------------------")
print("======================")
for i in range(len(value_list)-1):
    maxidx = i
    for j in range(i+1, len(value_list)):
        if (value_list[j] > value_list[maxidx]):
            maxidx = j
    index_list[i], index_list[maxidx] = index_list[maxidx], index_list[i]
    value_list[i], value_list[maxidx] = value_list[maxidx], value_list[i]
for i in range(members):
    j=i
    while (j+2 <= members) and (value_list[j] == value_list[j+1]):
        j+=1
    if value_list[j] == value_list[0]:
        print(f"{j+1}등 : Gamer{index_list[i]+1} {value_list[0]} 점 WIN!!")
    else:
        print(f"{j+1}등 : Gamer{index_list[i]+1} {value_list[i]} 점")
print("======================")