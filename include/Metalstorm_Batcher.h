#ifndef __CLASS_METALSTORM_BATCHER
#define __CLASS_METALSTORM_BATCHER

#include <deque>
#include <mutex>

#include "proxysql.h"
#include "cpp.h"

class Query_Pack {
public:
	Query_Info *query;
	int is_tp_or_ap;
	Query_Pack();
	~Query_Pack();
};

class Batcher_Info {
private:
	std::mutex queue_mutex;
	std::deque<Query_Pack> query_queue;
public:
	Batcher_Info ();
	~Batcher_Info ();
	void add_query (PtrSize_t *);
	void judge_process_kind(Query_Pack *);
};

class Batcher {
private:
	int foobar;
public:
	Batcher ();
	~Batcher ();
};

#endif /* __CLASS_METALSTORM_BATCHER */
