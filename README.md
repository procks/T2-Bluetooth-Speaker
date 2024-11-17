T2 Bluetooth speaker uses AC6928 20-pin chip coded as AS19AP1S230-28B4


To enter firmware mode use [Arduino BootLoader-izer](https://github.com/christian-kramer/JieLi-AC690X-Familiarization)
After connecting the Arduino and USB cable press reset button on the board and then disconnect the Arduino

For flashing use [jl-uboot-tool](https://github.com/kagaimiq/jl-uboot-tool)

Backup
read 0x0 0x80000 Backup.bin

Flash
write <address> <file>
write 0x0 Flash.bin
