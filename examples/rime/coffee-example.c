#include "cfs/cfs.h"
 #include "contiki.h"
 #include <stdio.h>

 //#define COFFEE_CONF_DYN_SIZE 256
 /**/
 PROCESS(coffee_test_process, "Coffee test process");
 AUTOSTART_PROCESSES(&coffee_test_process);
 PROCESS_THREAD(coffee_test_process, ev, data)
 /**/
 {
  PROCESS_BEGIN();
  /*        */
  /* step 1 */
  /*        */
  char message[32];
  char buf[100];
  char string[] = "SAAAAAAAo";
  int numero = 99;


  sprintf(message," %d %d %d %d.%02d %d",
                     numero, numero, numero, numero ,numero , numero);
  strcpy(buf,message);
  printf("step 1: %s\n", buf );
  /* End Step 1. We will add more code below this comment later */
  /*        */
  /* step 2 */
  /*        */
  /* writing to cfs */
  char *filename = "msg_file";
  int fd_write, fd_read;
  int n;
  //long file_size = 30;
  long file_size = 256;

  if ( cfs_coffee_reserve(filename, file_size)== 0)
  {
          printf("reserve exitoso!\n");
  }else
  {
      printf("reserve MALOOO!\n");
  }

  fd_write = cfs_open(filename, CFS_WRITE);
  if(fd_write != -1) {
    n = cfs_write(fd_write, message, sizeof(message));
    cfs_close(fd_write);
    printf("step 2: successfully written to cfs. wrote %i bytes\n", n);
  } else {
    printf("ERROR: could not write to memory in step 2.\n");
    }
  /*        */
  /* step 3 */
  /*        */
  /* reading from cfs */
  /*strcpy(buf,"empty string");
  fd_read = cfs_open(filename, CFS_READ);
  if(fd_read!=-1) {
    cfs_read(fd_read, buf, sizeof(message));
    printf("step 3: %s\n", buf);
    cfs_close(fd_read);
  } else {
    printf("ERROR: could not read from memory in step 3.\n");
}*/
  /*        */
  /* step 4 */
  /*        */
  /* adding more data to cfs */
  /*strcpy(buf,"empty string");
  strcpy(message,"#2.contiki is amazing!");
  fd_write = cfs_open(filename, CFS_WRITE | CFS_APPEND);
  if(fd_write != -1) {
    n = cfs_write(fd_write, message, sizeof(message));
    cfs_close(fd_write);
    printf("step 4: successfully appended data to cfs. wrote %i bytes  \n",n);
  } else {
    printf("ERROR: could not write to memory in step 4.\n");
}*/
  /*        */
  /* step 5 */
  /*        */
  /* seeking specific data from cfs */
 /* strcpy(buf,"empty string");
  fd_read = cfs_open(filename, CFS_READ);
  if(fd_read != -1) {
    cfs_read(fd_read, buf, sizeof(message));
    printf("step 5: #1 - %s\n", buf);
    cfs_seek(fd_read, sizeof(message), CFS_SEEK_SET);
    cfs_read(fd_read, buf, sizeof(message));
    printf("step 5: #2 - %s\n", buf);
    cfs_close(fd_read);
  } else {
    printf("ERROR: could not read from memory in step 5.\n");
}*/
  /*        */
  /* step 6 */
  /*        */
  /* remove the file from cfs */
  /*cfs_remove(filename);
  fd_read = cfs_open(filename, CFS_READ);
  if(fd_read == -1) {
    printf("Successfully removed file\n");
  } else {
    printf("ERROR: could read from memory in step 6.\n");
}*/
  /**/
  PROCESS_END();
 }
