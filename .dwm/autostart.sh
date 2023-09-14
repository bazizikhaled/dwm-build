#!/bin/bash
dwmblocks & 
redshift -O 1600 &
brightnessctl s 50 &
xbanish &
picom &
feh --bg-fill ~/.dwm/wallpaper.jpg &
