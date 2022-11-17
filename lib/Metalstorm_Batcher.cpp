#include "proxysql.h"
#include "cpp.h"

Query_Pack::Query_Pack () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Query_Pack construct!\n");
}

Query_Pack::~Query_Pack () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Query_Pack destruct!\n");
	if (query) {
		delete query;
		query = NULL;
	}

	if (pkt) {
		delete pkt;
		pkt = NULL;
	}
}

Query_Pack::Query_Pack(const Query_Pack && A) {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Query_Pack move construct!\n");
	query = A.query;
	pkt = A.pkt;
	is_tp_or_ap = A.is_tp_or_ap;
}

Batcher_Info::Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info construct!\n");
}

Batcher_Info::~Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info destruct!\n");
}

void Batcher_Info::add_query (PtrSize_t *pkt) {
	Query_Pack *pack = new Query_Pack();

	// copy packet
	pack->pkt.ptr = l_alloc(pkt->size);
	pack->pkt.size = pkt.size;
	memcpy(copy_ptr, pkt->ptr, pkt->size);

	// generate query info
	pack->query = new Query_Info();
	pack->query->begin((unsigned char *)pack->pkt.ptr, pkt->size, true);

	// judge is tp or ap of this query_info
	judge_process_kind(pack);

	{
		std::lock_guard<std::mutex> guard(queue_mutex);
		query_queue.push_back(pack);
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
