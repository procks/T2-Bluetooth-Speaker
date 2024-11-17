For flashing use this [jl-uboot-tool](https://github.com/kagaimiq/jl-uboot-tool)

Backup
read 0x0 0x80000 Backup.bin

Flash
write <address> <file>
write 0x0 Flash.bin
