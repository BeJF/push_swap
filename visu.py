from tkinter import *
import time

win_height = 900
win_width = 1200
pile_a = []
pile_b = []
i = 1
test = 2

def create_piles(nb_datas):
    
    while nb_datas != 0 :
        pile_a.append(w.create_rectangle(0, 0, 0, 0, fill="blue", outline="blue"))
        pile_b.append(w.create_rectangle(0, 0, 0, 0, fill="red", outline="red"))
        nb_datas -= 1

def update_pile_a(pile, data_height, data_width_ratio, size) :    

    obj = 1
    size_pile = len(pile)
    y0 = 50
    while (size_pile < size) :
        y1 = y0 + data_height
        w.coords(pile_a[obj - 1], 0, 0, 0, 0)
        obj += 1
        y0 = y1
        size_pile += 1
    for data in pile :
        y1 = y0 + data_height
        x0 = 50
        #print("data =", data)
        #print("obj =", obj)
        x1 = x0 + data * data_width_ratio
        w.coords(pile_a[obj - 1], x0, y0, x1, y1)
        y0 = y1
        obj += 1

def update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size) :    

    obj = 1
    size_pile = len(pile)
    y0 = 50
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

def Clic(event):
    """ Gestion de l'événement Clic gauche sur la zone graphique """
    # position du pointeur de la souris
    X = event.x
    Y = event.y
    # on dessine un carré
    r = 20
    w.create_rectangle(X-r, Y-r, X+r, Y+r, outline='black',fill='green')

def leftKey(event):
    print ("Left key pressed")

def rightKey(event):
    print ("Right key pressed")

def speed_up(event, speed) :
    speed += 1

def speed_down(event) :
    global speed
    key = event.char
    if key == 'a' :
        speed -= 2
    if key == 's' :
        speed += 2
    test = speed
    if speed <= 0 :
        test = 2

def speed_down2(event, speed) :
    print("clicked\n")
    print("speed \n", speed)
    speed -= 1

master = Tk()
master.title("TESTS")
w = Canvas(master, height=win_height, width=win_width, bg='black')
w.focus_set()
w.bind('<Left>', leftKey)
w.bind('<Right>', rightKey)
#w.bind('<Button-1>', speed_down)
w.bind('<Key>', speed_down)
w.pack()

lines = [line.rstrip('\n') for line in open('test0')]







w.bind("<w>", speed_up)
#w.bind(<'KP_Subtract'>, speed_down)



for line in lines :
    
    #transform the string into a list and convert the str into int
    pile = list(map(int,line.split())) 
    #print("speed here = \n", speed)
    if i == 1 :
        size = len(pile)
        create_piles(size)
        max = max(pile)
        data_height = (win_height - 100) / size #fct nbre data TODO
        data_width_ratio = (win_width - 200) / max / 2
        max_x1_a = data_width_ratio * max
    if i % test == 1 :
        update_pile_a(pile, data_height, data_width_ratio, size)
    if i % test == 0 :
        update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
        w.update()
    if speed < 0 :
        time.sleep((-speed)/50)
    i += 1

# Création d'un widget Canvas
master.mainloop()
