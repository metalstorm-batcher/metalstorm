#include "proxysql.h"
#include "cpp.h"

Batcher_Info::Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info construct!\n");
}

Batcher_Info::~Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info destruct!\n");
}

void Batcher_Info::add_query (PtrSize_t *pkt) {
  // get query info from pkt
  Query_Pack query_pack;
  query_pack.query = new Query_Info();
	query_pack.query->begin((unsigned char *)pkt->ptr, pkt->size, true);
  
  // judge is tp or ap of this query_info
  judge_process_kind(&query_pack);

	{
	  std::lock_guard<std::mutex> guard(queue_mutex);
    // add the query info to query_queue
	  query_queue.emplace_back(query_pack);
	}
}

void Batcher_Info::judge_process_kind(Query_Pack* query_pack) {
  // judge based query_info->stmt_info, query_info->stmt_meta
  query_pack->is_tp_or_ap = 0;
}

Batcher::Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher construct!\n");
	foobar=0;
}

Batcher::~Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher destruct!\n");
	foobar=0;
}
