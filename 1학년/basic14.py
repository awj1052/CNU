"""cointype = [500, 100, 50, 10, 5, 1]

def coin_greedy(p):
    sum = 0
    for i in cointype:
        sum+=p//i
        p-=(p//i)*i
    return sum

money = int(input('거스름돈 입력 : '))
print("\n총 코인 개수 : ", coin_greedy(money))"""

from functools import cmp_to_key

class items:
    def __init__(self, num, weight, price):
        self.num = num
        self.weight = weight
        self.price = price
    def __str__(self):
        return "번호 : {0}, 무게 : {1}, 가격 : {2}".format(self.num, self.weight, self.price)

def compare(x, y):
    # a,b로 비교할 인자 설정 #  x.price/x.weight   y.price/y.weight
    a = x.price/x.weight
    b = y.price/y.weight
    if a > b: # 내림차순으로 정렬
        return -1;
    elif a < b:
        return 1;
    return 0;

def knapsack(item, weight):
    print()
    item=sorted(item, key=cmp_to_key(compare))
    for i in item:
        if weight-i.weight<0:
            continue
        weight-=i.weight
        print("선택됨 : ", i)
    print("남은 무게 : ", weight)

if __name__ == "__main__":
    klist = [items(1, 20, 20), items(2, 31, 35), items(3, 38, 40), items(4, 7, 10), items(5, 5, 10),
            items(6, 27, 30), items(7, 24, 25), items(8, 14, 15), items(9, 19, 20), items(10, 3, 10)]
    knapsack(klist, int(input('가방의 무게 : ')))
    
