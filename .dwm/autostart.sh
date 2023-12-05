#!/bin/bash
dwmblocks & 
redshift -x ; redshift -O 1600 &
brightnessctl s 150 &
xbanish &
picom &
feh --bg-fill ~/.dwm/wallpaper1.jpg &
xset r rate 300 50 &
setxkbmap -option caps:swapescape &
# iwctl station wlan0 disconnect &
# stalonetray &
# aw-qt &
# live-server ~/.writing --port=4040 &
