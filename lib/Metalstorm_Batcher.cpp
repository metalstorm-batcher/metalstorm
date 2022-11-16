#include "proxysql.h"
#include "cpp.h"

Batcher_Info::Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info construct!\n");
}

Batcher_Info::~Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher Info destruct!\n");
}

void Batcher_Info::add_query (const Query_Info &query) {
	query_queue.emplace_back();
	Query_Info &copy_query = query_queue.back();
	copy_query.QueryLength = query.QueryLength;
	copy_query.MyComQueryCmd = MYSQL_COM_QUERY__UNINITIALIZED;
	//TODO WJF copy_query
}

Batcher::Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 5, "Batcher construct!\n");
	foobar=0;
}

Batcher::~Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher destruct!\n");
	foobar=0;
}
