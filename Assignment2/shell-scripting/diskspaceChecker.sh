#!/bin/bash

# Get the available disk space on the C drive
# For WSL or Linux systems, we will check the /mnt/c path (for Windows C: drive)
disk_space=$(df -h /mnt/c | grep -v Filesystem | awk '{print $4}')

# Display the available space as MB
echo "The space available is $disk_space"

