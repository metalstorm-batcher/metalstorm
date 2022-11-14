#ifndef __CLASS_METALSTORM_BATCHER
#define __CLASS_METALSTORM_BATCHER

#include <deque>

class Batcher_Info {
private:
	deque<Query_Info> query_que;
public:
	Batcher_Info ();
	~Batcher_Info ();
};

class Batcher {
private:
	int foobar;
public:
	Batcher ();
	~Batcher ();
	add_query (const Query_Info &query);
};

#endif /* __CLASS_METALSTORM_BATCHER */
