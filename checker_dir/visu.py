# Import libraries
from tkinter import *
import time

# Set initial variables
win_height = 900
win_width = 1200
pile_a = []
pile_b = []
mod = 2
speed = 0
start = 0

# Get initial data
# We read the file line by line and store them inside a list.
# We take the first line (the initial pile), to know the number of datas we will have to sort
lines = [line.rstrip('\n') for line in open('piles')]
initial_pile = list(map(int,lines[0].split())) 
size = len(initial_pile)

# Set other variable for the size of the datas
max = max(initial_pile)
data_height = (win_height - 200) / size
data_width_ratio = (win_width - 200) / max / 2
max_x1_a = data_width_ratio * max


def create_piles(nb_datas):
    
    while nb_datas >= 0 : 
        pile_a.append(w.create_rectangle(0, 0, 0, 0, fill="blue", outline="blue"))
        pile_b.append(w.create_rectangle(0, 0, 0, 0, fill="red", outline="red"))
        nb_datas -= 1

def update_pile_a(pile, data_height, data_width_ratio, size) :    

    obj = 1
    size_pile = len(pile)
    y0 = 150
    # The while loop is used to undisplayed some datas
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
    elif start == 1 :
        start = 0
        Pause.set("Start")
    elif start == 2 :
        start = 0
        Pause.set("Start")
        display()

def update_piles(pile, i) :
    
    # Mod is always pair. Can be greater than 2 to skip some actions and have a faster display
    if i % mod == 1 :
        update_pile_a(pile, data_height, data_width_ratio, size)
    elif i % mod == 0 :
        update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
        w.update()
    if speed < 0 :
        time.sleep((-speed)/50)

def display() :
    
    i = 1
    global start
    
    for line in lines :
        pile = list(map(int,line.split())) 
        # While loop for the "Stop" function
        while start == 0 :
            if i == 1 :
                update_pile_a(pile, data_height, data_width_ratio, size)
            w.update()
        update_piles(pile, i)
        i += 1
    
    # Print last state of the piles when mod > 2
    pile = list(map(int,lines[i - 3].split())) 
    update_pile_a(pile, data_height, data_width_ratio, size)
    pile = list(map(int,lines[i - 2].split())) 
    update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
    # Pile is sorted : get ready for the reset
    start = 2
    Pause.set("Reset")


# Set the window
master = Tk()
title = "VISU PUSH_SWAP     \u00A9jfinet"
master.title(title)
w = Canvas(master, height=win_height, width=win_width, bg='black')
w.pack()

# Set the "Start/Stop/Reset button"
Pause = StringVar()
Pause.set("Start")
go = Button(master, width=20, textvariable = Pause, highlightbackground="black", command = Start) #command = start
go.place(x=500, y=25)

# Set the "Speed up" and "Slow down" buttons
slow_down_button = Button(master, width=10, text = "Speed Up", highlightbackground="black", command = Speed_up)
slow_down_button.place(x=485, y=50)
speed_up_button = Button(master, width=10, text = "Slow Down", highlightbackground="black", command = Slow_down)
speed_up_button.place(x=605, y=50)

# Launch the fcking algo to display the piles being sorted
create_piles(size)
display()

master.mainloop()
