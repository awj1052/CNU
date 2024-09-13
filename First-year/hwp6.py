import os

print()
name = input("---------------\n입력 파일과 출력 파일을 다음과 같이 입력하시오\n(입력파일) (출력파일)\nEx) sales.txt summary.txt\n---------------\n")
file_name = name.split(" ")
if os.path.isfile(file_name[0]) == False:
    print(f'{file_name[0]} 파일을 찾을 수 없습니다.')
    exit()
with open(file_name[0], 'r', encoding="utf-8") as f:
    line = f.readline().replace("\n", "")
    lines = 0
    total = 0
    while line:
        lines += 1
        try:
            total += int(line)
        except:
            lines -= 1
        line = f.readline().replace("\n", "")
    else:
        if lines==0:
            print(f'{file_name[0]} 파일을 작성해주세요.')
            exit()
with open(file_name[1], 'w', encoding='utf-8') as f:
    f.write('총매출 = %d\n' %total)
    f.write('평균 일매출 = %f\n' %(total/lines))
print('---------------')
print('파일을 생성하였습니다.')
print()
        