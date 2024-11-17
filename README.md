#T2 Bluetooth speaker
T2 Bluetooth speaker uses AC6928 20-pin chip coded as AS19AP1S230-28B4

##BootLoader mode
To enter firmware mode use [Arduino BootLoader-izer](https://github.com/christian-kramer/JieLi-AC690X-Familiarization)
After connecting the Arduino and USB cable press reset button on the board and then disconnect the Arduino

##Flashing
For flashing use [jl-uboot-tool](https://github.com/kagaimiq/jl-uboot-tool)

###Backup
read 0x0 0x80000 Backup.bin

###Flash
write <address> <file>
write 0x0 Flash.bin

##Changes
Tone sounds replaced, tone volume set to minimum
Only BT and Radio mode

"+/-" buttons - only volume
Long press Play/Pause button - Prev
Light button - Next
Long press Light button - Mode change
You can change button behaviour in src\apps\task_manager\task_bt\task_bt_key.c src\apps\task_manager\task_fm\task_fm_key.c files

##Compile
Use [Code::Blocks](https://www.codeblocks.org/downloads/)