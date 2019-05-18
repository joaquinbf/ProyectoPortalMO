#ifndef __PROTECTED_QUEUE_H__
#define __PROTECTED_QUEUE_H__

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class ProtectedQueue {
private:
    std::queue<T> queue;
    std::mutex m;
    std::condition_variable cond_var;

public:
    bool isEmpty();
};

template <typename T>
bool ProtectedQueue<T>::isEmpty() {
    std::lock_guard<std::mutex> lk(this->m);
    return this->queue.empty();
}



#endif
