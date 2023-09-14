static const Block blocks[] = {
    {" 🕒 ", "date '+%H:%M'", 60, 0},
    {" 📅 ", "date '+%Y-%m-%d'", 3600, 0},
    {" 🔋 ", "cat /sys/class/power_supply/BAT0/capacity", 60, 0},
    {" 🔋 ", "cat /sys/class/power_supply/BAT0/capacity", 10, 0},
};
