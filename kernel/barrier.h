struct barrier_type {
    int in_use;
    int arrived; // number of arrived threads
    int round;
    struct sleeplock lock;
    struct cond_t cv;
};