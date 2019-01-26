#include "wrapper.h"
#define MAX_SIZE 1024

pthread_t thread;

int MQcreate (mqd_t * mq, char * name)
{
    /* Creates a mailslot with the specified name. Uses mq as reference pointer, so that you can 	reach the handle from anywhere */
    /* Should be able to handle a messages of any size */
    /* Should return 1 on success and 0 on fail*/
    return 0;
}

int MQconnect (mqd_t * mq, char * name)
{
    /* Connects to an existing mailslot for writing Uses mq as reference pointer, so that you can 	reach the handle from anywhere*/
    /* Should return 1 on success and 0 on fail*/
    return 0;
}

int MQread (mqd_t * mq, void ** refBuffer)
{
    /* Read a msg from a mailslot, return nr Uses mq as reference pointer, so that you can 		reach the handle from anywhere */
    /* of successful bytes read              */
    return 0;
}

int MQwrite (mqd_t * mq, void * sendBuffer)
{
    /* Write a msg to a mailslot, return nr Uses mq as reference pointer, so that you can 	     reach the handle from anywhere*/
    /* of successful bytes written         */
    return 0;
}

int MQclose(mqd_t * mq, char * name)
{
    /* close a mailslot, returning whatever the service call returns Uses mq as reference pointer, so that you can
    reach the handle from anywhere*/
    /* Should return 1 on success and 0 on fail*/
    return 0;
}

int threadCreate(void * functionCall, int threadParam)
{
	/* Creates a thread running threadFunc */
	/* Should return 1 on success and 0 on fail */
  int result = pthread_create(&thread, NULL, functionCall, (void *)&threadParam);

  if (result != 0) {
    return 0;
  } else {
    return 1;
  }
}
