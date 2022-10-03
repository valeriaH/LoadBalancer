#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include <string>
#include <queue>
#include <ostream>
#include <iostream>

#include "request.h"

/** 
 * Request Object:
 *    IP in
 *    IP out
 *    Time (Integer)
 **/

class request_queue
{

public:
    request_queue();

    std::queue<request> requests;

    void insert_request(request r);
    request pop_request();
    bool is_empty();

};

#endif // REQUEST_QUEUE_H