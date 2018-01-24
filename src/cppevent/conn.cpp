#include "conn.h"
#include <event2/bufferevent.h>

NS_CPPEVENT_BEGIN

std::shared_ptr<Conn> Conn::connect(const char *addr)
{
	// TODO: 
	return nullptr;
}

Conn::Conn()
	: container_(nullptr)
	, event_loop_(nullptr)
	, bev_(nullptr)
	, handler_(nullptr)
	, shared_handler_(true)
{}
Conn::~Conn()
{
	if (bev_)
	{
		struct bufferevent *bev = (struct bufferevent*)bev_;
		bufferevent_free(bev);
	}
}

EventHandler* Conn::getHandler()
{
	return handler_;
}
EventLoop* Conn::getLoop()
{
	return event_loop_;
}

void Conn::setBev(void *bev)
{
	if (bev_ == nullptr)
	{
		bev_ = bev;
		byte_buf_in_.setEvbuf(bufferevent_get_input((struct bufferevent*)bev));
		byte_buf_out_.setEvbuf(bufferevent_get_output((struct bufferevent*)bev));
	}
}

NS_CPPEVENT_END