#include "net/EventLoop.h"
#include <assert.h>
#include "net/Channel.h"
#include "net/Poller.h"
NAMESPACE_ZL_NET_START

EventLoop::EventLoop() : looping_(false), quit_(false)
{

}

EventLoop::~EventLoop()
{

}

void EventLoop::loop()
{

}

void EventLoop::quit()
{

}

void EventLoop::wakeup()
{

}

void EventLoop::updateChannel(Channel* channel)
{
	//assert(channel->ownerLoop() == this);
	//assertInLoopThread();
	poller_->updateChannel(channel);
}

void EventLoop::removeChannel(Channel* channel)
{
	//assert(channel->ownerLoop() == this);
	//assertInLoopThread();
	if (eventHandling_)
	{
		assert(currentActiveChannel_ == channel ||
			std::find(activeChannels_.begin(), activeChannels_.end(), channel) == activeChannels_.end());
	}
	poller_->removeChannel(channel);
}

bool EventLoop::hasChannel(Channel* channel)
{
    return poller_->hasChannel(channel);
}

void EventLoop::runInLoop(const Functor& func)
{
	if (isInLoopThread())
	{
		func();
	}
	else
	{
		queueInLoop(func);
	}
}

void EventLoop::queueInLoop(const Functor& func)
{
	//zl::thread::MutexLocker lock(mutex_);

}

NAMESPACE_ZL_NET_END