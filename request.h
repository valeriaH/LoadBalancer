#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/** 
 * Request Object:
 *    IP in
 *    IP out
 *    Time (Integer)
 **/

class request
{

public:
    request();

    std::string IP_in;
    std::string IP_out;
    int request_time;

    std::string generate_IP();
    int generate_time();
};

#endif // REQUEST_H