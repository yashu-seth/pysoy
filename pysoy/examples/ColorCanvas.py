#!/usr/bin/env python3

from random import randint, random
from time import sleep
import soy
client = soy.Client()
tex = soy.textures.Texture()
tex.size = soy.atoms.Size((16,16))
tex.smooth = False
can = soy.widgets.Canvas(client.window, tex)

colors = (
    soy.atoms.Color('blue'),
    soy.atoms.Color('cyan'),
    soy.atoms.Color('green'),
    soy.atoms.Color('white'),
    soy.atoms.Color('yellow'),
    soy.atoms.Color('red'),
    soy.atoms.Color('pink'),
    soy.atoms.Color('grey')
)

for i in range(256):
    tex[i] = colors[randint(0,len(colors)-1)]

while True:
    colors[randint(0,len(colors)-1)].red += random()*2+1
    colors[randint(0,len(colors)-1)].green += random()*2+1
    colors[randint(0,len(colors)-1)].blue += random()*2+1
    tex[randint(0,255)] = colors[randint(0,len(colors)-1)]
    sleep(.1)
