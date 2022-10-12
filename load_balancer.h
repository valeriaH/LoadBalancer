#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

/**
 * @brief Load Balancer:
 *      Queue of requests
 *      Keeps track of time
 */

#include <vector>
#include <queue>
#include <chrono>
#include "request_queue.h"
#include "server.h"


class load_balancer
{
public:

    /**
     * @brief Load Balancer Class
     * 
     * @param run_time User defined limit for how long the load balancer should run.
     * @param num_servers User defined number of servers to process requests.
     * @param initial_requests Initially instantiated requests when the request queue is first created.
     * @param clock Keeps track of the clock ticks for the load balancer system.
     * @param requests Request_queue object for all pending requests.
     * @param webservers All webservers that are free or in use.
     * @param free_webservers Queue of all free webservers that are waiting to take a new request.
     * @param handled_requests Vector holding all completed requests.
     * @param handled_servers Vector holding all servers that completed the corresponding request.
     * @param handled_times Timestamps corresponding to the handled requests.
     */
    load_balancer(int run_time, int num_servers, int initial_requests);

    int runtime;
    int num_servers;
    int initial_requests;
    int clock;

    request_queue requests;
    std::vector<server> webservers;
    std::queue<server> free_webservers;
    std::vector<request> handled_requests;
    std::vector<server> handled_servers;
    std::vector<std::string> handled_times; 

    std::vector<server> start_webservers();
    request_queue populate_requests();
    void initialize();
    void run();
    void assign_request();
    void server_sweep();
};
#endif // LOAD_BALANCER_H