#include "proxysql.h"


Batcher_Info::Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher Info construct!");
}

Batcher_Info::~Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher Info destruct!");
}

Batcher_Info::add_query (const Query_Info &query) {
	Query_Info copy_query();
	copy_query.QueryLength = query.QueryLength;
	MyComQueryCmd = MYSQL_COM_QUERY__UNINITIALIZED;

	this->query_queue
}

Batcher::Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher construct!");
	foobar=0;
}

Batcher::~Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher destruct!");
	foobar=0;
}
