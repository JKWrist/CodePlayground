count=`ls $*|wc -w`
if [ "$count" > "0" ];
then
 echo "file size $count"
else
 echo "empty!"
fi
