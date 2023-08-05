#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
  key_t key;
  int msgid;
  struct msqid_ds buf;
  
  if((key == ftok(".", 'A')) == -1)
  {
    perror("ftok");
    exit(EXIT_FAILURE);
  }

  if((msgid = msgget(key, 0666|IPC_CREAT)) == -1)
  {
    perror("msgget");
    exit(EXIT_FAILURE);
  }

  msgctl(msgid, IPC_STAT, &buf);
  

  printf("the key : %d, \nthe uid : %d,\n", buf.msg_perm.__key, buf.msg_perm.uid);
  printf("the gid : %d, \nthe cuid : %d,\n", buf.msg_perm.gid, buf.msg_perm.cuid);
  printf("the cgid : %d, \nthe mode : %d,\n", buf.msg_perm.cgid, buf.msg_perm.mode);
  printf("the sequence : %d\n", buf.msg_perm.__seq);

  printf("the max bytes is : %d\n", buf.msg_qbytes);

  msgctl(msgid, IPC_RMID, (struct msqid_ds *)0);
  return 0;

}
