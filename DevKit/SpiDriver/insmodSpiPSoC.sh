echo 0x3 > /sys/class/cplddrv/cpld/spi_route_reg
echo 0x1 > /sys/class/cplddrv/cpld/ext_serial_if_route_reg

insmod psoc_spimod.ko
insmod hotplug_psoc_spi_device.ko

mknod /dev/spi_dev c 64 0

/etc/init.d/qtdemo stop