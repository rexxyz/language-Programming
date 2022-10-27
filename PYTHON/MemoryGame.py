#Importing tkinter and random library
from tkinter import *
import random
from tkinter import ttk

#Create initial window
PuzzleWindow=Tk()
PuzzleWindow.title('The Memory Game')
PuzzleWindow.config(bg="dark gray")

#Create an easy tab on the initial window
tabs = ttk.Notebook(PuzzleWindow) 
easy= ttk.Frame(tabs)

#Create the objects that would be matched
def draw(a,l,m):
    global base_easy
    if a=='A':
        d=base_easy.create_rectangle(100*l+20,m*100+20,100*l+100-20,100*m+100-20,fill='aquamarine')
    elif a=='B':
        d=base_easy.create_rectangle(100*l+20,m*100+20,100*l+100-20,100*m+100-20,fill='cyan')
    elif a=='C':
        d=base_easy.create_rectangle(100*l+20,m*100+20,100*l+100-20,100*m+100-20,fill='red')
    elif a=='D':
        d=base_easy.create_oval(100*l+20,m*100+20,100*l+100-20,100*m+100-20,fill='slate gray')
    elif a=='E':
        d=base_easy.create_oval(100*l+20,m*100+20,100*l+100-20,100*m+100-20,fill='chartreuse')
    elif a=='F':
        d=base_easy.create_oval(100*l+20,m*100+20,100*l+100-20,100*m+100-20,fill='yellow')
    elif a=='G':
        d=base_easy.create_polygon(100*l+50,m*100+20,100*l+20,100*m+100-20,100*l+100-20,100*m+100-20,fill='blue')
    elif a=='H':
        d=base_easy.create_polygon(100*l+50,m*100+20,100*l+20,100*m+100-20,100*l+100-20,100*m+100-20,fill='green')

#Creating the board       
def quizboard():
    global base_easy,ans_easy,board_easy,moves_easy
    count=0
    for i in range(4):
        for j in range(4):
            rec=base_easy.create_rectangle(100*i,j*100,100*i+100,100*j+100,fill="white")
            if(board_easy[i][j]!='.'):
                draw(board_easy[i][j],i,j)
                count+=1
#Counting the number of moves it takes to complete the game            
    if count==16:
        base_easy.create_text(200,450,text="No. of moves: "+str(moves_easy),font=('arial',20)) 
            

def call(event):
    global base_easy,ans_easy,board_easy,moves_easy,prev_easy
    i=event.x//100
    j=event.y//100
    if board_easy[i][j]!='.':
        return
    moves_easy+=1

#Matching objectes/tiles
    if(prev_easy[0]>4):
        prev_easy[0]=i
        prev_easy[1]=j
        board_easy[i][j]=ans_easy[i][j]
        quizboard()
    else:
        board_easy[i][j]=ans_easy[i][j]
        quizboard()
        if(ans_easy[i][j]==board_easy[prev_easy[0]][prev_easy[1]]): #Picked the correct pair
            print("matched")
            prev_easy=[100,100]
            quizboard()
            return
        else: #Not a match
            board_easy[prev_easy[0]][prev_easy[1]]='.'
            quizboard()
            prev_easy=[i,j]
            return
#Creating the base "blocks"
base_easy=Canvas(easy,width=500,height=500)
base_easy.pack()

#List of the matching objects/pair
ans_easy = list('AABBCCDDEEFFGGHH')
random.shuffle(ans_easy)  #Randoming add the matching pairs each time the game is played
ans_easy = [ans_easy[:4],
       ans_easy[4:8],
       ans_easy[8:12],
       ans_easy[12:]]

base_easy.bind("<Button-1>", call)

moves_easy=IntVar()
moves_easy=0

prev_easy=[100,100]

board_easy=[list('.'*4) for count in range(4)]
quizboard()
tabs.add(easy, text ='Easy') 
tabs.pack(expand = 1, fill ="both") 

mainloop()