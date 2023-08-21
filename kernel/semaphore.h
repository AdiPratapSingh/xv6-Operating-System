struct semaphore {
  int value;
  struct sleeplock lock;
  struct cond_t cv;
};