#ifndef __CLASS_METALSTORM_BATCHER
#define __CLASS_METALSTORM_BATCHER

#include <deque>

class Batcher_Info {
private:
	int foobar;
	deque<int> query_que;
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
};

#endif /* __CLASS_METALSTORM_BATCHER */
