# fshm
Shared memory implemented with files;

mkdir /mnt/ramdisk #create folder

mountm  -t tmpfs -o size=1m tmpfs /mnt/ramdisk #put it on RAM
