import sys, os
import pygame
from math import sqrt
from pygame.locals import *
from material import *
import random

# pyinstaller -w --add-data '.\Tetris\*.wav;Tetris' --add-data '.\Tetris\*.mp3;Tetris' -F .\Tetris\Tetris.py

def resource_path(relative_path):
    try:
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")
    return os.path.join(base_path, relative_path)

# 순위 변수 관리를 위한 클래스
class T_RANK:
    def __init__(self, name, score):
        self.name = name
        self.score = score

class BLOCKC:
    def __init__(self, name):
        self.turn = 0
        self.type = BLOCKS[name]
        self.data = self.type[self.turn]
        self.size = int(sqrt(len(self.data)))
        self.xpos = (WIDTH - self.size)//2
        self.ypos = 0
        self.stop = 0
    def update(self, score):
        global BLOCK
        global BLOCK_LIST
        erased = 0
        if is_overlapped(self.xpos, self.ypos+1, self.turn):
            for y_offset in range(self.size):
                for x_offset in range(self.size):
                    if((0 <= self.xpos+x_offset) < WIDTH) and (0 <= self.ypos+y_offset < HEIGHT):
                        val = self.data[y_offset*self.size + x_offset]
                        if val != 'B':
                            FIELD[self.ypos+y_offset][self.xpos+x_offset] = val
            # 다음 블럭 지정
            sound_set.play()
            BLOCK_LIST.pop(0)
            BLOCK_LIST.append(get_block())
            BLOCK = BLOCK_LIST[0]
            erased = erase_line()
        else:
            # 점수가 높을수록 블럭이 빨리 떨어짐
            if score >= 50:
                FLAG = 3/5
            elif score >= 30:
                FLAG = 5/7
            elif score >= 10:
                FLAG = 7/9
            else:
                FLAG = 1
            self.stop = self.stop +1
            if self.stop > FPS * FLAG:
                self.stop = 0
                self.ypos = self.ypos + 1
        return erased
    def draw(self):
        for index in range(len(self.data)):
            xpos = index % self.size
            ypos = index // self.size
            val = self.data[index]
            if((0<=ypos + self.ypos < HEIGHT) and (0<=xpos + self.xpos < WIDTH) and (val != 'B')):
                x_pos = 25 + (xpos + self.xpos)*25
                y_pos = 25 + (ypos + self.ypos)*25
                pygame.draw.rect(SURFACE, COLORS[val], (x_pos, y_pos, 24, 24))                       
        # 바닥부분 표시
        n=1
        while True:
            if is_overlapped(self.xpos, self.ypos+n, self.turn):
                n-=1
                break
            n+=1    
        for index in range(len(self.data)):
            xpos = index % self.size
            ypos = index // self.size
            val = self.data[index]
            if((0<=ypos + self.ypos < HEIGHT) and (0<=xpos + self.xpos < WIDTH) and (val != 'B')):
                x_pos = 25 + (xpos + self.xpos)*25
                y_pos = 25 + (ypos + self.ypos+n)*25
                pygame.draw.rect(SURFACE, COLORS[val], (x_pos, y_pos, 24, 24), 1)  

    def left(self):
        if not is_overlapped(self.xpos-1, self.ypos, self.turn):
          self.xpos = self.xpos-1
    def right(self):
        if not is_overlapped(self.xpos+1, self.ypos, self.turn):
            self.xpos = self.xpos+1
    def down(self):
        if not is_overlapped(self.xpos, self.ypos+1, self.turn):
            self.ypos = self.ypos+1
    def up(self):
        if not is_overlapped(self.xpos-1, self.ypos, (self.turn+1)%4):
            self.turn = (self.turn+1)%4
            self.data = self.type[self.turn]
    # 스페이스바 혹은 엔터키 입력 시 바로 바닥에 떨어짐
    def quickdown(self):
        n=1
        while True:
            if is_overlapped(self.xpos, self.ypos+n, self.turn):
                self.ypos = self.ypos+n-1
                break
            n+=1

def get_block():
    name = random.choice(list(BLOCKS.keys()))
    return BLOCKC(name)

def is_game_over():
    filled = 0
    for cell in FIELD[0]:
        if cell != 'B':
            filled+=1
    return filled > 2

def is_overlapped(xpos, ypos, turn):
    data = BLOCK.type[turn]
    for y_offset in range(BLOCK.size):
        for x_offset in range(BLOCK.size):
            if((0 <= xpos+x_offset) < WIDTH) and (0 <= ypos+y_offset < HEIGHT):
                if((data[y_offset*BLOCK.size +x_offset]) != 'B' and (FIELD[ypos+y_offset][xpos+x_offset] != 'B')):
                    return True
    return False

def erase_line():
    erased = 0
    ypos = HEIGHT-1
    while ypos >= 0:
        if FIELD[ypos].count('B') == 0 and FIELD[ypos].count('W') == 2:
            erased+=1
            del FIELD[ypos]
            new_line = ['B']*(WIDTH-2)
            new_line.insert(0, 'W')
            new_line.append('W')
            FIELD.insert(0, new_line)
        else:
            ypos-=1
    return erased

def main():
    global BLOCK
    global BLOCK_LIST
    if BLOCK is None:
        # 오른쪽에 블럭 보여주기 위한 초반 설정
        BLOCK_LIST.append(get_block())
        BLOCK_LIST.append(get_block())
        BLOCK_LIST.append(get_block())
        BLOCK_LIST.append(get_block())
        BLOCK = BLOCK_LIST[0]
    active = False
    score = 0
    text = ''
    color = (160, 160, 160)
    input_box = pygame.Rect(200, 200, 200, 50)
    retry_box = pygame.Rect(480, 530, 100, 50)
    smallfont = pygame.font.SysFont(None, 36)
    largerfont = pygame.font.SysFont(None, 72)
    message_over = largerfont.render("GAME OVER!!", True, (255, 255, 255))
    message_rect = message_over.get_rect()
    message_rect.center= (300, 100)
    message_write = smallfont.render("Write Your Name", True, (255, 255, 255))
    message_rectw = message_write.get_rect()
    message_rectw.center = (300, 170)
    NAME = ''
    RANK = -1
    while True:
        key = None
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN:
                key = event.key
                if event.key == K_ESCAPE:
                    pygame.quit()
                    sys.exit()
                if active:
                    if event.key == K_RETURN:
                        NAME = text
                        active = False
                        color = (220, 220, 220)
                        # 파일 탐색 및 내용 확인
                        if os.path.isfile("tranking.txt") == False:
                            f = open("tranking.txt", 'w')
                            f.close()
                        RANKING = []
                        with open("tranking.txt", 'r', encoding="utf-8") as f: # ABC 10
                            line = f.readline().replace("\n", "")
                            while line:
                                tmp = line.split(" ")
                                RANKING.append(T_RANK(tmp[0], int(tmp[1])))
                                line = f.readline().replace("\n", "")

                        # 이름 입력 시 파일에 순위를 기록함
                        if len(RANKING) == 0:
                            RANKING.append(T_RANK(NAME, score))
                            RANK = 1
                        else:
                            flag = False
                            for i in range(len(RANKING)):
                                if score > RANKING[i].score:
                                    RANKING.insert(i, T_RANK(NAME, score))
                                    flag = True
                                    RANK = i+1
                                    break
                            if not flag:
                                RANKING.append(T_RANK(NAME, score))
                                RANK = len(RANKING)
                        with open("tranking.txt", 'w', encoding='utf-8') as f:
                            for i in RANKING:
                                f.write("%s %d\n" %(i.name, i.score)) 
                    # 이름 입력 부분
                    elif event.key == K_BACKSPACE:                        
                        text = text[:-1]
                    elif event.key == K_SPACE:
                        continue
                    elif len(text) < 13:
                        text += event.unicode
            elif event.type == MOUSEBUTTONDOWN:
                # 재시도 버튼
                if retry_box.collidepoint(event.pos):
                    if not is_game_over():
                        return # main() 함수를 끝내 while문을 한 번 더 돌려 변수 초기화 후 main() 재실행
                # 이름 입력 마우스 처리
                if input_box.collidepoint(event.pos):
                    if is_game_over() and len(NAME)==0:
                        active = True
                    else:
                        active = False
                    color = (255, 255, 255) if active else (220, 220, 220)

        SURFACE.fill((0,0,0))
        score_str = str(score).zfill(6)
        score_image = smallfont.render(score_str, True, (180, 180, 180))
        SURFACE.blit(score_image, (500,30))
        for y in range(HEIGHT):
            for x in range(WIDTH):
                value = FIELD[y][x]
                pygame.draw.rect(SURFACE, COLORS[value], (x*25+25,y*25+25,24,24))
        # 오른쪽에 다음 블럭 출력
        for i in range(1,4):
            for index in range(len(BLOCK_LIST[i].data)):
                xpos = index % BLOCK_LIST[i].size
                ypos = index // BLOCK_LIST[i].size
                val = BLOCK_LIST[i].data[index]
                x_pos = 500 + xpos*20
                y_pos = 90 + ypos*20 + 100*(i-1)
                pygame.draw.rect(SURFACE, COLORS[val], (x_pos, y_pos, 19, 19))
        # 순위 출력
        if len(NAME) != 0:
            message_rank = smallfont.render("Ranking", True, (255, 255, 255))
            message_rectr = message_write.get_rect()
            message_rectr.center = (350, 280)
            SURFACE.blit(message_rank, message_rectr)
            i=0 
            for i in range(10):
                if i < len(RANKING):
                    message_rank = pygame.font.SysFont(None, 20).render(f"{str(i+1).zfill(2)}. {RANKING[i].name}", True, (255, 255, 255))
                    message_rectr = message_write.get_rect()
                    message_rectr.center = (290, 330+i*20)
                    SURFACE.blit(message_rank, message_rectr)
                    message_rank = pygame.font.SysFont(None, 20).render(f" {str(RANKING[i].score).zfill(6)} score", True, (255, 255, 255))
                    message_rectr = message_write.get_rect()
                    message_rectr.center = (420, 330+i*20)
                    SURFACE.blit(message_rank, message_rectr)
                else:
                    break
            if RANK == 1:
                message_rank = pygame.font.SysFont(None, 30).render(f"{NAME} : 1st", True, (255, 255, 255))
            elif RANK == 2:
                message_rank = pygame.font.SysFont(None, 30).render(f"{NAME} : 2nd", True, (255, 255, 255))
            elif RANK == 3:
                message_rank = pygame.font.SysFont(None, 30).render(f"{NAME} : 3rd", True, (255, 255, 255))
            else:
                message_rank = pygame.font.SysFont(None, 30).render(f"{NAME} : {RANK}th", True, (255, 255, 255))
            message_rectr = message_write.get_rect()
            message_rectr.center = (300, 380+i*20)
            SURFACE.blit(message_rank, message_rectr)
        
        if is_game_over():
            if RANK==-1:
                RANK=0
                sound_gameover.play()
            SURFACE.blit(message_over, message_rect)
            SURFACE.blit(message_write, message_rectw)
            txt_surface = smallfont.render(text, True, color)
            SURFACE.blit(txt_surface, (input_box.x+5, input_box.y+15))
            pygame.draw.rect(SURFACE, color, input_box, 2)
        else:
            if key == K_UP:
                BLOCK.up()
            elif key == K_RIGHT:
                BLOCK.right()
            elif key == K_LEFT:
                BLOCK.left()
            elif key == K_DOWN:
                BLOCK.down()
            elif key == K_SPACE or key == K_RETURN:
                BLOCK.quickdown()

            # 재시도 버튼
            SURFACE.blit(smallfont.render("RETRY", True, (200, 200, 200)), (retry_box.x+8, retry_box.y+15))
            pygame.draw.rect(SURFACE, (200, 200, 200), retry_box, 2)

            erased = BLOCK.update(score)
            if erased > 0:
                sound_success.play()
                score+=2**erased
            BLOCK.draw()

        pygame.display.update()
        FPSCLOCK.tick(FPS)

if __name__ == "__main__":
    pygame.init()
    pygame.key.set_repeat(150)
    pygame.display.set_caption("My PyGame Window")
    sound_success = pygame.mixer.Sound(resource_path('Tetris/success.wav'))
    sound_success.set_volume(0.7)
    sound_set = pygame.mixer.Sound(resource_path('Tetris/set.wav'))
    sound_gameover = pygame.mixer.Sound(resource_path('Tetris/gameover.wav'))
    sound_bgm = pygame.mixer.Sound(resource_path('Tetris/bgm.mp3'))
    sound_bgm.set_volume(0.4)
    sound_bgm.play(-1)
    SURFACE = pygame.display.set_mode((600,600))
    FPSCLOCK = pygame.time.Clock()
    WIDTH =10+2
    HEIGHT=20+1
    FPS = 15
    # 재시도 버튼 사용을 위한 while
    while True:
        BLOCK = None
        BLOCK_LIST = []
        FIELD = [['B' for _ in range(WIDTH)] for _ in range(HEIGHT)]
        for a in range(HEIGHT):
            FIELD[a][0]='W'
            FIELD[a][WIDTH-1]='W'
        for a in range(WIDTH-2):
            FIELD[HEIGHT-1][a+1]='W'
        main()