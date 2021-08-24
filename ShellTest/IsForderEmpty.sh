DIRECTORY=Downloads
if [ "`ls -A $DIRECTORY`" = "" ]; then
  echo "$DIRECTORY is indeed empty"
else
  echo "$DIRECTORY is not empty"
fi
