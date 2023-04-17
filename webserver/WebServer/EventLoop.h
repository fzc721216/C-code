// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#pragma once
#include <functional>
#include <memory>
#include <vector>
#include "Channel.h"
#include "Epoll.h"
#include "Util.h"
#include "base/CurrentThread.h"
#include "base/Logging.h"
#include "base/Thread.h"


#include <iostream>
using namespace std;

class EventLoop {
 public:
  typedef std::function<void()> Functor; ///typedef std::function<void()> CallBack;这是Channel.cpp里的
  EventLoop();
  ~EventLoop();
  void loop();
  void quit();
  void runInLoop(Functor&& cb);
  void queueInLoop(Functor&& cb);
  bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }
  void assertInLoopThread() { assert(isInLoopThread()); }
  void shutdown(shared_ptr<Channel> channel) { shutDownWR(channel->getFd()); }
  void removeFromPoller(shared_ptr<Channel> channel) {
    // shutDownWR(channel->getFd());
    poller_->epoll_del(channel);
  }
  void updatePoller(shared_ptr<Channel> channel, int timeout = 0) {
    poller_->epoll_mod(channel, timeout);
  }
  void addToPoller(shared_ptr<Channel> channel, int timeout = 0) {
    poller_->epoll_add(channel, timeout);
  }

 private:
  // 声明顺序 wakeupFd_ > pwakeupChannel_
  ///用于标志该loop是否运行起来
  bool looping_;
  ///epoll结构，事件循环的核心部分。其生命周期由EventLoop控制
  shared_ptr<Epoll> poller_;
  ///唤醒通道，用于线程间的通信，主要是通知唤醒一个阻塞于epoll_wait中的Eventloop
  int wakeupFd_;
  bool quit_;
  bool eventHandling_;
  mutable MutexLock mutex_;
  std::vector<Functor> pendingFunctors_;
  bool callingPendingFunctors_;
  const pid_t threadId_;
  ///通知通道，用于MainReactor唤醒SubReactor
  shared_ptr<Channel> pwakeupChannel_;

  void wakeup();
  void handleRead();
  void doPendingFunctors();
  void handleConn();
};
