#ifndef __CLASS_METALSTORM_BATCHER
#define __CLASS_METALSTORM_BATCHER

#include <deque>
#include <mutex>

#include "proxysql.h"
#include "cpp.h"

struct Query_Pack {
	Query_Info query;
	int is_tp_or_ap;
}
class Batcher_Info {
private:
	std::mutex queue_mutex;
	std::deque<Query_Pack> query_queue;
public:
	Batcher_Info ();
	~Batcher_Info ();
	void add_query (PtrSize_t *pkt);
  void judge_process_kind(Query_Info *query_info);
};

class Batcher {
private:
	int foobar;
public:
	Batcher ();
	~Batcher ();
};

#endif /* __CLASS_METALSTORM_BATCHER */
