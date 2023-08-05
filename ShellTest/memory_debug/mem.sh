#!/bin/sh

echo "应用内存占比排序，单位kB"
for pid in $(ls /proc | grep -E "^[0-9]+$"); do
  name=$(awk '/Name/ {print $2}' /proc/$pid/status 2>/dev/null)
  mem=$(awk '/VmRSS/ {print $2}' /proc/$pid/status 2>/dev/null)
  if [[ ! -z $name && ! -z $mem ]]; then
    echo "$name $mem"
  fi
done | ./busybox sort -k2 -rn
echo $blank

echo "var是内存，其中大于300k的文件大小"
cd /var
find . -type f -size +500k -exec ls -lh {} \;| awk '{print $9, $5}'
echo $blank

cat /proc/meminfo
echo $blank

free
echo $blank