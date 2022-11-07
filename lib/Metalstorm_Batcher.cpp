#include "Metalstorm_Batcher.h"


Batcher_Info::Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher Info construct!");
	foobar=0;
}

Batcher_Info::~Batcher_Info () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher Info destruct!");
}

Batcher::Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher construct!");
	foobar=0;
}

Batcher::~Batcher () {
	proxy_debug(PROXY_DEBUG_METALSTORM, 0, "Batcher destruct!");
	foobar=0;
}
