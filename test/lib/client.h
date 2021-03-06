/* Setup a test dqlite client. */

#include "endpoint.h"

#ifndef TEST_CLIENT_H
#define TEST_CLIENT_H

#define FIXTURE_CLIENT                 \
	struct client client;          \
	struct test_endpoint endpoint; \
	int server

#define SETUP_CLIENT                                                    \
	{                                                               \
		int _rv;                                                \
		int _client;                                            \
		test_endpoint_setup(&f->endpoint, params);              \
		_rv = listen(f->endpoint.fd, 16);                       \
		munit_assert_int(_rv, ==, 0);                           \
		test_endpoint_pair(&f->endpoint, &f->server, &_client); \
		clientInit(&f->client, _client);                        \
	}

#define TEAR_DOWN_CLIENT         \
	clientClose(&f->client); \
	test_endpoint_tear_down(&f->endpoint)

#endif /* TEST_CLIENT_H */
