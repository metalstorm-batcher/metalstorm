#include "proxysql.h"
#include "cpp.h"

Query_Pack::Query_Pack () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Query_Pack construct!\n");
	is_tp_or_ap = 0;
	finshed = false;
}

Query_Pack::~Query_Pack () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Query_Pack destruct!\n");
	if (query_info) {
		delete query_info;
		query_info = NULL;
	}

	if (pkt.ptr) {
		l_free(pkt.size,pkt.ptr);
		pkt.ptr = NULL;
	}

	if (result_set) {
		delete result_set;
		result_set = NULL;
	}
}

// Query_Pack::Query_Pack(const Query_Pack && A) {
// 	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Query_Pack move construct!\n");
// 	query_info = A.query_info;
// 	pkt = A.pkt;
// 	is_tp_or_ap = A.is_tp_or_ap;
// }

Batcher_Info::Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info construct!\n");
}

Batcher_Info::~Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info destruct!\n");
}

void Batcher_Info::add_query (PtrSize_t *pkt) {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "add_query using pkt:%s\n", pkt->ptr + 5);
	Query_Pack *pack = new Query_Pack();

	// copy packet
	pack->pkt.ptr = l_alloc(pkt->size);
	pack->pkt.size = pkt->size;
	memcpy(pack->pkt.ptr, pkt->ptr, pkt->size);
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "copyed pkt:%s\n", pack->pkt.ptr + 5);

	// generate query info
	pack->query_info = new Query_Info();
	// pack->query_info->begin((unsigned char *)pack->pkt.ptr, pkt->size, true);

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
