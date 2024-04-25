#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>

using namespace std;

class RateLimiter
{
public:
    RateLimiter(int N, int T) : limit(N), interval(T)
    {
    }

    bool allow_request(int user_id)
    {
        auto now = std::chrono::steady_clock::now();
        auto it = request_counts.find(user_id);
        if (it == request_counts.end())
        {
            request_counts[user_id] = {1, now};
            return true;
        }
        else
        {
            auto &count = it->second.first;
            auto &last_request_time = it->second.second;
            auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(now - last_request_time).count();
            if (elapsed_time >= interval)
            {
                count = 1;
                last_request_time = now;
                return true;
            }
            else if (count < limit)
            {
                count++;
                last_request_time = now;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

private:
    int limit;
    int interval;
    std::unordered_map<int, std::pair<int, std::chrono::steady_clock::time_point>> request_counts;
};

int main()
{
    RateLimiter limiter(2, 60);
    int user_id = 123;
    cout << limiter.allow_request(user_id) << endl;
    cout << limiter.allow_request(user_id) << endl;
    cout << limiter.allow_request(user_id) << endl;
    return 0;
}