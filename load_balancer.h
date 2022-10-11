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