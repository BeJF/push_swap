from tkinter import *
import time
import os


win_height = 900
win_width = 1200
pile_a = []
pile_b = []
i = 1
mod = 2
speed = 0

#get initials data
lines = [line.rstrip('\n') for line in open('test0')]
#print(lines)
initial_pile = list(map(int,lines[0].split())) 
print("initial_pile", initial_pile)
size = len(initial_pile)
#create_piles(size)
max = max(initial_pile)
data_height = (win_height - 200) / size
data_width_ratio = (win_width - 200) / max / 2
max_x1_a = data_width_ratio * max


def create_piles(nb_datas):
    
    while nb_datas >= 0 : #0
        pile_a.append(w.create_rectangle(0, 0, 0, 0, fill="blue", outline="blue"))
        pile_b.append(w.create_rectangle(0, 0, 0, 0, fill="red", outline="red"))
        nb_datas -= 1

def update_pile_a(pile, data_height, data_width_ratio, size) :    

    obj = 1
    size_pile = len(pile)
    #if size_pile == 99 :
     #   print(pile)
    #if size_pile == 100 :
     #   print(pile)
    y0 = 150
    #print("size_pile = ", size_pile)
    #print("size = ", size)
    while (size_pile < size) :
        y1 = y0 + data_height
        w.coords(pile_a[obj - 1], 0, 0, 0, 0)
        obj += 1
        y0 = y1
        size_pile += 1
    for data in pile :
        y1 = y0 + data_height
        x0 = 50
        x1 = x0 + data * data_width_ratio
        w.coords(pile_a[obj - 1], x0, y0, x1, y1)
        y0 = y1
        obj += 1

def update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size) :    

    obj = 1
    size_pile = len(pile)
    y0 = 150
    while (size_pile < size) :
        y1 = y0 + data_height
        w.coords(pile_b[obj - 1], 0, 0, 0, 0)
        obj += 1
        y0 = y1
        size_pile += 1
    for data in pile :
        y1 = y0 + data_height
        x0 = max_x1_a + 150
        x1 = x0 + data * data_width_ratio
        w.coords(pile_b[obj - 1], x0, y0, x1, y1)
        y0 = y1
        obj += 1

'''def change_speed(event) :
    global speed
    global mod
    key = event.char
    if key == 'a' :
        speed -= 2
    if key == 's' :
        speed += 2
    mod = speed
    if mod <= 0 :
        mod = 2
    print("speed = ", speed)'''

def Speed_up() :
    global speed
    global mod
    speed += 2
    mod = speed
    if mod <= 0 :
        mod = 2
    print("speed =", speed)


def Slow_down() :
    global speed
    global mod
    speed -= 2
    mod = speed
    if mod <= 0 :
        mod = 2
    print("speed = ", speed)

def Start() :
    global start
    if start == 0 :
        start = 1
        Pause.set("Stop")
        #display()
    elif start == 1 :
        start = 0
        Pause.set("Start")
    elif start == 2 :
        start = 0
        Pause.set("Start")
        display()

def Stop() :
    global start
    start = 0

start = 0

master = Tk()
title = "VISU PUSH_SWAP     \u00A9jfinet"
master.title(title)
w = Canvas(master, height=win_height, width=win_width, bg='black')
w.pack()

Pause = StringVar()
Pause.set("Start")
go = Button(master, width=20, textvariable = Pause, highlightbackground="black", command = Start) #command = start
go.place(x=500, y=25)
slow_down_button = Button(master, width=10, text = "Speed Up", highlightbackground="black", command = Speed_up)
slow_down_button.place(x=485, y=50)
speed_up_button = Button(master, width=10, text = "Slow Down", highlightbackground="black", command = Slow_down)
speed_up_button.place(x=605, y=50)
#test = 0
#scale = Scale(master,from_=-25,to=25,resolution=1,orient=HORIZONTAL, bg= "black", fg="grey", length=200,width=20,label="Speed",tickinterval=10,variable=test)
#text = Text(master, height=1, font="Helvetica", fg = "red", bg="black", bd = 0)
#text = Text(master, height=1, font="Helvetica", fg = "red", bg="black")
#text.insert(INSERT, "SPEED")
#text.place(x=500, y=50)
#text.pack()
#scale.place(x=500, y =50)
#w.bind('<Key>', change_speed)
#w.focus_set()


def update_piles(pile, i) :
    while start == 0 :
        update_pile_a(pile, data_height, data_width_ratio, size)
        w.update()
        continue
    if i % mod == 1 :
        update_pile_a(pile, data_height, data_width_ratio, size)
    if i % mod == 0 :
        update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
        w.update()
    if speed < 0 :
        #w.after((-speed)/50)
        time.sleep((-speed)/50)

'''for line in lines :
    
    #transform the string into a list and convert the str into int
    pile = list(map(int,line.split())) 
    if i == 1 :
        size = len(pile)
        create_piles(size)
        max = max(pile)
        data_height = (win_height - 200) / size
        data_width_ratio = (win_width - 200) / max / 2
        max_x1_a = data_width_ratio * max
    while start == 0 :
        if i == 1 :
            update_pile_a(pile, data_height, data_width_ratio, size)
        w.update()
    if i % mod == 1 :
        update_pile_a(pile, data_height, data_width_ratio, size)
    if i % mod == 0 :
        update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
        w.update()
    if speed < 0 :
        #w.after((-speed)/50)
        time.sleep((-speed)/50)
    i += 1'''

def display() :
#create_piles(size)
    i = 1
    global start
    for line in lines :
        pile = list(map(int,line.split())) 
        while start == 0 :
            if i == 1 :
                #print("line = ", line)
                update_pile_a(pile, data_height, data_width_ratio, size)
            w.update()
            #continue
        #if (speed >= 0) :
        update_piles(pile, i)
        #elif (speed < 0) :
            #w.after(500, update_piles(pile,i))
            #w.after((-speed)/50, update_piles(pile,i))
        #w.update()
        i += 1
    pile = list(map(int,lines[i - 3].split())) 
    update_pile_a(pile, data_height, data_width_ratio, size)
    pile = list(map(int,lines[i - 2].split())) 
    update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
    start = 2
    Pause.set("Reset")



#print last state of the pile when mod > 2
#pile = list(map(int,lines[i - 3].split())) 
#update_pile_a(pile, data_height, data_width_ratio, size)
#pile = list(map(int,lines[i - 2].split())) 
#update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
create_piles(size)
display()
#Pause.set("Reset")
#start = 2

master.mainloop()
