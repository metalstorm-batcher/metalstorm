#include "proxysql.h"
#include "cpp.h"

Batcher_Info::Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher Info construct!");
}

Batcher_Info::~Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher Info destruct!");
}

void Batcher_Info::add_query (const Query_Info &query) {
	query_queue.emplace_back();
	Query_Info &copy_query = query_queue.back();
	copy_query.QueryLength = query.QueryLength;
	copy_query.MyComQueryCmd = MYSQL_COM_QUERY__UNINITIALIZED;
	//TODO WJF copy_query
}

Batcher::Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher construct!");
	foobar=0;
}

Batcher::~Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher destruct!");
	foobar=0;
}
