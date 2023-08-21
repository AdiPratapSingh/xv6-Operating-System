struct buffer_elem {
   int x;
   int full;
   struct sleeplock lock;
   struct cond_t inserted;
   struct cond_t deleted;
};